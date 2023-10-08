#include "interface.h"

/// defaultElement \\\|
Element::Element()
{
    font.loadFromFile(pathFont);
    mainText.setFont(font);
    mainText.setCharacterSize(fontSize);
    mainText.setFillColor(sf::Color::Yellow);
}

void Element::initSecondPointBox() { secondPointBox = mainBox.getSize() + mainBox.getPosition(); }
void Element::setSize(sf::Vector2f size)
{
    mainBox.setSize(size);
    initSecondPointBox();
}
void Element::setPosition(sf::Vector2f position)
{
    mainBox.setPosition(position);
    initSecondPointBox();
}
void Element::setColorBox(sf::Color color) { mainBox.setFillColor(color); }
void Element::setOutlineColorBox(sf::Color color) { mainBox.setOutlineColor(color); }
void Element::setColorText(sf::Color color) { mainText.setFillColor(color); }
void Element::setHide(bool isHide) { this->isHide = isHide; }

sf::Vector2f Element::getSize() { return mainBox.getSize(); }
sf::Vector2f Element::getPosition() { return mainBox.getPosition(); }
sf::Color Element::getColorBox() { return mainBox.getFillColor(); }
sf::Color Element::getOutlineColorBox() { return mainBox.getOutlineColor(); }
sf::Color Element::getColorText() { return mainText.getFillColor(); }

bool Element::isClick(sf::Vector2i mouse)
{
    return (mainBox.getPosition().x <= mouse.x && mouse.x <= secondPointBox.x &&
            mainBox.getPosition().y <= mouse.y && mouse.y <= secondPointBox.y) &&
           !isHide;
}

/// Button \\\|

Button::Button(sf::Vector2f size, sf::Vector2f pos, std::string txt, bool isHide = false,
               sf::Color color = sf::Color(125, 125, 125),
               sf::Color outlineColor = sf::Color(125, 125, 255))
{
    mainBox.setSize(size);
    mainBox.setPosition(pos);
    mainBox.setFillColor(color);
    mainBox.setOutlineColor(outlineColor);
    mainBox.setOutlineThickness(-3);

    mainText.setCharacterSize(fontSize);
    mainText.setString(txt);
    mainText.setPosition(mainBox.getPosition() + sf::Vector2f(20, 0));

    this->isHide = isHide;

    initSecondPointBox();
}
void Button::draw(sf::RenderWindow &window)
{
    if (!isHide)
    {
        window.draw(mainBox);
        window.draw(mainText);
    }
}

/// Text \\\|

Text::Text(sf::Vector2f pos = sf::Vector2f(0, 0), std::string txt = "")
{
    mainText.setPosition(pos);
    mainText.setString(txt);
}

void Text::draw(sf::RenderWindow &window) { window.draw(mainText); }
