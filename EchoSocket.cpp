#include "Log/Logger.h"

#include "EchoSocket.h"

PacketLength EchoSocket::_HandlePacket(const char* data, size_t bytes){
    if(bytes >= 3 && strncmp(data, "bye", 3) == 0){
        this->OnError();
        return 0;
    }

    SendPacket(data, bytes);

    return bytes;
}