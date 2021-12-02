#include "DrawingBody.h"
#include <iostream>
#include <cmath>

void DrawingBody::drawHorLine(Color line_color, float y, float thickness = 2)
{
    auto* line = new RectangleShape;
    line->setOrigin(0,thickness/2);
    line->setPosition(shape.left, shape.top+y);
    line->setFillColor(line_color);
    line->setSize(Vector2f(shape.width, thickness));
    draw_queue.push((Drawable*)line);
}

void DrawingBody::drawLine(Color line_color, Vector2f start, Vector2f end, float thickness = 2)
{
    float radian = 57.295779;
    auto* line = new RectangleShape;
    float delta_y = end.y - start.y;
    float delta_x = end.x - start.x;
    line->setOrigin(0,thickness/2);
    line->setPosition(shape.left+start.x, shape.top+start.y);
    line->setSize(Vector2f(sqrtf(delta_y*delta_y + delta_x*delta_x), thickness));
    line->setRotation(atanf(delta_y/delta_x)*radian);
    line->setFillColor(line_color);
    draw_queue.push((Drawable*)line);
}

void DrawingBody::drawVertLine(Color line_color, float x, float thickness = 2)
{
    auto* line = new RectangleShape;
    line->setOrigin(0,thickness/2);
    line->setPosition(shape.left+x, shape.top);
    line->setFillColor(line_color);
    line->setSize(Vector2f(shape.width, thickness));
    line->setRotation(90);
    draw_queue.push((Drawable*)line);
}

void DrawingBody::drawPoint(Color point_color, Vector2f pos, float radius = 2)
{
    auto* point = new CircleShape;
    point->setRadius(radius);
    point->setOrigin(radius, radius);
    point->setFillColor(point_color);
    point->setPosition(shape.left+pos.x, shape.top+pos.y);
    draw_queue.push((Drawable*)point);
}

void DrawingBody::drawRect(Color rect_fill_color, Color rect_outline_color, Vector2f pos, Vector2f size,
                           float outline_thickness)
{
    auto* rect = new RectangleShape;
    rect->setFillColor(rect_fill_color);
    rect->setOutlineColor(rect_outline_color);
    rect->setOutlineThickness(outline_thickness);
    rect->setPosition(shape.left+pos.x, shape.top+pos.y);
    rect->setSize(size);
    draw_queue.push((Drawable*)rect);
}

void DrawingBody::setBoardPos(Vector2f new_pos)
{
    shape.left = new_pos.x;
    shape.top = new_pos.y;
}

void DrawingBody::setBoardSize(Vector2f new_size)
{
    shape.width = new_size.x;
    shape.height = new_size.y;
}

void DrawingBody::draw(RenderWindow* window)
{
    while(!draw_queue.empty())
    {
        window->draw(*(draw_queue.front()));
        delete draw_queue.front();
        draw_queue.pop();
    }
}

bool DrawingBody::mouseHover(Vector2f mouse_pos)
{
    return shape.contains(mouse_pos);
}

void DrawingBody::transform(Vector2f pos, Vector2f size)
{
    setBoardSize(size);
    setBoardPos(pos);
}

FloatRect DrawingBody::getGlobalBounds()
{
    return shape;
}

FloatRect DrawingBody::getLocalBounds()
{
    return FloatRect(0, 0, shape.width, shape.height);
}

