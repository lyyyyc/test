//tcp客户端通信流程
//1.创建套接字
//2.为套接字绑定地址信息
//3.向服务端发起连接请求
//4。发送数据
//5.接收数据
//6.关闭套接字
//
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include "tcp.hpp"

void sigcb(int signo){
  std::cout<<"recv a signo SIGPIPE --- connect shutdown\n";
}

int main(int argc, char *argv[]){
  if(argc != 3){
    std::cerr<<"./cli ip port"<<std::endl;
    return -1;
  }
  signal(SIGPIPE, sigcb);
  TcpSocket sock;
  CHECK_RET(sock.Socket());
  CHECK_RET(sock.Connect(argv[1], argv[2]));
  while(1){
    std::string buf;
    std::cout<<"client say:";
    fflush(stdout);
    std::cin>>buf;
    sock.Send(buf);
    buf.clear();
    sock.Recv(buf);
    std::cout<<"server say:"<<buf<<std::endl;
  }
  sock.Close();
  return 0;
}
