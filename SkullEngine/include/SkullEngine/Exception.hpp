#pragma once

#include <Windows.h>
#include <exception>

#include "SkullEngine.hpp"

namespace SkullEngine
{
    struct SKULLENGINE_API Exception : public std::exception
    {
        // ATTR
        std::string *_msg;
        //METHODS
        Exception(const std::string &msg) : _msg(new std::string(msg)) {}
        ~Exception() throw () {}
        const char *what() const throw() { return _msg->c_str(); }
        void box() { ::MessageBoxA(NULL, _msg->c_str(), "Exception", MB_OK | MB_ICONERROR); delete _msg;}
    };
}
