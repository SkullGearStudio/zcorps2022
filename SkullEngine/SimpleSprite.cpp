#include "SkullEngine/SimpleSprite.hpp"

namespace SkullEngine
{
    namespace Asset
    {
        SimpleSprite::SimpleSprite(const std::string &name, Texture &texture) :
            AAsset(name)
        {
            _spr.setTexture(texture.res());
        }
        sf::Sprite &SimpleSprite::res()
        {
            return _spr;
        }
    }
}

