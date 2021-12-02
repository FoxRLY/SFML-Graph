#pragma once
#include "../UIElement.h"

class CheckBoxEvent: public UIEvent
{
private:
    bool hold;
public:
    CheckBoxEvent();

    bool check(UIElementBody* body, RenderWindow* window) override;
};

