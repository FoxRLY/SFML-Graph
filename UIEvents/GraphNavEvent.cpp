#include "GraphNavEvent.h"

Vector2f GraphNavEvent::getMouseDelta()
{
    return mouse_pos_delta;
}

bool GraphNavEvent::check(UIElementBody *body, RenderWindow *window)
{
    if(!is_enabled)
    {
        body->paintDisabled();
        check_result = false;
        //left_hold = false;
        center_hold = false;
        center_graph_flag = false;
        return check_result;
    }
    sf::Vector2i pixelPos = getMousePos(window);
    sf::Vector2f worldPos = window->mapPixelToCoords(pixelPos);
    if(body->mouseHover(worldPos))
    {
        if(isMouseKeyPressed(Mouse::Middle))
        {
            if(!center_hold)
            {
                center_graph_flag = true;
                center_hold = true;
            }
        }
        else
        {
            center_hold = false;
        }
        if(Mouse::isButtonPressed(Mouse::Left))
        {
            if(!check_result)
            {
                body->paintHoverToggled();
                prev_mouse_pos = worldPos;
                check_result = true;
            }
            else
            {
                mouse_pos_delta = worldPos - prev_mouse_pos;
                prev_mouse_pos = worldPos;
            }
        }
        else
        {
            body->paintHover();
            check_result = false;
        }
    }
    else
    {
        body->paintResting();
        check_result = false;
    }
    return check_result;
}