// TODO conditional define

class TCPClient {
    
    public:
        TCPClient();
        ~TCPClient();

        // head gets request from interface
        // interface might block
        // interface might not care and want a callback
        // head 

        int send(int port, char *msg, char *resp);
};
