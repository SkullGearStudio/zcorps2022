#pragma once

#include <SFML\Graphics\Text.hpp>

#include "SkullEngine\AAsset.hpp"
#include "SkullEngine\Types.hpp"
#include "SkullEngine\Font.hpp"

namespace SkullEngine
{
    namespace Asset
    {
        class Text : public AAsset
        {
        public:
            Text(const std::string &, const std::string &, uint, sf::Color, Font &);
            ~Text() {};

            sf::Text    &res();

        private:
            sf::Text _text;
        };
    }
}
