class Element
{
protected:
    sf::RectangleShape mainBox;
    sf::Text mainText;
    sf::Font font;
    int fontSize = 36;
    std::string pathFont = "assets/font.ttf";
    sf::Vector2f secondPointBox;
    bool isHide = false;

    void initSecondPointBox();

public:
    Element();

    void setSize(sf::Vector2f size);
    void setPosition(sf::Vector2f position);
    void setColorBox(sf::Color color);
    void setOutlineColorBox(sf::Color color);
    void setColorText(sf::Color color);
    void setHide(bool isHide);

    sf::Vector2f getSize();
    sf::Vector2f getPosition();
    sf::Color getColorBox();
    sf::Color getOutlineColorBox();
    sf::Color getColorText();

    bool isClick(sf::Vector2i mouse);

    virtual void draw(sf::RenderWindow &window) = 0;
};

class Button : public Element
{
public:
    Button(sf::Vector2f size, sf::Vector2f pos, std::string txt, bool isHide,
           sf::Color color,
           sf::Color outlineColor);
    void draw(sf::RenderWindow &window) override;
};

class Text : public Element
{
public:
    Text(sf::Vector2f pos, std::string txt);
    void draw(sf::RenderWindow &window) override;
};