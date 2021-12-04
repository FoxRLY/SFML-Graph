#pragma once
#include "../UIElement.h"

// Работает с ButtonEvent, CheckBoxEvent и InputTextBoxEvent

class RectShapeBody : public UIElementBody
{
private:
    RectangleShape shape;
    Color click_color;
    Color hover_color;
    Color resting_color;
    Color disabled_color;
public:
    RectShapeBody();
    void setClickColor(Color new_color);
    void setHoverColor(Color new_color);
    void setRestingColor(Color new_color);
    void setDisabledColor(Color new_color);
    void setSize(Vector2f new_size);
    void setShape(RectangleShape& new_shape);
    void setPos(Vector2f new_pos);
    void setOutline(float new_outline);
    RectangleShape& getShape();

    bool mouseHover(Vector2f mouse_pos) override;
    FloatRect getGlobalBounds() override;
    FloatRect getLocalBounds() override;
    void transform(Vector2f pos, Vector2f size) override;
    void paintDisabled() override;
    void paintToggledDisabled() override;
    void paintResting() override;
    void paintToggled() override;
    void paintHover() override;
    void paintHoverToggled() override;
    void draw(RenderWindow* window) override;
};

void RectShapeBodyPreset(RectShapeBody* button_body);


