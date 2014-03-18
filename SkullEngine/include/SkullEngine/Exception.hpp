#pragma once

#include <exception>

namespace SkullEngine
{
    struct Exception : public std::exception
    {
        const char *msg;
        Exception(const char *msg_) : msg(msg_) {}
        ~Exception() throw () {}
        const char *what() const throw() { return msg; }
    };
}
