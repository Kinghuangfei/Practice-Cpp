#include<iostream>
#include<string>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

void Usage(std::string proc){
  std::cout<<"Usage:"<<proc<<"ip port"<<std::endl;
}

int main(int argc,char* argv[])
{
  if(argc!=3){
    Usage(argv[0]);//0表示服务名称；
    exit(1);
  }
  int sock  = socket(AF_INET,SOCK_DGRAM,0);
  if(sock<0){
    std::cerr<<"socket error"<<std::endl;
    exit(-1);
  }
  sockaddr_in serv;
  serv.sin_addr.s_addr = inet_addr(argv[1]);
  serv.sin_port = htons(atoi(argv[2]));
  serv.sin_family = AF_INET;
  std::string Message;
  char buf[1024];
  while(1){
    socklen_t len = sizeof(serv);
    std::cout<<"Please Enter#"<<std::endl;
    getline(std::cin,Message);
    sendto(sock,Message.c_str(),Message.size(),0,(sockaddr*)&serv,len);
    ssize_t s = recvfrom(sock,buf,sizeof(buf)-1,0,(sockaddr*)&serv,&len);
    buf[s] = 0;
    std::cout<<"serv echo#"<<buf<<std::endl;
  }
  return 0;
}
