#include "SkullEngine\Image.hpp"

namespace SkullEngine
{
    namespace Asset
    {
        Image::Image(const std::string &name, const std::string &file) :
            AAsset(name)
        {
            if (!_img.loadFromFile(file))
            {
                system("PAUSE");
                exit(-1);
            }
        }

        sf::Image &Image::res()
        {
            return _img;
        }
        const sf::Uint8 *Image::px()
        {
            return _img.getPixelsPtr();
        }
    }
}
