#pragma once
#include "../UIElement.h"


class InputTextBoxEvent : public UIEvent
{
public:
    static void addChar(char c, Text& input_text);

    bool check(UIElementBody* body, RenderWindow* window) override;
};

