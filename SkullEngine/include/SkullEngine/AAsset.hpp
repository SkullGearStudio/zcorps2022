#pragma once

#include <string>

namespace SkullEngine
{
    namespace Asset
    {
        class AAsset
        {
        public:
            AAsset(const std::string &);
            virtual ~AAsset(void) {};

            const std::string &Name();

        protected:
            std::string *_name;
        };
    }
}
