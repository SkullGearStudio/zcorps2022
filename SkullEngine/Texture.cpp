#include "SkullEngine/Texture.hpp"

namespace SkullEngine
{
    namespace Asset
    {
        Texture::Texture(const std::string &name, const std::string &file, bool repeated) :
            AAsset(name)
        {
            if (!_tex.loadFromFile(file))
            {
                system("PAUSE");
                exit(-1);
            }
            _tex.setRepeated(repeated);
        }
        sf::Texture &Texture::res()
        {
            return _tex;
        }
    }
}
