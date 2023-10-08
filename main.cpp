#include <SFML/Graphics.hpp>

#include <vector>
#include <iostream>
#include <fstream>
#include <io.h>
#include <stdio.h>

enum ScreenType
{
    MENU,
    GAME,
    CARD
};
enum Position
{
    KING,
    ALL,
    SHORT,
    MID,
    LONG
};
enum Fruction
{
    NEUTRAL,
    NILFGAARD,
    KINGDOMNORTH
};

#include "interface.cpp"
#include "Player.cpp"
#include "Deck.cpp"
#include "Screen.cpp"

int main()
{
	setlocale(LC_ALL, "");
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Gwent");
    sf::Image icon;
    ScreenType screenT = ScreenType::MENU;
    window.setPosition(sf::Vector2i(1930, 0));
    // window.setFramerateLimit();

    if (icon.loadFromFile("assets/icon.png"))
        window.setIcon(256, 256, icon.getPixelsPtr());

    Player player;

    Screen *screen = new MenuScreen();
    screen->setPlayer(player);

    do
    {
        sf::Event event;
        if (screenT != screen->getScreen())
        {
            screenT = screen->getScreen();
            screen->getPlayer(player);
            switch (screenT)
            {
            case ScreenType::MENU:
                screen = new MenuScreen();
                break;
            case ScreenType::GAME:
                screen = new GameScreen();
                break;
            case ScreenType::CARD:
                screen = new CardScreen(player.getFruction(), window);
            }
            screen->setPlayer(player);
        }
        screen->isEvent(window, event);
        window.clear(sf::Color(0, 0, 0, 0));
        screen->draw(window);
        window.display();
    } while (!screen->isEnd() && window.isOpen());

    return 0;
}