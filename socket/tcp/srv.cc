//tcp服务段通信流程
//1.创建套接字
//2.为套接字绑定地址信息
//3.开始监听
//4.获取已完成连接的socket
//5.通过获取的新建socket与客户端进行通信-接收数据
//6.发送数据
//7.关闭套接字
//
#include <stdio.h>
#include "tcp.hpp"
#include <pthread.h>

void *thr_start(void *arg){
  TcpSocket *clisock = (TcpSocket*)arg;
  while(1){
    std::string buf;
    clisock->Recv(buf);
    std::cout<<"client say:"<<buf<<std::endl;
    buf.clear();
    std::cout<<"server say:";
    fflush(stdout);
    std::cin>>buf;
    clisock->Send(buf);
  }
  clisock->Close();
  delete clisock;
  return NULL;
}

int main(int argc, char *argv[]){
  if(argc != 3){
    std::cerr<<"./srv ip port"<<std::endl;
    return -1;
  }
  TcpSocket lst_sock;
  CHECK_RET(lst_sock.Socket());
  CHECK_RET(lst_sock.Bind(argv[1], argv[2]));
  CHECK_RET(lst_sock.Listen());

  while(1){
    TcpSocket *clisock = new TcpSocket();
    bool ret = lst_sock.Accept(*clisock);
    if(ret == false){
      continue;
    }
    pthread_t tid;
    pthread_create(&tid, NULL, thr_start, (void*)clisock);
    pthread_detach(tid);
  }
  lst_sock.Close();
  return 0;
}
