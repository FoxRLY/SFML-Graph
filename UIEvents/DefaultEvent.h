#pragma once
#include "../UIElement.h"

class DefaultEvent : public UIEvent
{
public:
    DefaultEvent()
    {
        is_enabled = false;
        check_result = false;
    }
    bool check(UIElementBody* body, RenderWindow* window) override;
};
