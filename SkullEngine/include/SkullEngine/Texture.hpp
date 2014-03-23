#pragma once

#include "SkullEngine.hpp"
#include "AAsset.hpp"
#include "SFML\Graphics.hpp"

namespace SkullEngine
{
    namespace Asset
    {
        class SKULLENGINE_API Texture : AAsset
        {
        public:
            Texture(const std::string &name, const std::string &file) :
                AAsset(name)
            {
                if (!_tex.loadFromFile(file))
                {
                    system("PAUSE");
                    exit(-1);
                }
            }
            ~Texture() {};
            sf::Texture &res()
            {
                return _tex;
            }

        private:
            sf::Texture _tex;
        };
    }
}
