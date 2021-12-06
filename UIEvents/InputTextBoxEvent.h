#pragma once
#include "../UIElement.h"


class InputTextBoxEvent : public UIEvent
{
public:
    static void addChar(char c, Text& input_text);
    static bool inputChar(UIElement* input_box, Text& input_text, char input_char);
    bool check(UIElementBody* body, RenderWindow* window) override;
};

