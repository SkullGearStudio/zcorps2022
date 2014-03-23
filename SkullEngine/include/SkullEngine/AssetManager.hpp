#pragma once

#include <map>

#include "SkullEngine\AAsset.hpp"

namespace SkullEngine
{
    namespace Asset
    {
        class AssetManager
        {
        private:
            typedef std::map<std::string, AAsset *> asset_map;

        public:
            AssetManager(void);
            ~AssetManager(void) {};
            AAsset &GetAsset(const std::string &) const;
            void    LoadAsset(AAsset &);
            void    UnloadAsset(const std::string &);

        private:
            asset_map   *_assets;
        };
    }
}
