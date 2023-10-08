#include "Screen.h"

/// Screen \\\|
void Screen::isEvent(sf::RenderWindow &window, sf::Event event)
{
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (isMouseFree)
            {
                isMouseFree = false;
                isMousePressed = true;
                isLeftClick(sf::Mouse::getPosition(window));
            }
        }
        if (event.type != sf::Event::MouseButtonPressed)
        {
            if (isMousePressed)
            {
                isMouseFree = true;
                isMousePressed = false;
            }
        }
        if (isScroll)

            if (event.type == sf::Event::MouseWheelMoved)
            {
                std::cout << event.mouseWheel.delta;
            }
        if (event.type == sf::Event::KeyPressed)
        {
            key(window, event);
        }
    }
}

ScreenType Screen::getScreen() { return screen; }
bool Screen::isEnd() { return isEndProccess; }

void Screen::defaultDraw(sf::RenderWindow &window)
{
    for (auto element : elements)
    {
        element->draw(window);
    }
}
void Screen::setPlayer(Player &player)
{
    this->player = player;
}

void Screen::getPlayer(Player &player)
{
    player = this->player;
}

/// MenuScreen \\\|

MenuScreen::MenuScreen()
{
    screen = ScreenType::MENU;
    elements.push_back(new Button(sf::Vector2f(150, 50), sf::Vector2f(10, 0), "exit"));       // 0
    elements.push_back(new Button(sf::Vector2f(150, 50), sf::Vector2f(30, 360), "play"));     // 1
    elements.push_back(new Button(sf::Vector2f(150, 50), sf::Vector2f(30, 460), "card"));     // 2
    elements.push_back(new Button(sf::Vector2f(150, 50), sf::Vector2f(30, 460), "NORD", 1));  // 3
    elements.push_back(new Button(sf::Vector2f(150, 50), sf::Vector2f(190, 460), "NILF", 1)); // 4
}
void MenuScreen::draw(sf::RenderWindow &window) { defaultDraw(window); }
void MenuScreen::isLeftClick(sf::Vector2i mouse)
{
    if (elements.at(0)->isClick(mouse))
    {
        isEndProccess = true;
        return;
    }

    if (elements.at(1)->isClick(mouse))
    {
        screen = ScreenType::GAME;
        return;
    }

    if (elements.at(2)->isClick(mouse))
    {
        elements.at(2)->setHide(1);
        elements.at(3)->setHide(0);
        elements.at(4)->setHide(0);
        return;
    }

    if (elements.at(3)->isClick(mouse))
    {
        screen = ScreenType::CARD;
        player.setFruction(Fruction::KINGDOMNORTH);
        return;
    }

    if (elements.at(4)->isClick(mouse))
    {
        screen = ScreenType::CARD;
        player.setFruction(Fruction::NILFGAARD);
        return;
    }

    elements.at(2)->setHide(0);
    elements.at(3)->setHide(1);
    elements.at(4)->setHide(1);
}
void MenuScreen::key(sf::RenderWindow &window, sf::Event event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        isEndProccess = true;
    }
}

/// GameScreen \\\|

GameScreen::GameScreen()
{
    screen = ScreenType::GAME;
    elements.push_back(new Button(sf::Vector2f(150, 50), sf::Vector2f(0, 0), "back"));
}
void GameScreen::draw(sf::RenderWindow &window) { defaultDraw(window); }
void GameScreen::isLeftClick(sf::Vector2i mouse)
{
    if (elements.at(0)->isClick(mouse))
        screen = ScreenType::MENU;
}
void GameScreen::key(sf::RenderWindow &window, sf::Event event) {}

/// CardScreen \\\|

CardScreen::CardScreen(Fruction fruction, sf::RenderWindow &window)
{
    screen = ScreenType::CARD;
    deck = new CardDeck(fruction);
    elements.push_back(new Button(sf::Vector2f(window.getSize().x, 70), sf::Vector2f(0, 0), ""));
    elements.push_back(new Button(sf::Vector2f(window.getSize().x, 70), sf::Vector2f(0, 0), ""));
    elements.push_back(new Button(sf::Vector2f(150, 50), sf::Vector2f(10, 10), "back"));
}
void CardScreen::draw(sf::RenderWindow &window) { deck->draw(window); defaultDraw(window);  }
void CardScreen::isLeftClick(sf::Vector2i mouse)
{
    if (elements.at(0)->isClick(mouse))
        if (elements.at(1)->isClick(mouse))
            screen = ScreenType::MENU;

}
void CardScreen::key(sf::RenderWindow &window, sf::Event event) {}

/*// Screen \\\|

Screen::Screen() {}
void Screen::draw(sf::RenderWindow &window) { defaultDraw(window); }
void Screen::isLeftClick(sf::Vector2i mouse) {}
void Screen::key(sf::RenderWindow &window, sf::Event event) {}
//*/