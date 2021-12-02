#pragma once
#include "UIElement.h"
#include "UIBodies/RectShapeBody.h"
#include "UIBodies/DrawingBody.h"
#include "UIEvents/ButtonEvent.h"
#include "UIEvents/CheckBoxEvent.h"
#include "UIEvents/InputTextBoxEvent.h"
#include "UIEvents/GraphNavEvent.h"

class UIFabric
{
private:
public:
    static UIElement* createRectShapeButton(RenderWindow* window);
    static UIElement* createRectShapeCheckBox(RenderWindow* window);
    static UIElement* createRectShapeInputTextBox(RenderWindow* window);
    static UIElement* createDrawingBox(RenderWindow* window);
};