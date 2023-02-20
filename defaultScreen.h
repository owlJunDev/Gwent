namespace load
{
    Label text(0, 0, "load");
    void draw(sf::RenderWindow &win)
    {
    }

    void screen(sf::RenderWindow &win, sf::View &view, Screen &screen)
    {


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


            win.clear();
            draw(win);
            win.display();
        }
    }
};