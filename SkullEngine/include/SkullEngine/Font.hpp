#pragma once

#include <SFML\Graphics\Font.hpp>

#include "SkullEngine\AAsset.hpp"

namespace SkullEngine
{
    namespace Asset
    {
        class Font : public AAsset
        {
        public:
            Font(const std::string &, const std::string &);
            ~Font() {};

            sf::Font &res();

        private:
            sf::Font _font;
        };
    }
}
