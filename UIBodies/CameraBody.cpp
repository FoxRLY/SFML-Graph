#include "CameraBody.h"

void CameraBody::setView(RenderWindow* window)
{
    window->setView(view);
}

RectangleShape CameraBody::shapeToView(View &new_view, RenderWindow *window)
{
    RectangleShape new_shape;
    Vector2f size(new_view.getViewport().width*(float)window->getSize().x,
                  new_view.getViewport().height*(float)window->getSize().y);
    Vector2f pos(new_view.getViewport().left*(float)window->getSize().x,
                 new_view.getViewport().top*(float)window->getSize().y);
    new_shape.setSize(size);
    new_shape.setPosition(pos);
    return new_shape;
}
View CameraBody::viewToShape(RectangleShape& new_shape, RenderWindow* window)
{
    View new_view;
    FloatRect rect;
    rect.width = new_shape.getSize().x / (float)window->getSize().x;
    rect.height = new_shape.getSize().y / (float)window->getSize().y;
    rect.left = new_shape.getPosition().x / (float)window->getSize().x;
    rect.top = new_shape.getPosition().y / (float)window->getSize().y;
    new_view.setViewport(rect);
    return new_view;
}
Vector2f CameraBody::rectPosToViewPos(Vector2f pos)
{
    return Vector2f(pos.x + shape.getSize().x/2.0,
                    pos.y + shape.getSize().y/2.0);
}

void CameraBody::setDisplayRect(RectangleShape& new_shape, RenderWindow* window)
{
    shape = new_shape;
    view = viewToShape(new_shape, window);
}

View CameraBody::getView()
{
    return view;
}

void CameraBody::setCameraPos(Vector2f pos)
{
    view.setCenter(rectPosToViewPos(pos));
}

bool CameraBody::mouseHover(Vector2f mouse_pos)
{
    return shape.getGlobalBounds().contains(mouse_pos);
}
FloatRect CameraBody::getGlobalBounds()
{
    return shape.getGlobalBounds();
}
FloatRect CameraBody::getLocalBounds()
{
    return shape.getLocalBounds();
}
void CameraBody::transform(Vector2f pos, Vector2f size)
{
}
void CameraBody::draw(RenderWindow* window)
{
}