#ifndef FIGHT_H
#include <SFML/Graphics.hpp>
#define FIGHT_H


class Fight
{
    public:
        Fight();
        void store(sf::RenderWindow &win);
        void draw(sf::RenderWindow &win);
        void fight(sf::RenderWindow &win);
    protected:

    private:
        sf::RectangleShape bg;
        sf::RectangleShape mc;
        sf::RectangleShape pl1;
        sf::RectangleShape pl2;
        sf::RectangleShape pl3;
        sf::RectangleShape shootBox;

        sf::Texture* stickman = new sf::Texture;
        sf::Texture* bgTexture = new sf::Texture;
        sf::Texture dedstickman;

        sf::Font font;
        sf::Text mcT;
        sf::Text pl1T;
        sf::Text pl2T;
        sf::Text pl3T;
        sf::Text mainText;

        int mch = 100;
        int pl1h = 100;
        int pl2h = 100;
        int pl3h = 100;

        int rradh = 0;

        sf::RectangleShape longsh;
        sf::RectangleShape fist;
        sf::Texture longt;
        sf::Texture fistt;

        sf::Clock cl1;
        int a1 = 0;
        int b1 = 0;
        int c1 = 0;
        int d1 = 0;
        int g1 = 0;
        int san = 0;
        int sran2;

        int a2 = 0;

        int pran1;
        int sran1;
};

#endif // FIGHT_H
