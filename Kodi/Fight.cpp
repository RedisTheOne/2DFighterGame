#include "Fight.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


Fight::Fight()
{
    //ctor
}

void Fight::store(sf::RenderWindow &win)
{
    bg.setSize(sf::Vector2f(1000.0f, 800.0f));
    mc.setSize(sf::Vector2f(80.0f, 100.0f));
    pl1.setSize(sf::Vector2f(80.0f, 100.0f));
    pl2.setSize(sf::Vector2f(80.0f, 100.0f));
    pl3.setSize(sf::Vector2f(80.0f, 100.0f));
    mc.setPosition(sf::Vector2f(200.0f, 500.0f));
    pl1.setPosition(sf::Vector2f(50.0f, 500.0f));
    pl2.setPosition(sf::Vector2f(700.0f, 500.0f));
    pl3.setPosition(sf::Vector2f(850.0f, 500.0f));

    bgTexture->loadFromFile("./fightSceneImages/fightBackground.jpeg");
    bg.setTexture(&*bgTexture);
    dedstickman.loadFromFile("./fightSceneImages/deadStickMan.png");

    stickman->loadFromFile("./fightSceneImages/stickman.png");
    mc.setTexture(&*stickman);
    pl1.setTexture(&*stickman);
    pl2.setTexture(&*stickman);
    pl3.setTexture(&*stickman);

    //Text
    if(!font.loadFromFile("./fonts/FontFile.ttf")){
        std::cout << "ERROR404\n";
    }

    mcT.setFont(font);
    pl1T.setFont(font);
    pl2T.setFont(font);
    pl3T.setFont(font);
    mainText.setFont(font);

    mcT.setString(std::to_string(mch));
    pl3T.setString(std::to_string(pl3h));
    pl2T.setString(std::to_string(pl2h));
    pl1T.setString(std::to_string(pl1h));

    mcT.setCharacterSize(30);
    pl3T.setCharacterSize(30);
    pl2T.setCharacterSize(30);
    pl1T.setCharacterSize(30);
    mainText.setCharacterSize(30);
    mcT.setFillColor(sf::Color::White);
    pl1T.setFillColor(sf::Color::White);
    pl2T.setFillColor(sf::Color::White);
    pl3T.setFillColor(sf::Color::White);
    mainText.setFillColor(sf::Color::White);


    mcT.setPosition(mc.getPosition().x + 15, 465);
    pl1T.setPosition(pl1.getPosition().x + 15, 465);
    pl2T.setPosition(pl2.getPosition().x + 15, 465);
    pl3T.setPosition(pl3.getPosition().x + 15, 465);
    mainText.setPosition(win.getSize().x/2 - mainText.getLocalBounds().width/2, 0);

    //ShootBox
    shootBox.setFillColor(sf::Color::Transparent);
    shootBox.setSize(sf::Vector2f(25.0f, 10.0f));
}


void Fight::draw(sf::RenderWindow &win)
{
    win.clear();
    //bg
    win.draw(bg);
    //players
    win.draw(mc);
    win.draw(pl1);
    win.draw(pl2);
    win.draw(pl3);
    //Text
    win.draw(mcT);
    win.draw(pl3T);
    win.draw(pl2T);
    win.draw(pl1T);
    win.draw(mainText);
    //ShootBox
    win.draw(shootBox);
    win.display();
}


