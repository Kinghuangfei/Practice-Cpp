//UDP回显服务端程序：1.创建socket；2.为socket绑定地址信息3.接收发送数据4.关闭socket
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<netinet/in.h>//sockaddr_in的定义所在
#include<arpa/inet.h>

union BorS{
  int i;
  char a;
}test;


int main(){
  int socketfd,ret;
  struct sockaddr_in addr;
  socketfd = socket(AF_INET,SOCK_DGRAM,0);
  if(socketfd<0){
    perror("socket creat error!!");
    return -1;
  }
  addr.sin_family=AF_INET;//协议族
  addr.sin_port = htons(1998);
  addr.sin_addr.s_addr =inet_addr("192.168.72.142");//将一个字符串IP地址转换成网络字节序的0x类型；INADDR_ANAY--给0的话表示电脑所有网卡（ip地址）的1998端口接收数据；INADDR_BROADCAST--0xffffffff--255:255:255:255广播地址
  //addr.sin_addr.s_addr = htonl(0x314a5824);//将主机字节序转化为网络字节序
  int len = sizeof(struct sockaddr_in);
  ret = bind(socketfd,(struct sockaddr*)&addr,(socklen_t)len);
  if(ret<0){
    perror("bind");
    return -1;
  }
  while(1){
    char buffer[1024] = {0};
    struct sockaddr_in peer_addr;
    ssize_t rlen=recvfrom(socketfd,buffer,1023,0,(struct sockaddr*)&peer_addr,(socklen_t*)&len);//接受多少返回多少
    printf("recv buff:[%ld-%s],from:[%s:%d]",rlen,buffer,inet_ntoa(peer_addr.sin_addr),ntohs(peer_addr.sin_port));//inet_ntoa//全局空间会覆盖
    sendto(socketfd,buffer,strlen(buffer),0,(struct sockaddr*)&peer_addr,(socklen_t)len);
    sleep(1);
  }
  close(socketfd);
  return 0;
}
