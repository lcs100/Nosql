#pragma once

#include "Server.h"

class Server1: public Server {
    public:
        bool _Init() override;
        bool _RunLogic() override;
        void _Recycle() override;

};