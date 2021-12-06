#include "InputTextBoxEvent.h"

void InputTextBoxEvent::addChar(char c, Text& input_text)
{
    std::string input_str = input_text.getString();
    if(c == 8)
    {
        if(input_str.empty())
        {
            return;
        }
        input_str.pop_back();
    }
    else
    {
        input_str += c;
    }
    input_text.setString(input_str);
}

bool InputTextBoxEvent::check(UIElementBody *body, RenderWindow *window)
{
    if(!is_enabled)
    {
        body->paintDisabled();
        check_result = false;
        return check_result;
    }
    if(isKeyPressed(Keyboard::Enter))
    {
        check_result = false;
        body->paintResting();
        return check_result;
    }
    sf::Vector2i pixelPos = getMousePos(window);
    sf::Vector2f worldPos = window->mapPixelToCoords(pixelPos);
    if(body->mouseHover(worldPos))
    {
        if(Mouse::isButtonPressed(Mouse::Left))
        {
            if(!check_result)
            {
                check_result = true;
                body->paintHoverToggled();
            }
        }
        else
        {
            if(check_result)
            {
                body->paintHoverToggled();
            }
            else
            {
                body->paintHover();
            }
        }
    }
    else
    {
        if(check_result)
        {
            body->paintToggled();
        }
        else
        {
            body->paintResting();
        }
        if(Mouse::isButtonPressed(Mouse::Left))
        {
            check_result = false;
            body->paintResting();
        }
    }
    return check_result;
}

bool InputTextBoxEvent::inputChar(UIElement* input_box, Text& input_text, char input_char)
{
    if(input_box->checkResult())
    {
        InputTextBoxEvent::addChar(input_char, input_text);
        if(input_text.getGlobalBounds().width > input_box->getBody()->getGlobalBounds().width)
        {
            InputTextBoxEvent::addChar(8, input_text);
        }
        return true;
    }
    return false;
}