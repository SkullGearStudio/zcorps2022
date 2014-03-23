#pragma once

#include <map>

#include "SkullEngine.hpp"
#include "AAsset.hpp"

namespace SkullEngine
{
    namespace Asset
    {
        class SKULLENGINE_API AssetManager
        {
        private:
            typedef std::map<std::string, AAsset *> asset_map;

        public:
            AssetManager(void) {};
            ~AssetManager(void) {};
            AAsset &GetAsset(const std::string &) const; // TODO
            void    LoadAsset(AAsset &); // TODO
            void    UnloadAsset(const std::string &); // TODO

        private:
            asset_map   *_assets;
        };
    }
}
