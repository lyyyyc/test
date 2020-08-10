//封装一个tcpsocket类，向外提供简单的套接字接口
//1.创建套接字
//2.为套接字绑定地址信息
//3.开始监听
//4.向服务端发起连接请求
//5.服务端获取新建连接
//6.发送数据
//7.接收数据
//8.关闭套接字

#include <iostream>
#include <sstream>
#include <unistd.h>
#include <string>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define CHECK_RET(q) if((q)==false){return -1;}

class TcpSocket
{
  private:
    int _sockfd;
  public:
    void SetFd(int fd){
      _sockfd = fd;
    }

    int GetFd(){
      return _sockfd;
    }

    bool Socket(){
      _sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
      if(_sockfd < 0){
        std::cerr<<"socket error"<<std::endl;
        return false;
      }
      return true;
    }

    int str2int(const std::string &str){
      int num;
      std::stringstream tmp;
      tmp << str;
      tmp >> num;
      return num;
    }

    bool Bind(const std::string &ip, const std::string &port){
      struct sockaddr_in addr;
      addr.sin_family = AF_INET;
      addr.sin_port = htons(str2int(port));
      addr.sin_addr.s_addr = inet_addr(ip.c_str());
      socklen_t len = sizeof(struct sockaddr_in);
      int ret = bind(_sockfd, (struct sockaddr*)&addr,len);
      if(ret < 0){
        std::cerr<<"bind error"<<std::endl;
        return false;
      }
      return true;
    }

    bool Listen(const int backlog = 5){
      int ret = listen(_sockfd, backlog);
      if(ret < 0){                                                                
        std::cerr<<"listen error"<<std::endl;                                       
        return false;                                                             
      }                                                                           
      return true;                                                                
    }

    bool Connect(const std::string &srv_ip, const std::string &srv_port){
      struct sockaddr_in addr;
      addr.sin_family = AF_INET;
      addr.sin_port = htons(str2int(srv_port));
      addr.sin_addr.s_addr = inet_addr(srv_ip.c_str());
      socklen_t len = sizeof(struct sockaddr_in);
      int ret = connect(_sockfd, (struct sockaddr*)&addr, len);
      if(ret < 0){
        std::cerr<<"connect error"<<std::endl;
        return false;
      }
      return true;
    }

    bool Accept(TcpSocket &clisock, std::string *ip = NULL, uint16_t *port = NULL){
      struct sockaddr_in cliaddr;
      socklen_t len = sizeof(struct sockaddr_in);
      int newfd = accept(_sockfd, (sockaddr*)&cliaddr, &len);
      if(newfd < 0){
        std::cerr<<"accept error"<<std::endl;
        return false;
      }
      clisock.SetFd(newfd);
      if(ip != NULL){
        *ip = inet_ntoa(cliaddr.sin_addr);
      }
      if(port != NULL){
        *port = ntohs(cliaddr.sin_port);
      }
      return true;
    }

    bool Send(std::string &data){
      int ret = send(_sockfd, &data[0],data.size(),0);
      if(ret < 0){
        std::cerr<<"send error"<<std::endl;
        return false;
      }
      return true;
    }

    bool Recv(std::string &buf){
      char tmp[4096];
      int ret = recv(_sockfd, tmp, 4096, 0);
      if(ret < 0){
        std::cerr<<"recv error"<<std::endl;
        return false;
      }
      else if(ret == 0){
        std::cerr<<"connect shutdown"<<std::endl;
        return false;
      }
      buf.assign(tmp, ret);
      return true;
    }

    void Close(){
      close(_sockfd);
    }
};
