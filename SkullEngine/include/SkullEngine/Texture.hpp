#pragma once

#include <SFML\Graphics.hpp>

#include "SkullEngine\AAsset.hpp"

namespace SkullEngine
{
    namespace Asset
    {
        class Texture : public AAsset
        {
        public:
            Texture(const std::string &, const std::string &, bool = false);
            ~Texture(void) {};

            sf::Texture &res();

        private:
            sf::Texture _tex;
        };
    }
}
