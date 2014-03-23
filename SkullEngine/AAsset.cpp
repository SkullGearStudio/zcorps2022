#include "SkullEngine/AAsset.hpp"

namespace SkullEngine
{
    namespace Asset
    {
        AAsset::AAsset(const std::string &n) :
            _name(new std::string(n))
        {
        }

        const std::string &AAsset::Name()
        {
            return *_name;
        }
    }
}
