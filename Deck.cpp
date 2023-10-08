#include "Deck.h"

/// Decks \\\|

Decks::Decks() { upladAllCard(); }

void Decks::upladAllCard()
{
    std::string param;
    std::ifstream file(path);
    int id = 0;

    Fruction fr;
    int point;
    bool isSoul;
    Position pos;
    std::string path;
    std::string name;
    bool isSelect;

    do // read all cards
    {
        getline(file, param, '|'); // fruction
        if (param == "" or param.empty())
        {
            break;
        }
        if (param[0] == '\n')
            param.erase(0, 1);
        // using namespace std;

        fr = Fruction(std::stoi(param));

        switch (fr)
        {
        case Fruction::NILFGAARD:
            idNilf.push_back(id);
            break;
        case Fruction::KINGDOMNORTH:
            idNord.push_back(id);
            break;

        default:
            idNilf.push_back(id);
            idNord.push_back(id);
            break;
        }

        getline(file, param, '|'); // isHero
        if (param == "" or param.empty())
        {
            break;
        }
        isSoul = std::stoi(param);

        getline(file, param, '|'); // point
        if (param == "" or param.empty())
        {
            break;
        }

        if (param == "x" || param == "l")
            point = param == "x" ? 10 : 15;
        else
            point = std::stoi(param);

        getline(file, param, '|'); // pos
        if (param == "" or param.empty())
        {
            break;
        }
        pos = (param == "s" ? Position::SHORT : (param == "b" ? Position::MID : Position::LONG));

        getline(file, param, '|'); // special
        if (param == "" or param.empty())
        {
            break;
        }
        // special

        getline(file, param, '|'); // path
        if (param == "" or param.empty())
        {
            break;
        }
        path = (param == "assets\\" ? "" : param);

        getline(file, param, '|'); // name
        if (param == "" or param.empty())
        {
            break;
        }
        for (int i = 0; i < param.length(); i++)
            if (param[i] == ' ')
                param[i] = '\n';
        name = param;

        // Card cCard(fr, isSoul, point, pos, path, name);
        mainDeck.push_back(new Card(fr, isSoul, point, pos, path, name));
    } while (!file.eof());
    std::cout << "\nCount All card: " << mainDeck.size();
}
void Decks::saveSelectPlayerDeck() {}

/// CardDeck \\\|

CardDeck::CardDeck(Fruction fruction)
{
    for (auto card : mainDeck)
        if (card->getFruction() == fruction || card->getFruction() == Fruction::NEUTRAL)
            deckFruction.push_back(card);
    std::cout << "\nCount Fruction card: " << deckFruction.size();
}

void CardDeck::draw(sf::RenderWindow &window)
{
    for (auto card : deckFruction)
    {
        std::cout << "\nname: " << card->getName();
        // card->draw(window);
    }
};
void CardDeck::isClick(sf::Vector2i mouse){};
