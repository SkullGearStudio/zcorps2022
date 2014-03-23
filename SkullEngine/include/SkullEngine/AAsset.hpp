#pragma once

#include <string>

#include "SkullEngine.hpp"

namespace SkullEngine
{
    namespace Asset
    {
        class SKULLENGINE_API AAsset
        {
        public:
            AAsset(const std::string &);
            virtual ~AAsset(void) {};

            const std::string &Name();

        private:
            std::string *_name;
        };
    }
}
