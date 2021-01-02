#ifndef I_LED_CONTROLLER_H
#define I_LED_CONTROLLER_H

#include <Arduino.h>

class ILedController {
    public:    
        // pure virtual (abstract) method definitions
        virtual void init() = 0;
        virtual void fadeIn(boolean isForward) = 0;
        virtual void fadeOut(boolean isForward) = 0;
        virtual void flash(boolean isForward) = 0;
        virtual void stop() = 0;
        virtual void startSequence(byte red, byte green, byte blue, int speedDelay) = 0;
        virtual void loop(int* new_forward, int* old_forward, int* new_backward, int* old_backward) = 0;

};

class LedControllerFactory {
    public:
        static LedControllerFactory* getInstance();
        ILedController* createLedController();

    private:
        LedControllerFactory();    
        static LedControllerFactory *instance;    
};
#endif

