#include "AScreenManager.hpp"

namespace SkullEngine
{
    namespace GameScreen
    {
        AScreenManager::AScreenManager(ScreenManager::ScreenManager &scM, std::string &n) :
            _active(false),
            _popup(false),
            _layer(100),
            _name(n),
            _screenManager(scM)
        {
        }

        bool AScreenManager::IsActive() const
        {
            return _active;
        }
        bool AScreenManager::IsPopup() const
        {
            return _popup;
        }
        ushort AScreenManager::Layer() const
        {
            return _layer;
        }
        const std::string &AScreenManager::Name() const
        {
            return _name;
        }
        const ScreenManager::ScreenManager &AScreenManager::SCM() const
        {
            return _screenManager;
        }

        void AScreenManager::On()
        {
            _active = true;
        }
        void AScreenManager::Off()
        {
            _active = false;
        }
        void AScreenManager::PopUp()
        {
            _popup = true;
        }
        void AScreenManager::PopDown()
        {
            _popup = false;
        }
        void AScreenManager::LayerUp()
        {
            ++_layer;
        }
        void AScreenManager::LayerDown()
        {
            --_layer;
        }
    }
}
