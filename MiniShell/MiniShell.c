#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<ctype.h>

char buff[1024] = {0};
int argc = 0;
char *argv[32];

int getInput(){
  memset(buff,0x00,1024);//每次调用都要清空一次
  printf("[minishell@coolsuperman]$");
  fflush(stdout);
  if(scanf("%[^\n]%*c",buff)!=1){//如果只是\n scanf阻塞
    getchar();
    return -1;
  }
  return 0;
}

int  AnalysisData(){
  argc = 0;
  char* go = buff;
  while(*go!='\0'){
    if(!isspace(*go)){
      argv[argc] = go;
      argc++;
      while((*go!='\0')&&(!isspace(*go))){
        go++;
      }
      *go = '\0';
    }
      go++;
  }
  argv[argc]=NULL;
  return 0;
}

int main(){
  while(1){
    if(getInput()<0)
      continue;
    AnalysisData();
    if(!strcmp(argv[0],"cd")){
      chdir(argv[1]);
      continue;
    }
    int pid = fork();
    if(pid<0){
      perror("fork error");
      return -1;
    }else if(pid==0){
      int i = 0;
      for(;i<argc;i++){
        if(!strcmp(argv[i],">")){
          int fd = open(argv[i+1],O_WRONLY|O_CREAT|O_TRUNC);//只写，没有创新，清空再写入
          dup2(fd,1);
          argv[i] = NULL;
        }else if(!strcmp(argv[i],">>")){
          int fd = open(argv[i+1],O_WRONLY|O_CREAT|O_APPEND);//只写，没有创新，在末尾续；
          dup2(fd,1);
          argv[i] = NULL;
        }
      }
      execvp(argv[0],argv);//在PATH下找命令；
      perror("execvp error");
      exit(-1);

    }
    wait(NULL); //阻塞式等待，防止僵尸进程；
    }
  return 0;
}
