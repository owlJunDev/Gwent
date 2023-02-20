namespace card
{
    Button button[3];

    void draw(sf::RenderWindow &win)
    {
        button[0].displayButton(win);
        button[1].displayButton(win);
        decks.drawPlayDeckFruction(win);
    }
    bool isKeyPressed = false;
    bool isKeyFree = true;

    void screen(sf::RenderWindow &win, sf::View &view, Screen &screen)
    {
        sf::Clock clock;
        float lastTime = 0;
        decks.setPage(0);
        bool isSave = false;

        std::cout << "\nlog: card: end in";
        button[0].setSetting(0, 0, 150, 50, "menu");
        button[1].setSetting(winWidth - 150, 0, 150, 50, "save");

        while (win.isOpen())
        {

            view.setSize(win.getSize().x, win.getSize().y);
            win.setView(view);

            sf::Event event;
            while (win.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    win.close();
                    screen = Screen::END;
                }
            }

            if (isMouseLeftFree)
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    if (button[0].select(sf::Mouse::getPosition(win)))
                    {
                        screen = Screen::MENU;
                        if (isSave)
                            decks.uploadSave("assets/saveCardDeck.txt", player);
                        break;
                    }
                    if (button[1].select(sf::Mouse::getPosition(win))){
                        decks.saveSelectPlayerDeck();
                        isSave = true;
                    }
                    
                    decks.clickAllCard(sf::Mouse::getPosition(win));
                    isMouseLeftFree = false;
                    isMouseLeftPressed = true;
                }
            if (isMouseLeftPressed) {
                if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    isMouseLeftFree = true;
                    isMouseLeftPressed = false;
                }
            }
            
            // sf::Event event;
            if (isKeyFree)
                if (sf::Event::KeyPressed == event.type)
                {
                    isKeyFree = false;
                    isKeyPressed = true;
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { decks.setPage(decks.getPage() - 1);}
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { decks.setPage(decks.getPage() + 1);}
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { screen = Screen::MENU; break;}
                    std::cout << "\n\tlog: page: " << decks.getPage();
                }
            if (isKeyPressed)
                if (sf::Event::KeyPressed != event.type)
                {
                    isKeyFree = true;
                    isKeyPressed = false;
                }

            win.clear();
            draw(win);
            win.display();
        }
    }
};