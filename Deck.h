#include "Card.cpp"

class Decks
{
protected:
	std::vector<Card *> mainDeck;
	std::vector<int> countCardRow;
	std::vector<int> idNilf;
	std::vector<int> idNord;
	std::string path = "save/card.sv";

public:
	Decks();

	void saveSelectPlayerDeck();
	void upladAllCard();
	virtual void draw(sf::RenderWindow &window) = 0;
	virtual void isClick(sf::Vector2i mouse) = 0;
};

class CardDeck : public Decks
{
private:
	std::vector<Card *> deckFruction;

public:
	CardDeck(Fruction fruction);
	void draw(sf::RenderWindow &window) override;
	void isClick(sf::Vector2i mouse) override;
};