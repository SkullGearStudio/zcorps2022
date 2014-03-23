#include "Image.hpp"

namespace SkullEngine
{
    namespace Asset
    {
        Image::Image(const std::string &name, Texture &texture) :
            AAsset(name)
        {
            _spr.setTexture(texture.res());
        }
        sf::Sprite &Image::res()
        {
            return _spr;
        }
    }
}

