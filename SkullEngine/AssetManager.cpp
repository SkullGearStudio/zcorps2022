#include "AssetManager.hpp"

namespace SkullEngine
{
    namespace Asset
    {
        AssetManager::AssetManager() :
            _assets(new asset_map)
        {
        }
        AAsset  &AssetManager::GetAsset(const std::string &name) const
        {
            asset_map::iterator it = _assets->find(name);

            if (it != _assets->end())
                return *(it->second);
        }
        void    AssetManager::LoadAsset(AAsset &as)
        {
            (*_assets)[as.Name()] = &as;
        }
        void    AssetManager::UnloadAsset(const std::string &name)
        {
            asset_map::iterator it = _assets->find(name);

            if (it != _assets->end())
                _assets->erase(it);
        }
    }
}
