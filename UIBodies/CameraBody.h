#pragma once
#include "../UIElement.h"

class CameraBody : public UIElementBody
{
private:
    RectangleShape shape;
    View view;
    static RectangleShape shapeToView(View& new_view, RenderWindow* window);
    static View viewToShape(RectangleShape& new_shape, RenderWindow* window);
    Vector2f rectPosToViewPos(Vector2f pos);
public:
    void setDisplayRect(RectangleShape& new_shape, RenderWindow* window);
    void setCameraPos(Vector2f pos);
    View getView();

    bool mouseHover(Vector2f mouse_pos) override;
    FloatRect getGlobalBounds() override;
    FloatRect getLocalBounds() override;
    void transform(Vector2f pos, Vector2f size) override;
    void draw(RenderWindow* window) override;
};