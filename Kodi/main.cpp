#include <SFML/Graphics.hpp>
#include "Fight.h"
#include <fstream>


int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Insert game name", sf::Style::None);
    Fight ao;

    ao.store(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        ao.fight(window);

        ao.draw(window);
    }
}
