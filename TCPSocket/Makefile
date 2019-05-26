.PHONY:all
all:Client Server 

Client:TcpClient.cc 
	g++ $^ -o $@ -std=c++11
Server:TcpServer.cc 
	g++ $^ -o $@ -std=c++11 -lpthread

.PHONY:clean
clean:
	rm -f Client Server
