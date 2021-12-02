#pragma once
#include "../UIElement.h"

class ButtonEvent : public UIEvent
{
private:
    bool hold;
public:
    ButtonEvent()
    {
        hold = false;
    }
    bool check(UIElementBody* body, RenderWindow* window) override;
};