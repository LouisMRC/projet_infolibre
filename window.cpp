#include "window.hpp"

int map(int value, int start1, int stop1, int start2, int stop2)
{
	return start2 + (value - start1) * (stop2 - start2) / (stop1 - start1);
}

Window::Window()
{
    this->win = new sf::RenderWindow(sf::VideoMode(800, 600), "Foo");
    this->win->setFramerateLimit(20);

    int i = 0;
    while (win->isOpen())
    {
       // Event processing
       sf::Event event;
       while (win->pollEvent(event))
       {
           // Request for closing the window
           if (event.type == sf::Event::Closed)
               win->close();
       }

       win->clear(Window::getColor(i));
       // End the current frame and display its contents on screen
       win->display();
       i++;
    }

    delete this->win;
}

sf::Color Window::getColor(int soundAmp)
{
    return sf::Color((soundAmp <= 100 ? (soundAmp >= 50 ? map(soundAmp, 50, 100, 0, 255) : 0) : 255), (soundAmp <= 100 ? (soundAmp <= 50 ? map(soundAmp, 0, 50, 0, 255) : map(soundAmp, 50, 100, 255, 0)) : 0), (soundAmp <= 50 ? map(soundAmp, 0, 50, 255, 0) : 0));
}
