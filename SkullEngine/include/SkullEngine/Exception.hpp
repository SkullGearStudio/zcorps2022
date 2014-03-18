#pragma once

#include <Windows.h>
#include <exception>

namespace SkullEngine
{
    struct Exception : public std::exception
    {
        const char *_msg;
        Exception(const char *msg) : _msg(msg) {}
        ~Exception() throw () {}
        const char *what() const throw() { return _msg; }
        void box() { ::MessageBoxA(NULL, _msg, "Exception", MB_OK | MB_ICONERROR); }
    };
}
