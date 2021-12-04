#pragma once
#include "UIElement.h"
#include "UIBodies/RectShapeBody.h"
#include "UIBodies/DrawingBody.h"
#include "UIBodies/CameraBody.h"
#include "UIEvents/ButtonEvent.h"
#include "UIEvents/CheckBoxEvent.h"
#include "UIEvents/InputTextBoxEvent.h"
#include "UIEvents/GraphNavEvent.h"
#include "UIEvents/DefaultEvent.h"

class UIFabric
{
private:
public:
    static UIElement* createRectShapeButton(RenderWindow* window);
    static UIElement* createRectShapeCheckBox(RenderWindow* window);
    static UIElement* createRectShapeInputTextBox(RenderWindow* window);
    static UIElement* createDrawingBox(RenderWindow* window);
    static UIElement* createCameraBox(RenderWindow* window);
};