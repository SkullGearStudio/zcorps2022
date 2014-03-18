#include "AGameScreen.hpp"

namespace SkullEngine
{
    namespace GameScreen
    {
        AGameScreen::AGameScreen(ScreenManager::ScreenManager &scM, std::string &n) :
            _active(false),
            _popup(false),
            _layer(100),
            _name(n),
            _screenManager(scM)
        {
        }

        bool AGameScreen::IsActive() const
        {
            return _active;
        }
        bool AGameScreen::IsPopup() const
        {
            return _popup;
        }
        ushort AGameScreen::Layer() const
        {
            return _layer;
        }
        const std::string &AGameScreen::Name() const
        {
            return _name;
        }
        const ScreenManager::ScreenManager &AGameScreen::SCM() const
        {
            return _screenManager;
        }

        void AGameScreen::On()
        {
            _active = true;
        }
        void AGameScreen::Off()
        {
            _active = false;
        }
        void AGameScreen::PopUp()
        {
            _popup = true;
        }
        void AGameScreen::PopDown()
        {
            _popup = false;
        }
        void AGameScreen::LayerUp()
        {
            ++_layer;
        }
        void AGameScreen::LayerDown()
        {
            --_layer;
        }
    }
}
