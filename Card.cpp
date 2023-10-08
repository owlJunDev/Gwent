#include "Card.h"

Card::Card(
    Fruction fruction,
    bool isSun,
    int point,
    Position posCard,
    std::string imgPath,
    std::string cardName)
{
    this->fruction = fruction;
    this->cardName = cardName;
    this->isSun = isSun;
    this->point = point;
    this->posCard = posCard;
    this->imgPath = imgPath;
    isSelect = false;

    card.setSize(sf::Vector2f(150, 250));
    card.setFillColor(sf::Color(240, 230, 140));
    card.setOutlineColor(sf::Color(12, 0, 0));
    card.setOutlineThickness(2);
}

// getData
Position Card::getPosCard() { return posCard; }
Fruction Card::getFruction() { return fruction; }
std::string Card::getName() { return cardName; }
int Card::getPoint() { return point; }
bool Card::isCardSelect() { return isSelect; }

// setData
void Card::setSelect(bool isSelect) { this->isSelect = isSelect; }

void Card::draw(sf::RenderWindow &window) 
{
    window.draw(card);
}