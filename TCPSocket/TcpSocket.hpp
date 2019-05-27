#include<iostream>
#include<string>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<cstring>
#include<signal.h>
#include<pthread.h>
#include<unordered_map>
class Sock{
  private:
    std::string ip;
    int local_socket;
    short port;
  public:
    Sock(const std::string &ip_,const int &port_)
      :ip(ip_)
      ,port(port_)
    {  }
    Sock(const short& port_):port(port_)
    {  }
    void SockCreate(){
      local_socket = socket(AF_INET,SOCK_STREAM,0);
      if(local_socket<0){
        std::cerr<<"socket error!"<<std::endl;
        exit(1);
      }
    }
    void Bind(){
      struct sockaddr_in local;
      local.sin_family = AF_INET;
      local.sin_port = htons(port);
      // local.sin_addr.s_addr = inet_addr(ip.c_str());
      local.sin_addr.s_addr =htonl(INADDR_ANY);
      if(bind(local_socket,(struct sockaddr*)&local,sizeof(local))<0){
        std::cerr<<"bind error!"<<std::endl;
        exit(2);
      }
    }
    void Listen(){
      if(listen(local_socket,5)<0){
        std::cerr<<"listen error"<<std::endl;
        exit(3);
      }
    }
    int Accept(){
      struct sockaddr_in peer;
      socklen_t len = sizeof(peer);
      int sockfd = accept(local_socket,(struct sockaddr*)&peer,&len);
      if(sockfd<0){
        std::cerr<<"accept error!"<<std::endl;//没拉到客人继续，不退出；
        return -1;
      }
      return sockfd;
    }
    ~Sock(){
      close(local_socket);
    }
    void Connect(){
      struct sockaddr_in peer;
      socklen_t len  = sizeof(peer);
      peer.sin_family = AF_INET;
      peer.sin_port = htons(port);
      peer.sin_addr.s_addr = inet_addr(ip.c_str());
      if(connect(local_socket,(struct sockaddr*)&peer,len)<0){
        std::cerr<<"connect error!"<<std::endl;
        exit(5);
      };
    }
    int Getlocal_socket(){
      return local_socket;
    }
};

class Server{
  private:
    Sock sock;
    pthread_t ptid;
    std::unordered_map<std::string,std::string> dict;
    class getinfo{
      public:
        int sock;
        Server* this_ptr;
        getinfo(int sock_,Server*this_):sock(sock_),this_ptr(this_)
        {  }
    };
  public:
    Server(const short port_)
      :sock(port_)
    {
      dict.insert(std::make_pair("hello","你好"));
      dict.insert(std::make_pair("bit","比特"));
      dict.insert(std::make_pair("LinTong","临潼"));
      dict.insert(std::make_pair("apple","苹果"));
      dict.insert(std::make_pair("sust","陕西科技大学"));
    }
    void InitSever(){
      signal(SIGCHLD,SIG_IGN);
      sock.SockCreate();
      sock.Bind();
      sock.Listen();
    }
    static void* Service(void* arg){
      pthread_detach(pthread_self());//先把自己分离了，就不用等它了
      getinfo* info = (getinfo*)arg;
      int sock = info->sock;
      char buf[1024];
      for(;;){
        ssize_t total=read(sock,buf,sizeof(buf)-1);//read返回0时代表对方关闭链接！
        if(total>0){
          buf[total]=0;
          std::cout<<buf<<std::endl;
          std::string key = buf;
          std::string val = info->this_ptr->dict[key];
          if(val.empty()){
            val="null";
          }
          write(sock,val.c_str(),val.size());
        }else if(total==0){
          std::cout<<"client is quit..."<<std::endl;
          break;
        }else{
          std::cerr<<"read error!"<<std::endl;
          break;
        }
      }
      close(sock);
      return NULL;
    }
    void Run(){
      while(1){
        int new_sock = sock.Accept();
        if(new_sock<0){
          continue;
        }
        getinfo info(new_sock,this);
        std::cout<<"Get A New Client"<<std::endl;
        pthread_create(&ptid,NULL,Service,(void*)&info);
        //close(new_sock);//父进程因为不使用new_sock,所以关掉new_sock，子进程完了后会自动退出;
      }
    }
    ~Server(){

    }
};

class Client{
  private:
    Sock sock;
  public:
    Client(const std::string& ip_,short port_)
      :sock(ip_,port_)
    {}
    void InitClient(){
      sock.SockCreate();
      sock.Connect();
    }
    void Run(){
      std::string message;
      std::string get;
      char buf[1024];
      for(;;){
        std::cout<<"Please Enter#";
        std::cin>>message;
        write(sock.Getlocal_socket(),message.c_str(),message.size());
        ssize_t total = read(sock.Getlocal_socket(),buf,sizeof(buf)-1);
        if(total>0){
          get.assign(buf,total);
          std::cout<<"Server Echo#"<<get<<std::endl;
        }
     }
    }
};
