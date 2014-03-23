#pragma once

#include <map>

#include "SkullEngine.hpp"
#include "IAsset.hpp"

namespace SkullEngine
{
    namespace Asset
    {
        class SKULLENGINE_API AssetManager
        {
        private:
            typedef std::map<std::string, IAsset *> asset_map;

        public:
            AssetManager(void) {};
            ~AssetManager(void) {};
            IAsset &GetAsset(const std::string &) const; // TODO
            void    LoadAsset(IAsset &); // TODO
            void    UnloadAsset(const std::string &); // TODO

        private:
            asset_map   *_assets;
        };
    }
}
