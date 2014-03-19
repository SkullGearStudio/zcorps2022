#include "AGameScreen.hpp"
#include "Exception.hpp"

namespace SkullEngine
{
    namespace GameScreen
    {
        AGameScreen::AGameScreen(ScreenManager::ScreenManager &scM, std::string &n) :
            _active(false),
            _popup(false),
            _layer(100),
            _name(n),
            _manager(scM)
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
            return _manager;
        }

        void AGameScreen::On()
        {
            try
            {
                if (IsActive())
                    throw Exception(std::string("Screen [" + Name() + "] is already active").c_str());
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
                    throw Exception(std::string("Screen [" + Name() + "] is already unactive").c_str());
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
                    throw Exception(std::string("Screen [" + Name() + "] is already on top").c_str());
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
                    throw Exception(std::string("Screen [" + Name() + "] is already on background").c_str());
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
