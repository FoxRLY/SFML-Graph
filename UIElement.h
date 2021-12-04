#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class UIElementBody
{
public:
    virtual void paintDisabled(){};
    virtual void paintToggledDisabled(){};
    virtual void paintResting(){};
    virtual void paintToggled(){};
    virtual void paintHover(){};
    virtual void paintHoverToggled(){};

    virtual bool mouseHover(Vector2f mouse_pos) = 0;
    virtual void transform(Vector2f pos, Vector2f size) = 0;
    virtual FloatRect getGlobalBounds() = 0;
    virtual FloatRect getLocalBounds() = 0;
    virtual void draw(RenderWindow* window) = 0;
    virtual ~UIElementBody() = 0;
};

class UIEvent
{
protected:
    bool check_result;
    bool is_enabled;
public:
    UIEvent()
    {
        check_result = false;
        is_enabled = true;
    }
    static Vector2i getMousePos(RenderWindow* window);
    static bool isKeyPressed(Keyboard::Key);
    static bool isMouseKeyPressed(Mouse::Button);

    virtual void setResult(bool new_result)
    {
        check_result = new_result;
    }
    virtual bool checkResult()
    {
        return check_result;
    }
    virtual void setEnabled(bool active)
    {
        is_enabled = active;
    }
    virtual bool isEnabled()
    {
        return is_enabled;
    }

    virtual bool check(UIElementBody* body, RenderWindow* window) = 0;
    virtual ~UIEvent() = 0;
};

class UIElement
{
private:
    UIElementBody* body;
    UIEvent* event;
    RenderWindow* window;
public:
    UIElement(UIElementBody* new_body, UIEvent* new_event, RenderWindow* new_window)
    {
        body = new_body;
        event = new_event;
        window = new_window;
    }
    void setEventEnabled(bool active)
    {
        event->setEnabled(active);
    }
    bool isEventEnabled()
    {
        return event->isEnabled();
    }
    bool eventCheck()
    {
        return event->check(body, window);
    }
    bool checkResult()
    {
        return event->checkResult();
    }
    void setResult(bool new_result)
    {
        event->setResult(new_result);
    }
    void draw()
    {
        body->draw(window);
    }
    UIElementBody* getBody()
    {
        return body;
    }
    UIEvent* getEvent()
    {
        return event;
    }
    RenderWindow* getWindow()
    {
        return window;
    }
    void setBody(UIElementBody* new_body)
    {
        body = new_body;
    }
    void setMouseEvent(UIEvent* new_event)
    {
        event = new_event;
    }
    void setWindow(RenderWindow* new_window)
    {
        window = new_window;
    }
    ~UIElement()
    {
        delete body;
        delete event;
    }
};

void uiEventLoop(std::vector<UIElement*>& event_list);