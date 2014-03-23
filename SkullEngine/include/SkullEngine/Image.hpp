#pragma once

#include "SkullEngine\AAsset.hpp"
#include "SkullEngine\Texture.hpp"

namespace SkullEngine
{
    namespace Asset
    {
        class Image : public AAsset
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
