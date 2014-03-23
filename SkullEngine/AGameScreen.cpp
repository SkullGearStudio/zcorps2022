#include "SkullEngine/AGameScreen.hpp"
#include "SkullEngine/Exception.hpp"

namespace SkullEngine
{
    namespace GameScreen
    {
        AGameScreen::AGameScreen(ScreenManager::ScreenManager &m, const std::string &n) :
            _active(false),
            _popup(false),
            _layer(100),
            _name(new std::string(n)),
            _manager(m)
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
            return *_name;
        }
        ScreenManager::ScreenManager &AGameScreen::Manager() const
        {
            return _manager;
        }

        void AGameScreen::On()
        {
            try
            {
                if (IsActive())
                    throw Exception("Screen [" + Name() + "] is already active");
                _active = true;
            } catch (Exception ex)
            {
                ex.box();
                ::exit(-1);
            }
        }
        void AGameScreen::Off()
        {
            try
            {
                if (!IsActive())
                    throw Exception("Screen [" + Name() + "] is already unactive");
                _active = false;
            } catch (Exception ex)
            {
                ex.box();
                ::exit(-1);
            }
        }
        void AGameScreen::PopUp()
        {
            try
            {
                if (IsPopup())
                    throw Exception("Screen [" + Name() + "] is already on top");
                _popup = true;
            } catch (Exception ex)
            {
                ex.box();
                ::exit(-1);
            }
        }
        void AGameScreen::PopDown()
        {
            try
            {
                if (!IsPopup())
                    throw Exception("Screen [" + Name() + "] is already on background");
                _popup = false;
            } catch (Exception ex)
            {
                ex.box();
                ::exit(-1);
            }
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
