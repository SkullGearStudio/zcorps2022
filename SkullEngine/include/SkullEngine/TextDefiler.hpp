#pragma once

#include <string>

#include "Types.hpp"
#include "Assets.hpp"

namespace SkullEngine
{
    namespace GUI
    {
        class TextDefiler
        {
        public:
            TextDefiler() {};
            ~TextDefiler() {};

            void    AddLine(const std::string &);
            void    Draw(void);

        private:
            uint        _height;
            uint        _charSize;
            Asset::Font &_font;
            sf::Color   _color;
            const uint  _maxLines;
        };
    }
}
