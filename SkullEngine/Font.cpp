#include "SkullEngine\Font.hpp"

namespace SkullEngine
{
    namespace Asset
    {
        Font::Font(const std::string &name, const std::string &file) :
            AAsset(name)
        {
            if (!_font.loadFromFile(file))
            {
                system("PAUSE");
                exit(-1);
            }
        }

        sf::Font    &Font::res()
        {
            return _font;
        }
    }
}
