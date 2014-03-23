#pragma once

#include "SkullEngine.hpp"
#include "AAsset.hpp"
#include "SFML\Graphics.hpp"

namespace SkullEngine
{
    namespace Asset
    {
        class SKULLENGINE_API Texture : public AAsset
        {
        public:
            Texture(const std::string &, const std::string &);
            ~Texture(void) {};

            sf::Texture &res();

        private:
            sf::Texture _tex;
        };
    }
}
