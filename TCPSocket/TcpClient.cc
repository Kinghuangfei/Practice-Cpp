#include"TcpSocket.hpp"

void Usage(std::string proc_){
  std::cout<<"Usage"<<proc_<<"local_ip local_port"<<std::endl;
}

int main(int argc,char*argv[]){
  if(argc!=3){
    Usage(argv[0]);
    exit(1);
  }
  std::string ip = argv[1];
  short port = atoi(argv[2]);
  Client *client=new Client(ip,port);
  client->InitClient();
  client->Run();
  delete client;
  return 0 ;
}
