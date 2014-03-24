#pragma once

#include "SkullEngine\AAsset.hpp"
#include "SFML\Graphics.hpp"

namespace SkullEngine
{
    namespace Asset
    {
        class Image : public AAsset
        {
        public:
            Image(const std::string &, const std::string &);
            ~Image(void) {};

            sf::Image &res();
            const sf::Uint8 *px();

        private:
            sf::Image _img;
        };
    }
}
