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
            IAsset &GetAsset(const std::string &) const;
            void    LoadAsset(IAsset &);
            void    UnloadAsset(const std::string &);
            void    Dump() const;

        private:
            asset_map   _assets;
        };
    }
}
