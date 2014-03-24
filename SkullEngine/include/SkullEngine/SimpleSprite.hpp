#pragma once

#include "SkullEngine\AAsset.hpp"
#include "SkullEngine\Texture.hpp"

namespace SkullEngine
{
    namespace Asset
    {
        class SimpleSprite : public AAsset
        {
        public:
            SimpleSprite(const std::string &, AAsset &);
            SimpleSprite(const std::string &, Texture &);
            ~SimpleSprite() {}

            sf::Sprite  &res();

        private:
            sf::Sprite _spr;
        };
    }
}
