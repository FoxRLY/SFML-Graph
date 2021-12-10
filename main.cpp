#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "translator.h"
#include "UIElements/UIConstructor.h"


using namespace sf;

void TextPreset(Text& text, Font& font)
{
    text.setFont(font);
    text.setString("");
    text.setFillColor(Color::Black);
    text.setCharacterSize(40);
}

void drawGraphPlane(DrawingBody* drawing_body, int plane_size, int grid_size, Font& font)
{
    for(int i = 0; i < plane_size; i += grid_size)
    {
        if(plane_size / 2.0 == (float)i)
        {
            drawing_body->drawHorLine(Color::Green, i, 3);
            drawing_body->drawVertLine(Color::Red, i, 3);
        }
        else
        {
            drawing_body->drawHorLine(Color::Black, i, 2);
            drawing_body->drawVertLine(Color::Black, i, 2);
        }

        for(int k = 0; k < plane_size; k += grid_size)
        {
            Text number;
            TextPreset(number, font);
            number.setCharacterSize(12);
            std::string y_number = std::to_string(-(i - plane_size/2));
            std::string x_number = std::to_string(k - plane_size/2);

            number.setString(x_number);
            number.setOrigin(number.getGlobalBounds().width, 0);
            drawing_body->drawText(number, Vector2f(k-3, i+3));

            number.setString(y_number);
            number.setOrigin(0, number.getGlobalBounds().height);
            drawing_body->drawText(number, Vector2f(k+3,i-3));
        }

    }


}

int main()
{
    // Окно приложения
    RenderWindow window(VideoMode( 1640, 1080 ), L"Рисование графиков");
    window.setVerticalSyncEnabled(true);


    // Шрифт для элементов
    Font mono;
    mono.loadFromFile("../assets/JetBrainsMono-Bold.ttf");


    // Calculator
    Calculator calculator;


    // Список элементов интерфейса
    std::vector<UIElement*> event_list;


    // Камера для графика
    UIElement* camera_box = UIConstructor::createCameraBox(&window);
    auto* camera_box_body = (CameraBody*)camera_box->getBody();
    camera_box_body->setDisplayRect(Vector2f(730, 90), Vector2f(890,890));
    event_list.push_back(camera_box);


    // Окно рисования
    UIElement* drawing_box = UIConstructor::createDrawingBox(&window);
    auto* drawing_box_body = (DrawingBody*)drawing_box->getBody();
    drawing_box_body->transform(Vector2f(0,0), Vector2f(10000, 10000));
    event_list.push_back(drawing_box);


    // Кнопки управления
    UIElement* draw_button = UIConstructor::createRectShapeButton(&window);
    event_list.push_back(draw_button);

    auto* draw_button_body = (RectShapeBody*)draw_button->getBody();
    RectShapeBodyPreset(draw_button_body);
    draw_button_body->transform(Vector2f(30,621), Vector2f(600,150));

    UIElement* clear_button = UIConstructor::createRectShapeButton(&window);
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
    UIElement* input_box_1 = UIConstructor::createRectShapeInputTextBox(&window);
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
    UIElement* input_box_2 = UIConstructor::createRectShapeInputTextBox(&window);
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
    UIElement* input_box_3 = UIConstructor::createRectShapeInputTextBox(&window);
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
        UIElement::eventCheckLoop(event_list);

        // Перемещение камеры
        auto* camera_box_event = (GraphNavEvent*)camera_box->getEvent();
        camera_box_body->setCameraPos(camera_box_body->getCameraPos() - camera_box_event->getMouseDelta());

        // Центровка камеры
        if(camera_box_event->getCenterGraphFlag())
        {
            camera_box_body->setCameraCenter(Vector2f(5000, 5000));
        }

        // Кнопка "Отобразить графики"
        if(draw_button->getEventResult())
        {
            camera_box_body->setCameraCenter(Vector2f(5000, 5000));
            drawing_box_body->clearDrawings();
            drawGraphPlane(drawing_box_body, 10000, 200, mono);
        }


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
                case Event::TextEntered:
                {
                    if(event.text.unicode < 128)
                    {
                        char input_char = static_cast<char>(event.text.unicode);
                        if(InputTextBoxEvent::inputChar(input_box_1, input_text_1, input_char) ||
                           InputTextBoxEvent::inputChar(input_box_2, input_text_2, input_char) ||
                           InputTextBoxEvent::inputChar(input_box_3, input_text_3, input_char))
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

        camera_box_body->applyView();
        drawing_box->draw();
        camera_box_body->resetView();

        input_box_1->draw();
        input_box_2->draw();
        input_box_3->draw();
        draw_button->draw();
        clear_button->draw();

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

