#include<iostream>
#include<string>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

class Socket{
  public:
    Socket(std::string& ip,short port)
      :_ip(ip)
      ,_port(port)
    {}
    void SocketCreate(){
      _socketfd = socket(AF_INET,SOCK_DGRAM,0);//创建ipv4的udp协议socket
      if(_socketfd<0){
        std::cerr<<"socket error!"<<std::endl;
        exit(-1);
      }
    }
    void Bind(){
      sockaddr_in local;
      local.sin_addr.s_addr = inet_addr(_ip.c_str());
      local.sin_family = AF_INET;
      local.sin_port =htons(_port);
      socklen_t len = sizeof(local);
      if(bind(_socketfd,(sockaddr*)&local,len)<0){
        std::cout<<"bind error!"<<std::endl;
        exit(-2);
      }
    }
    void Recv(std::string& get,sockaddr_in& peer,socklen_t& len){
      char buf[1024] = {0};
      len = sizeof(sockaddr_in);
      ssize_t final_recv =  recvfrom(_socketfd,buf,1023,0,(sockaddr*)&peer,&len);
      if(final_recv>0){
        buf[final_recv] = 0;
        get = buf;
      }
    }
    void Send(std::string& send,sockaddr_in& peer,socklen_t len){
      sendto(_socketfd,send.c_str(),send.size(),0,(sockaddr*)&peer,len);
    }
    ~Socket(){
      close(_socketfd);
    }
  private:
    int _socketfd;
    std::string _ip;
    short _port;
};


class UdpServ{
  private:
    Socket sock;
  public:
    UdpServ(std::string ip,short port):sock(ip,port)
    {}
    void InitServer(){
      sock.SocketCreate();
      sock.Bind();
    }
    void start(){
      sockaddr_in peer;
      socklen_t len;
      std::string message;
      while(1){
        sock.Recv(message,peer,len);
        std::cout<<"["<<inet_ntoa(peer.sin_addr)<<":"<<ntohs(peer.sin_port)<<"]#"<<message<<std::endl;
        message+="back by server";
        sock.Send(message,peer,len);
        std::cout<<"serve echo success!"<<std::endl;

      }
    }
    ~UdpServ(){
    }
};
