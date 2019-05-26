#include"TcpSocket.hpp"

void Usage(std::string proc_){
  std::cout<<"Usage"<<proc_<<" local_port"<<std::endl;
}

int main(int argc,char*argv[]){
  if(argc!=2){
    Usage(argv[0]);
    exit(1);
  }
  short port = atoi(argv[1]);
  Server *server=new Server(port);
  server->InitSever();
  server->Run();
  delete server;
  return 0 ;
}
