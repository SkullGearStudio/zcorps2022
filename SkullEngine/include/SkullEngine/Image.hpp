#pragma once

#include "SkullEngine.hpp"
#include "AAsset.hpp"
#include "Texture.hpp"

namespace SkullEngine
{
    namespace Asset
    {
        class SKULLENGINE_API Image : public AAsset
        {
        public:
            Image(const std::string &, Texture &);
            ~Image() {}

            sf::Sprite  &res();

        private:
            sf::Sprite _spr;
        };
    }
}
