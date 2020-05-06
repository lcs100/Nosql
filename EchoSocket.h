#pragma once

#include "StreamSocket.h"

class EchoSocket: public StreamSocket {
    private:
        PacketLength _HandlePacket(const char* msg, std::size_t len) override;
};