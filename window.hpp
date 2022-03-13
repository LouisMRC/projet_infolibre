#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Window
{
public:
    Window();

    void repaint(sf::RenderTarget *panel, sf::Color bgColor);

    static sf::Color getColor(int soundAmp);
protected:
    sf::RenderWindow *win;
};

#endif // WINDOW_HPP
