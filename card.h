class Card
{
private:
    Fruction fruction;
    std::string cardName;
    bool isSun;
    int point;
    Position posCard;
    std::string imgPath;
    bool isSelect;
	sf::RectangleShape card;

public:
    Card(
        Fruction fruction = Fruction::NEUTRAL,
        bool isSun = false,
        int point = 15,
        Position posCard = Position::ALL,
        std::string imgPath = "assets\\",
        std::string cardName = "NuN");
    // getData
    Position getPosCard();
    Fruction getFruction();
    std::string getName();
    int getPoint();
    bool isCardSelect();

    // setData
    void setSelect(bool isSelect);
    void draw(sf::RenderWindow &window);
};