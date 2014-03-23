#pragma once

#include "SkullEngine.hpp"
#include "AAsset.hpp"
#include "Texture.hpp"

namespace SkullEngine
{
    namespace Asset
    {
        class Image : AAsset
        {
        public:
            Image(const std::string &name, Texture &texture) :
                AAsset(name)
            {
                _spr.setTexture(texture.res());
            }
            ~Image() {};
            sf::Sprite &res()
            {
                return _spr;
            }

        private:
            sf::Sprite _spr;
        };
    }
}
