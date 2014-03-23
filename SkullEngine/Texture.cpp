#include "Texture.hpp"

namespace SkullEngine
{
    namespace Asset
    {
        Texture::Texture(const std::string &name, const std::string &file) :
            AAsset(name)
        {
            if (!_tex.loadFromFile(file))
            {
                system("PAUSE");
                exit(-1);
            }
        }
        sf::Texture &Texture::res()
        {
            return _tex;
        }
    }
}
