namespace game
{
    Button button[3];

    void draw(sf::RenderWindow &win)
    {
        button[0].displayButton(win);
    }

    void screen(sf::RenderWindow &win, sf::View &view, Screen &screen)
    {
        std::cout << "\nlog: game: end in";
        button[0].setSetting(0, 0, 150, 50, "menu");
        

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
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if (button[0].select(sf::Mouse::getPosition(win)))
                {
                    screen = Screen::MENU;
                    break;
                }
            }

            win.clear();
            draw(win);
            win.display();
        }
    }
};