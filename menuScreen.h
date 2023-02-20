namespace menu
{

    Label title(0, 0, "The Gwent");
    sf::RectangleShape backgroun;
    Button button[6];
    bool isSelect = false;
    

    void draw(sf::RenderWindow &win)
    {
        win.draw(backgroun);
        button[0].displayButton(win);
        if (isSelect)
        {
            button[2].displayButton(win);
            button[3].displayButton(win);
            button[4].displayButton(win);
        }
        else
        {
            button[1].displayButton(win);
        }
        button[5].displayButton(win);
        title.displayText(win);
    }

    void screen(sf::RenderWindow &win, sf::View &view, Screen &screen)
    {
        isSelect = false;
        std::cout << "\nlog: menu: end in";
        sf::Texture t;

        t.loadFromFile("assets\\logo.png");
        backgroun.setSize(sf::Vector2f(win.getSize().x, win.getSize().y));
        backgroun.setTexture(&t);

        title.setPosition(win.getSize().x / 2 - 150, win.getSize().y / 2 + 120);

        button[0].setSetting(0, win.getSize().y / 2, 150, 50, "game");
        button[1].setSetting(0, button[0].getPosition().y + 100, 150, 50, "card");
        button[2].setSetting(0, button[1].getPosition().y, 150, 50, "nord");
        button[3].setSetting(button[2].getPosition().x + 150, button[1].getPosition().y, 150, 50, "nilf");
        button[4].setSetting(button[3].getPosition().x + 150, button[1].getPosition().y, 150, 50, "play");
        button[5].setSetting(0, button[1].getPosition().y + 100, 150, 50, "exit");

        while (win.isOpen())
        {
            sf::Event event;
            view.setSize(win.getSize().x, win.getSize().y);
            win.setView(view);
            while (win.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    win.close();
                    screen = Screen::END;
                }
            }
            std::cout << "\nlog: click Pressed: " << std::to_string(isMouseLeftPressed) << ", click Free: " << std::to_string(isMouseLeftFree);
            if (isMouseLeftPressed)
                if (event.type != sf::Event::MouseButtonPressed)
                    isMouseLeftFree = true, isMouseLeftPressed = false;

            if (isMouseLeftFree)
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    isMouseLeftFree = false, isMouseLeftPressed = true;
                    if (button[0].select(sf::Mouse::getPosition(win)))
                    {
                        screen = Screen::GAME;
                        break;
                    } 
                    else if (button[1].select(sf::Mouse::getPosition(win)) && !isSelect)
                    {
                        isSelect = true;
                    }
                    else if (button[2].select(sf::Mouse::getPosition(win)) && isSelect)
                    {
                        screen = Screen::CARD;
                        decks.setFruction(Fruction::KINGDOMNORTH);
                        break;
                    }
                    else if (button[3].select(sf::Mouse::getPosition(win)) && isSelect)
                    {
                        screen = Screen::CARD;
                        decks.setFruction(Fruction::NILFGAARD);
                        break;
                    }
                    else if (button[4].select(sf::Mouse::getPosition(win)) && isSelect)
                    {
                        screen = Screen::CARD;
                        break;
                    }
                    else if (button[5].select(sf::Mouse::getPosition(win)))
                    {
                        win.close();
                        screen = Screen::END;
                    }
                }
            win.clear();
            draw(win);
            win.display();
        }
    }
};