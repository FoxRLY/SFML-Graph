#pragma once
#include "../UIElement.h"

class GraphNavEvent : public UIEvent
{
private:
    Vector2f prev_mouse_pos;
    Vector2f mouse_pos_delta;
    //bool left_hold;
    bool center_hold;
    bool center_graph_flag;

public:
    GraphNavEvent()
    {
        center_graph_flag = false;
        //left_hold = false;
        center_hold = false;
    }
    Vector2f getMouseDelta();
    bool& getCenterGraphFlag()
    {
        return center_graph_flag;
    }

    bool check(UIElementBody* body, RenderWindow* window) override;
};

