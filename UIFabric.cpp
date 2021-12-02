#include "UIFabric.h"

UIElement* UIFabric::createRectShapeButton(RenderWindow* window)
{
    auto* body = new RectShapeBody;
    auto* event = new ButtonEvent;
    auto* button = new UIElement(body, event, window);
    return button;
}

UIElement* UIFabric::createRectShapeCheckBox(RenderWindow* window)
{
    auto* body = new RectShapeBody;
    auto* event = new CheckBoxEvent;
    auto* checkbox = new UIElement(body, event, window);
    return checkbox;
}

UIElement* UIFabric::createRectShapeInputTextBox(RenderWindow *window)
{
    auto* body = new RectShapeBody;
    auto* event = new InputTextBoxEvent;
    auto* input_text_box = new UIElement(body, event, window);
    return input_text_box;
}

UIElement* UIFabric::createDrawingBox(RenderWindow *window)
{
    auto* body = new DrawingBody;
    auto* event = new GraphNavEvent;
    auto* drawing_box = new UIElement(body, event, window);
    return drawing_box;
}