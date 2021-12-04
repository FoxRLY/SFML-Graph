#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "translator.h"
#include "UIFabric.h"


using namespace sf;

void TextPreset(Text& text, Font& font)
{
    text.setFont(font);
    text.setString("");
    text.setFillColor(Color::Black);
    text.setCharacterSize(40);
}

bool inputChar(UIElement* input_box, Text& input_text, char input_char)
{
    if(input_box->checkResult())
    {
        InputTextBoxEvent::addChar(input_char, input_text);
        if(input_text.getGlobalBounds().width > input_box->getBody()->getGlobalBounds().width)
        {
            InputTextBoxEvent::addChar(8, input_text);
        }
        return true;
    }
    return false;
}

int main()
{
    // Окно приложения
    RenderWindow window(VideoMode( 1640, 1080 ), L"Рисование графиков");
    window.setVerticalSyncEnabled(true);



    // Шрифт для элементов
    Font mono;
    mono.loadFromFile("../assets/JetBrainsMono-Bold.ttf");



    // Список элементов интерфейса
    std::vector<UIElement*> event_list;


    // Окно рисования
    UIElement* drawing_box = UIFabric::createDrawingBox(&window);
    auto* drawing_box_body = (DrawingBody*)drawing_box->getBody();
    drawing_box_body->transform(Vector2f(730,100), Vector2f(880, 880));
    event_list.push_back(drawing_box);


    // Кнопки управления
    UIElement* draw_button = UIFabric::createRectShapeButton(&window);
    event_list.push_back(draw_button);

    auto* draw_button_body = (RectShapeBody*)draw_button->getBody();
    RectShapeBodyPreset(draw_button_body);
    draw_button_body->transform(Vector2f(30,621), Vector2f(600,150));

    UIElement* clear_button = UIFabric::createRectShapeButton(&window);
    event_list.push_back(clear_button);

    auto* clear_button_body = (RectShapeBody*)clear_button->getBody();
    RectShapeBodyPreset(clear_button_body);
    clear_button_body->transform(Vector2f(30,850), Vector2f(600,150));


    // Подписи кнопок управления
    Text draw_button_label;
    TextPreset(draw_button_label, mono);
    draw_button_label.setString(L"Отобразить графики");
    float h_delta = (150 - draw_button_label.getGlobalBounds().height)/2.f;
    float w_delta = (600 - draw_button_label.getGlobalBounds().width)/2.f;
    draw_button_label.setPosition(30+w_delta, 621+h_delta-5);

    Text clear_button_label;
    TextPreset(clear_button_label, mono);
    clear_button_label.setString(L"Очистить поле");
    h_delta = (150 - clear_button_label.getGlobalBounds().height)/2.f;
    w_delta = (600 - clear_button_label.getGlobalBounds().width)/2.f;
    clear_button_label.setPosition(30+w_delta, 850+h_delta-5);



    // Подписи элементов ввода
    Text input_box_1_label;
    TextPreset(input_box_1_label, mono);
    input_box_1_label.setString(L"Функция 1:");
    input_box_1_label.setPosition(30, 40);

    Text input_box_2_label;
    TextPreset(input_box_2_label, mono);
    input_box_2_label.setString(L"Функция 2:");
    input_box_2_label.setPosition(30, 240);

    Text input_box_3_label;
    TextPreset(input_box_3_label, mono);
    input_box_3_label.setString(L"Функция 3:");
    input_box_3_label.setPosition(30, 440);



    // Окно ввода 1
    UIElement* input_box_1 = UIFabric::createRectShapeInputTextBox(&window);
    event_list.push_back(input_box_1);

    // Форматирование тела окна ввода 1
    auto* input_box_1_body = (RectShapeBody*)input_box_1->getBody();
    RectShapeBodyPreset(input_box_1_body);
    input_box_1_body->transform(Vector2f(30, 100), Vector2f(600, 42));

    // Создание и форматирование строки ввода 1
    Text input_text_1;
    TextPreset(input_text_1, mono);
    input_text_1.setPosition(30, 96);



    // Окно ввода 2
    UIElement* input_box_2 = UIFabric::createRectShapeInputTextBox(&window);
    event_list.push_back(input_box_2);

    // Форматирование тела окна ввода 2
    auto* input_box_2_body = (RectShapeBody*)input_box_2->getBody();
    RectShapeBodyPreset(input_box_2_body);
    input_box_2_body->transform(Vector2f(30, 300), Vector2f(600, 42));

    // Создание и форматирование строки ввода 2
    Text input_text_2;
    TextPreset(input_text_2, mono);
    input_text_2.setPosition(30, 296);



    // Окно ввода 3
    UIElement* input_box_3 = UIFabric::createRectShapeInputTextBox(&window);
    event_list.push_back(input_box_3);

    // Форматирование тела окна ввода 3
    auto* input_box_3_body = (RectShapeBody*)input_box_3->getBody();
    RectShapeBodyPreset(input_box_3_body);
    input_box_3_body->transform(Vector2f(30, 500), Vector2f(600, 42));

    // Создание и форматирование строки ввода 3
    Text input_text_3;
    TextPreset(input_text_3, mono);
    input_text_3.setPosition(30, 496);


    // Калькулятор вводимых функций
    Calculator calculator;


    // Цикл приложения
    while(window.isOpen())
    {
        // Цикл обработки событий элементов интерфейса
        uiEventLoop(event_list);

        // Цикл обработки событий окна
        Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case Event::Closed:
                {
                    window.close();
                    break;
                }
                case Event::Resized:
                {
                    //window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
                    break;
                }
                case Event::TextEntered:
                {
                    if(event.text.unicode < 128)
                    {
                        char input_char = static_cast<char>(event.text.unicode);
                        if(inputChar(input_box_1, input_text_1, input_char) ||
                           inputChar(input_box_2, input_text_2, input_char) ||
                           inputChar(input_box_3, input_text_3, input_char))
                        {
                            break;
                        }
                    }
                    break;
                }
            }
        }

        // Цикл отрисовки
        window.clear(Color::White);
        input_box_1->draw();
        input_box_2->draw();
        input_box_3->draw();
        draw_button->draw();
        clear_button->draw();


        if(draw_button->checkResult())
        {
            drawing_box_body->clearDrawings();
            drawing_box_body->drawRect(Color::White, Color::Black, Vector2f(0,0), Vector2f(880,880), 5);
        }
        drawing_box->draw();

        window.draw(input_text_1);
        window.draw(input_text_2);
        window.draw(input_text_3);
        window.draw(input_box_1_label);
        window.draw(input_box_2_label);
        window.draw(input_box_3_label);
        window.draw(draw_button_label);
        window.draw(clear_button_label);

        // Вывод изображения
        window.display();
    }
}