void Fight::fight(sf::RenderWindow &win)
{
    srand(time(NULL));

    if(rradh == 0)
    {
        if(g1 == 0) {
            san = rand() % 2 + 1;
            g1++;
        }
        if(san == 1) {
            mainText.setString("Main Character Turn");
            mainText.setPosition(win.getSize().x/2 - mainText.getLocalBounds().width/2, 50);

            //Fist
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::F) && sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && a1 != 1 && pl2h > 0){
                a1 = 1;
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::F) && sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && a1 != 1 && a1 != 2 && pl3h > 0){
                a1 = 2;
            }

            if(a1 == 1){
                sf::Time t1 = cl1.getElapsedTime();
                int int1 = t1.asSeconds();
                if(int1 > 1 && mc.getPosition().x <= 680 && b1 == 0) {
                    mc.move(1.0f, 0.0f);
                    mcT.move(1.0f, 0.0f);
                    if(mc.getPosition().x == 680) {
                        b1 = 2;
                        cl1.restart();
                    }
                }
                if(int1 > 1 && b1 == 2 && mc.getPosition().x >= 200){
                    mc.move(-1.0f, 0.0f);
                    mcT.move(-1.0f, 0.0f);
                    if(mc.getPosition().x == 200){
                        pl2h -= rand()%50 + 1;
                        if(pl2h > 0) {
                            pl2T.setString(to_string(pl2h));
                        } else {
                            pl2T.setString("0");
                            pl2.setTexture(&dedstickman);
                        }
                        a2 = 0;
                        rradh = 1;
                    }
                }
            }

            if(a1 == 2){
                sf::Time t1 = cl1.getElapsedTime();
                int int1 = t1.asSeconds();
                if(int1 > 1 && mc.getPosition().x <= 820 && b1 == 0) {
                    mc.move(1.0f, 0.0f);
                    mcT.move(1.0f, 0.0f);
                    if(mc.getPosition().x == 820) {
                        b1 = 2;
                        cl1.restart();
                    }
                }
                if(int1 > 1 && b1 == 2 && mc.getPosition().x >= 200){
                    mc.move(-1.0f, 0.0f);
                    mcT.move(-1.0f, 0.0f);
                    if(mc.getPosition().x == 200){
                        pl3h -= rand()%50 + 1;
                        if(pl3h > 0) {
                            pl3T.setString(to_string(pl3h));
                        } else {
                            pl3T.setString("0");
                            pl3.setTexture(&dedstickman);
                        }
                        a2 = 0;
                        rradh = 1;
                    }
                }
            }

            //LongShot
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::L) && sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && c1 != 1 && c1 != 2 && pl2h > 0){
                c1 = 1;
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::L) && sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && c1 != 1 && c1 != 2 && pl3h > 0){
                c1 = 2;
            }

            if(c1 == 1){
                if(d1 == 0){
                    shootBox.setFillColor(sf::Color::Red);
                    shootBox.setPosition(sf::Vector2f(250.0f, 570.0f));
                    d1 = 1;
                }

                if(d1 == 1 && shootBox.getPosition().x <= 710) {
                    shootBox.move(1.0f, 0.0f);
                    if(shootBox.getPosition().x == 710){d1 = 2;}
                }

                if(d1 == 2){
                    shootBox.setFillColor(sf::Color::Transparent);
                    pl2h -= rand()%100 + 1;
                    if(pl2h > 0) {
                        pl2T.setString(to_string(pl2h));
                    } else {
                       pl2T.setString("0");
                       pl2.setTexture(&dedstickman);
                    }
                    a2 = 0;
                    rradh = 1;
                }
            }

            if(c1 == 2){
                if(d1 == 0){
                    shootBox.setFillColor(sf::Color::Red);
                    shootBox.setPosition(sf::Vector2f(250.0f, 570.0f));
                    d1 = 1;
                }

                if(d1 == 1 && shootBox.getPosition().x <= 863) {bg.setSize(sf::Vector2f(15000.0f, 1500.0f));
                    shootBox.move(1.0f, 0.0f);
                    if(shootBox.getPosition().x == 863){d1 = 2;}
                }

                if(d1 == 2){
                    shootBox.setFillColor(sf::Color::Transparent);
                    pl3h -= rand()%100 + 1;
                    if(pl3h > 0) {bg.setSize(sf::Vector2f(15000.0f, 1500.0f));
                        pl3T.setString(to_string(pl3h));
                    } else {
                       pl3T.setString("0");
                       pl3.setTexture(&dedstickman);
                    }
                    a2 = 0;
                    rradh = 1;bg.setSize(sf::Vector2f(15000.0f, 1500.0f));
                }
            }
        } else if(san == 2) {
            mainText.setString("Companion Turn");
            mainText.setPosition(win.getSize().x/2 - mainText.getLocalBounds().width/2, 50);
            if(a1 == 0) {
                cl1.restart();

                a1 = 1;
            }
            sf::Time t1 = cl1.getElapsedTime();
            int int1 = t1.asSeconds();
            if(pl2h <= 0 && pl3h > 0) {
                sran2 = 2;
            }else if(pl2h > 0 && pl3h <= 0) {
                sran2 = 1;
            }else {
                sran2 = rand()%2 + 1;
            }
            if(sran2 == 1) {
                if(int1 > 1){
                    if(a1 == 1){
                        pran1 = 1;
                        if(pl2h <= 0) {
                            a1 = 6;
                        } else {
                            a1 = 3;
                        }
                    }
                    if(a1 == 3){
                        shootBox.setFillColor(sf::Color::Red);

                        shootBox.setPosition(sf::Vector2f(140.0f, 570.0f));
                        a1 = 4;
                    }
                    if(a1 == 4 && shootBox.getPosition().x <= 720){
                        shootBox.move(1.0f, 0.0f);
                        if(shootBox.getPosition().x == 720){
                            a1 = 5;
                        }
                    }
                    if(a1 == 5){
                        shootBox.setFillColor(sf::Color::Transparent);
                        pl2h -= rand()%60 + 1;
                        if(pl2h < 0) {
                            pl2T.setString("0");
                            pl2.setTexture(&dedstickman);
                        } else {
                            pl2T.setString(to_string(pl2h));
                        }

                        a1 = 6;
                    }
                    if(a1 == 6){
                        a2 = 0;
                        a1 = 0;
                        rradh = 1;
                    }
                }
            } else if(sran2 == 2) {
                    if(int1 > 1){
                    if(a1 == 1){
                        pran1 = 1;
                        if(pl3h <= 0) {
                            a1 = 6;
                        } else {
                            a1 = 3;
                        }
                    }
                    if(a1 == 3){
                        shootBox.setFillColor(sf::Color::Red);

                        shootBox.setPosition(sf::Vector2f(140.0f, 570.0f));
                        a1 = 4;
                    }
                    if(a1 == 4 && shootBox.getPosition().x <= 820){
                        shootBox.move(1.0f, 0.0f);
                        if(shootBox.getPosition().x == 820){
                            a1 = 5;
                        }
                    }
                    if(a1 == 5){
                        shootBox.setFillColor(sf::Color::Transparent);
                        pl3h -= rand()%60 + 1;
                        if(pl3h < 0) {
                            pl3T.setString("0");
                            pl3.setTexture(&dedstickman);
                        } else {
                            pl3T.setString(to_string(pl3h));
                        }

                        a1 = 6;
                    }
                    if(a1 == 6){
                        a2 = 0;
                        a1 = 0;
                        rradh = 1;
                    }
                }
            }
        }
    }
    if(rradh == 1) {
        if(pl2h > 0 && pl3h > 0){
            sran1 = rand()%2 + 1;
        }else if(pl2h > 0 && pl3h <= 0) {
            sran1 = 1;
        } else if(pl2h <= 0 && pl3h > 0) {
            sran1 = 2;
        } else {
            sran1 = 0;
        }
        int sran2 = rand()%2 + 1;
        if(sran1 != 0) {
            mainText.setString("Enemy Turn");
            mainText.setPosition(win.getSize().x/2 - mainText.getLocalBounds().width/2, 50);
        } else if(sran1 == 0) {
            mainText.setString("Congratulations! You won!");
            mainText.setPosition(win.getSize().x/2 - mainText.getLocalBounds().width/2, 50);
        }
        if(sran2 == 2){
            if(a2 == 0) {
                cl1.restart();
                a2 = 1;
            }
            sf::Time t1 = cl1.getElapsedTime();
            int int1 = t1.asSeconds();

            if(int1 > 1){
                if(a2 == 1){
                    pran1 = 1;
                    a2 = 2;
                }
                if(pran1 == 1){
                    if(a2 == 2){
                        a2 = 3;
                    }
                    if(sran1 == 1){
                        if(a2 == 3){
                            shootBox.setFillColor(sf::Color::Red);
                            shootBox.setPosition(sf::Vector2f(700.0f, 570.0f));
                            a2 = 4;
                        }
                        if(a2 == 4 && shootBox.getPosition().x >= 140){
                            shootBox.move(-1.0f, 0.0f);
                            if(shootBox.getPosition().x == 140){
                                a2 = 5;
                            }
                        }
                        if(a2 == 5){
                            shootBox.setFillColor(sf::Color::Transparent);
                            pl1h -= rand()%30 + 1;
                            pl1T.setString(to_string(pl1h));
                            a2 = 6;
                        }
                        if(a2 == 6){
                            a1 = 0;
                            c1 = 0;
                            d1 = 0;
                            b1 = 0;
                            g1 = 0;
                            rradh = 0;
                        }
                    } else if(sran1 == 2){
                        if(a2 == 3){
                            shootBox.setFillColor(sf::Color::Red);
                            shootBox.setPosition(sf::Vector2f(830.0f, 570.0f));
                            a2 = 4;
                        }
                        if(a2 == 4 && shootBox.getPosition().x >= 140){
                            shootBox.move(-1.0f, 0.0f);
                            if(shootBox.getPosition().x == 140){
                                a2 = 5;
                            }
                        }
                        if(a2 == 5){
                            shootBox.setFillColor(sf::Color::Transparent);
                            pl1h -= rand()%30 + 1;
                            pl1T.setString(to_string(pl1h));
                            a2 = 6;
                        }
                        if(a2 == 6){
                            a1 = 0;
                            c1 = 0;
                            d1 = 0;
                            b1 = 0;
                            g1 = 0;
                            rradh = 0;
                        }
                    }
                    else if(sran1 == 0) {
                        mainText.setString("Congratulations! You won!");
                        mainText.setPosition(win.getSize().x/2 - mainText.getLocalBounds().width/2, 50);
                }

            }

          }
        } else if(sran2 == 1) {
            if(a2 == 0) {
                cl1.restart();
                a2 = 1;
            }
            sf::Time t1 = cl1.getElapsedTime();
            int int1 = t1.asSeconds();

            if(int1 > 1){
                if(a2 == 1){
                    pran1 = 1;
                    a2 = 2;
                }
                if(pran1 == 1){
                    if(a2 == 2){
                        a2 = 3;
                    }
                    if(sran1 == 1){
                        if(a2 == 3){
                            shootBox.setFillColor(sf::Color::Red);
                            shootBox.setPosition(sf::Vector2f(700.0f, 570.0f));
                            a2 = 4;
                        }
                        if(a2 == 4 && shootBox.getPosition().x >= 240){
                            shootBox.move(-1.0f, 0.0f);
                            if(shootBox.getPosition().x == 240){
                                a2 = 5;
                            }
                        }
                        if(a2 == 5){
                            shootBox.setFillColor(sf::Color::Transparent);
                            mch -= rand()%30 + 1;
                            mcT.setString(to_string(mch));
                            a2 = 6;
                        }
                        if(a2 == 6){
                            a1 = 0;
                            c1 = 0;
                            d1 = 0;
                            b1 = 0;
                            g1 = 0;
                            rradh = 0;
                        }
                    } else if(sran1 == 2){
                        if(a2 == 3){
                            shootBox.setFillColor(sf::Color::Red);
                            shootBox.setPosition(sf::Vector2f(830.0f, 570.0f));
                            a2 = 4;
                        }
                        if(a2 == 4 && shootBox.getPosition().x >= 240){
                            shootBox.move(-1.0f, 0.0f);
                            if(shootBox.getPosition().x == 240){
                                a2 = 5;
                            }
                        }
                        if(a2 == 5){
                            shootBox.setFillColor(sf::Color::Transparent);
                            mch -= rand()%30 + 1;
                            mcT.setString(to_string(mch));
                            a2 = 6;
                        }
                        if(a2 == 6){
                            a1 = 0;
                            c1 = 0;
                            d1 = 0;
                            b1 = 0;
                            g1 = 0;
                            rradh = 0;
                        }
                    }
                    else if(sran1 == 0) {
                        mainText.setString("Congratulations! You won!");
                        mainText.setPosition(win.getSize().x/2 - mainText.getLocalBounds().width/2, 50);
                }

            }

          }
        }
    }

}
