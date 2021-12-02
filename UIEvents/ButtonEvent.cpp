#include "ButtonEvent.h"

bool ButtonEvent::check(UIElementBody* body, RenderWindow* window)
{
    if(!is_enabled)
    {
        body->paintDisabled();
        hold = false;
        check_result = false;
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
                body->paintHoverToggled();
                check_result = true;
                hold = true;
            }
            else
            {
                check_result = false;
            }
        }
        else
        {
            body->paintHover();
            check_result = false;
            hold = false;
        }
    }
    else
    {
        body->paintResting();
        check_result = false;
    }
    return check_result;
}
