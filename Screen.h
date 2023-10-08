class Screen {
protected:
    std::vector<Element *> elements;
    bool isScroll = false;
    bool isEndProccess;
    bool isKeyPressed = false, isKeyFree = true;
    bool isMousePressed = false, isMouseFree = true;
    Player player;
    std::string enteredText = "";
    ScreenType screen;
    sf::View view;
    Decks *deck;

    void defaultDraw(sf::RenderWindow &window);

public:

    virtual void draw(sf::RenderWindow &window) = 0;
    void isEvent(sf::RenderWindow &window, sf::Event event);
    virtual void key(sf::RenderWindow &window, sf::Event event) = 0;
    virtual void isLeftClick(sf::Vector2i mouse) = 0;
    void setPlayer(Player &player);
    void getPlayer(Player &player);

    ScreenType getScreen();
    bool isEnd();
    void textInput(sf::Event event);
};

class MenuScreen : public Screen {
    private:
    public:
    MenuScreen();
    ~MenuScreen();
    void draw(sf::RenderWindow &window) override;
    void key(sf::RenderWindow &window, sf::Event event) override;
    void isLeftClick(sf::Vector2i mouse) override;
};

class GameScreen : public Screen {
    private:
    public:
    GameScreen();
    ~GameScreen();
    void draw(sf::RenderWindow &window) override;
    void key(sf::RenderWindow &window, sf::Event event) override;
    void isLeftClick(sf::Vector2i mouse) override;
};

class CardScreen : public Screen {
    private:
    public:
    CardScreen(Fruction fruction, sf::RenderWindow &window);
    ~CardScreen();
    void draw(sf::RenderWindow &window) override;
    void key(sf::RenderWindow &window, sf::Event event) override;
    void isLeftClick(sf::Vector2i mouse) override;
};