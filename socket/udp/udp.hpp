//封装udpsocket类，实例化对象，向外提供简单socket接口
//1.创建套接字
//2.为套接字绑定地址信息
//3.发送数据
//4.接收数据
//5.关闭套接字

#include <iostream>
#include <string>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define CHECK_RET(q) if(q == false){return -1;}

class UdpSocket{
  private:
    int _sockfd;

  public:
    bool Socket(){
      _sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
      if(_sockfd < 0){
        std::cerr<<"socket error"<<std::endl;
        return false;
      }
      return true;
    }

    bool Bind(const std::string &ip, const uint16_t port){
      struct sockaddr_in addr;
      addr.sin_family = AF_INET;
      addr.sin_port = htons(port);
      addr.sin_addr.s_addr = inet_addr(ip.c_str());
      int ret;
      socklen_t len = sizeof(struct sockaddr_in);
      ret = bind(_sockfd, (struct sockaddr*)&addr, len);
      if(ret < 0){
        std::cerr<<"bind error"<<std::endl;
        return false;
      }
      return true;
    }

    bool Send(const std::string &data, const std::string &peer_ip, const uint16_t peer_port){
      struct sockaddr_in addr;
      addr.sin_family = AF_INET;
      addr.sin_port = htons(peer_port);
      addr.sin_addr.s_addr = inet_addr(peer_ip.c_str());
      socklen_t len = sizeof(struct sockaddr_in);
      int ret = sendto(_sockfd, &data[0], data.size(), 0, (struct sockaddr*)&addr, len);
      if(ret < 0){
        std::cerr<<"send error"<<std::endl;
        return false;
      }
      return true;
    }

    bool Recv(std::string &buf, std::string &peer_ip, uint16_t &peer_port){
      struct sockaddr_in peer_addr;
      socklen_t len = sizeof(struct sockaddr_in);
      char tmp[4096] = {0};
      int ret = recvfrom(_sockfd, tmp, 4096, 0, (struct sockaddr*)&peer_addr, &len);
      if(ret < 0){
        std::cerr<<"recv error"<<std::endl;
        return false;
      }
      peer_ip = inet_ntoa(peer_addr.sin_addr);
      peer_port = ntohs(peer_addr.sin_port);
      buf.assign(tmp, ret);
      return true;
    }

    void Close(){
      close(_sockfd);
    }
};
