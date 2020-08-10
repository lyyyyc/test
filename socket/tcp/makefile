all:cli srv
tcp_thread:tcp_thread.cpp 
	g++ $^ -o $@ -lpthread
tcp_process:tcp_process.cpp 
	g++ $^ -o $@
cli:cli.cc
	g++ $^ -o $@
srv:srv.cc 
	g++ $^ -o $@ -lpthread
udp_cli:udp_cli.cpp
	g++ $^ -o $@
udp_srv:udp_srv.cpp 
	g++ $^ -o $@
