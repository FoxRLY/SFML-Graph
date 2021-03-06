#pragma once
#include "../UIElements/UIElement.h"

class CameraBody : public UIElementBody
{
private:
    RectangleShape shape;
    View view;
    RectangleShape shapeToView(View& new_view);
    View viewToShape(RectangleShape& new_shape);
    Vector2f rectPosToViewPos(Vector2f pos);
    Vector2f viewPosToRectPos(Vector2f pos);
public:
    explicit CameraBody(RenderWindow* new_window);
    void setDisplayRect(Vector2f pos, Vector2f size);
    void setCameraPos(Vector2f pos);
    void setCameraCenter(Vector2f pos);
    Vector2f getCameraPos();
    View getView();
    void applyView();
    void resetView();

    bool mouseHover(Vector2f mouse_pos) override;
    FloatRect getGlobalBounds() override;
    FloatRect getLocalBounds() override;
    void transform(Vector2f pos, Vector2f size) override;
    void draw() override;
};