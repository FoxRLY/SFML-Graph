#pragma once
#include "../UIElement.h"
#include <queue>


class DrawingBody : public UIElementBody
{
private:
    std::queue<Drawable*> draw_queue;
    FloatRect shape;
public:
    void drawHorLine(Color line_color, float y, float thickness);
    void drawVertLine(Color line_color, float x, float thickness);
    void drawPoint(Color point_color, Vector2f pos, float radius);
    void drawLine(Color line_color, Vector2f start, Vector2f end, float thickness);
    void drawRect(Color rect_fill_color, Color rect_outline_color, Vector2f pos, Vector2f size, float outline_thickness);
    void setBoardSize(Vector2f new_size);
    void setBoardPos(Vector2f new_pos);

    bool mouseHover(Vector2f mouse_pos) override;
    FloatRect getGlobalBounds() override;
    FloatRect getLocalBounds() override;
    void transform(Vector2f pos, Vector2f size) override;
    void draw(RenderWindow* window) override;
};
