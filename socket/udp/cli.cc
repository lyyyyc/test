#include "udp.hpp"
#include <sstream>

int main(int argc, char *argv[]){
  if(argc != 3){
    std::cerr<<"./udp_cli ip port"<<std::endl;
    return -1;
  }
  uint16_t port;
  std::string ip = argv[1];
  std::stringstream tmp;
  tmp << argv[2];
  tmp >> port;

  UdpSocket sock;
  CHECK_RET(sock.Socket());
  while(1){
    std::string buf;
    std::cin>>buf;
    sock.Send(buf, ip, port);
    buf.clear();
    sock.Recv(buf, ip, port);
    std::cout<<"server say:"<<buf<<std::endl;
  }
  sock.Close();
  return 0;
}
