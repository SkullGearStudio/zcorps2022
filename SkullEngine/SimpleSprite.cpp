#include "SkullEngine/SimpleSprite.hpp"

namespace SkullEngine
{
    namespace Asset
    {
        SimpleSprite::SimpleSprite(const std::string &name, AAsset &texture) :
            AAsset(name)
        {
            Texture &tex = dynamic_cast<Texture &>(texture);
            _spr.setTexture(tex.res());
        }
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

