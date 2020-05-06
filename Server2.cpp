#include <iostream>

#include "Log/Logger.h"
#include "EchoSocket.h"

#include "Server2.h"

const int kEchoTag = 1;

bool Server2::_Init(){
    g_log = LogManager::Instance().CreateLog(logALL, logConsole, "");

    SocketAddr addr("127.0.0.1", 9800);
    if(!Server::TCPBind(addr, kEchoTag)){
        ERR << "can not bind socket on port " << addr.GetPort();
        return false;
    }

    return true;
}

bool Server2::_RunLogic(){
    static int c = 0;

    if(++c % 50000 == 0)
        DBG << "Server2::_RunLogic";

    return Server::_RunLogic();    
}

void Server2::_Recycle()
{
    std::cout << "Server2::_Recycle: server is exiting.. BYE BYE\n";
}

std::shared_ptr<StreamSocket> Server2::_OnNewConnection(int fd, int tag){
    assert(tag == kEchoTag);

    SocketAddr peer;
    Socket::GetPeerAddr(fd, peer);

    auto socket = std::make_shared<EchoSocket>();
    socket->Init(fd, peer);
    return socket;
}

int main(){
    Server2 svr;

    svr.MainLoop(false);

    return 0;
}