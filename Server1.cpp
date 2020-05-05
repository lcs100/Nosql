#include <iostream>

#include "Log/Logger.h"
#include "Socket.h"

#include "Server1.h"

bool Server1::_Init(){
    g_log = LogManager::Instance().CreateLog(logALL, logConsole, "");

    SocketAddr addr("127.0.0.1", 9800);
    if(!Server::TCPBind(addr, 0)){
        ERR << "can not bind socket on port " << addr.GetPort();
        return false;
    }

    return true;
}

bool Server1::_RunLogic(){
    static int c = 0;
    if( ++c % 20000 == 0)
        DBG << "Server1::_RunLogic";
    
    return Server::_RunLogic();
}

bool Server1::_Recycle(){
    std::cout << "Server1::_Recycle: server is exiting.. BYE BYE\n";
}

int main(){
    Server1 svr;

    svr.MainLoop(false);

    return 0;
}
