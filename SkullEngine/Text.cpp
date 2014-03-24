#include "SkullEngine\Text.hpp"

namespace SkullEngine
{
    namespace Asset
    {
        Text::Text(const std::string &name, const std::string &text, uint size, sf::Color color, Font &font) :
            AAsset(name)
        {
            _text.setFont(font.res());
            _text.setString(text);
            _text.setColor(color);
            _text.setCharacterSize(size);
        }

        sf::Text    &Text::res()
        {
            return _text;
        }
    }
}
