#include "UIElement.h"

UIElementBody::~UIElementBody() = default;
UIEvent::~UIEvent() = default;

Vector2i UIEvent::getMousePos(RenderWindow* window)
{
    return Mouse::getPosition(*window);
}

bool UIEvent::isKeyPressed(Keyboard::Key key)
{
    return Keyboard::isKeyPressed(key);
}

bool UIEvent::isMouseKeyPressed(Mouse::Button button)
{
    return Mouse::isButtonPressed(button);
}