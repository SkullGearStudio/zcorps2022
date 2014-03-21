#pragma once

#include <Windows.h>
#include <exception>

#include "SkullEngine.hpp"

namespace SkullEngine
{
    struct SKULLENGINE_API Exception : public std::exception
    {
        // ATTR
        const char *_msg;
        //METHODS
        Exception(const char *msg) : _msg(msg) {}
        ~Exception() throw () {}
        const char *what() const throw() { return _msg; }
        void box() { ::MessageBoxA(NULL, _msg, "Exception", MB_OK | MB_ICONERROR); }
    };
}
