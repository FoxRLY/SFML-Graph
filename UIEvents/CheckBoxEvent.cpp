#include "CheckBoxEvent.h"

CheckBoxEvent::CheckBoxEvent()
{
    hold = false;
}

bool CheckBoxEvent::check(UIElementBody* body, RenderWindow* window)
{
    if(!is_enabled)
    {
        if(check_result)
        {
            body->paintToggledDisabled();
        }
        else
        {
            body->paintDisabled();
        }
        return check_result;
    }
    sf::Vector2i pixelPos = getMousePos(window);
    sf::Vector2f worldPos = window->mapPixelToCoords(pixelPos);
    if(body->mouseHover(worldPos))
    {
        if(Mouse::isButtonPressed(Mouse::Left))
        {
            if(!hold)
            {
                check_result = !check_result;
                if(check_result)
                {
                    body->paintHoverToggled();
                }
                else
                {
                    body->paintHover();
                }
                hold = true;
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
            hold = false;
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
    }
    return check_result;
}

