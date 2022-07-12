// conditional define

class TCPServer {

    public:
	TCPServer(int port);
	~TCPServer();
	void run();
    void stop();

    private:
	int sockfd;
    int running;    

	void echoHandler(int connfd);

};
