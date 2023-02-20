class Label
{
public:
	std::string text;

protected:
	sf::Font None;
	double x;
	double y;
	std::string pathTTF = "assets/ffont.ttf";
	sf::Text TXT;
	int fontSize = 64;

public:
	Label(double _x = 0, double _y = 0, std::string _text = "Label")
	{
		None.loadFromFile(pathTTF);

		x = _x;
		y = _y;
		text = _text;
		TXT.setFont(None);
		TXT.setPosition(x, y);
		TXT.setCharacterSize(fontSize);
	}
	void displayText(sf::RenderWindow &window)
	{
		TXT.setString(text);
		window.draw(TXT);
	}	
	void setPosition(int x, int y)
	{
		TXT.setPosition(x, y);
	}
	void setFontSize(int size) {TXT.setCharacterSize(size);}
	void setColor(sf::Color color) {TXT.setFillColor(color);}
};

class Button : public Label
{
protected:
	double width;
	double height;
	sf::RectangleShape BOX;
	sf::Texture texture;

public:
	Button(double _x = 0, double _y = 0, double _width = 150, double _height = 30, std::string _text = "Button")
	{
		None.loadFromFile(pathTTF);

		x = _x;
		y = _y;
		width = _width;
		height = _height;
		text = _text;
		TXT.setFont(None);
		TXT.setCharacterSize(fontSize);
		TXT.setCharacterSize(20);
		TXT.setPosition(x, y + height / 4);
		texture.loadFromFile("assets\\button.png");

		BOX.setSize(sf::Vector2f(width, height));
		BOX.setPosition(x, y);
		BOX.setTexture(&texture);
		BOX.setTextureRect(sf::IntRect(0, 0, 197, 44));
	}

	void setSetting(double _x = 0, double _y = 0, double _width = 150, double _height = 30, std::string _text = "Button")
	{
		None.loadFromFile(pathTTF);

		x = _x;
		y = _y;
		width = _width;
		height = _height;
		text = _text;
		TXT.setFont(None);
		TXT.setCharacterSize(fontSize);
		TXT.setCharacterSize(24);
		TXT.setPosition(x + width / 8, y + height / 4);
		texture.loadFromFile("assets\\button.png");

		BOX.setSize(sf::Vector2f(width, height));
		BOX.setPosition(x, y);
		BOX.setTexture(&texture);
		BOX.setTextureRect(sf::IntRect(0, 0, 197, 44));
	}

	bool select(sf::Vector2i _mouse)
	{
		if ((_mouse.x > x && _mouse.x < x + width) && (_mouse.y > y && _mouse.y < y + height))
		{
			std::cout << "\nlog: click button [" + text + ']';
			return true;
		}
		return false;
	}

	void displayButton(sf::RenderWindow &window)
	{
		TXT.setString(text);
		window.draw(BOX);
		window.draw(TXT);
	}

	sf::Vector2f getPosition() { return BOX.getPosition(); }
};

class Bar : public Label
{
protected:
	double width;
	double height;
	sf::RectangleShape box;
	sf::RectangleShape bar;

public:
	Bar(double _x = 0, double _y = 0, double _width = 100, double _height = 30, std::string _text = "Bar")
	{
		None.loadFromFile(pathTTF);

		x = _x;
		y = _y;
		width = _width;
		height = _height;
		text = _text;
		TXT.setFont(None);
		TXT.setCharacterSize(20);
		TXT.setPosition(x, y);

		box.setSize(sf::Vector2f(width, height));
		box.setFillColor(sf::Color(0, 0, 0, 0));
		box.setOutlineThickness(-2);
		box.setOutlineColor(sf::Color(66, 66, 66));
		box.setPosition(box.getOutlineThickness(), y);

		bar.setSize(sf::Vector2f(width - box.getOutlineThickness() * 2, height - box.getOutlineThickness() * 2));
		bar.setPosition(box.getPosition().x, y);
		bar.setFillColor(sf::Color(0, 255, 0));
		bar.setOutlineColor(sf::Color(66, 66, 66));
	}

	void setPoint(int point)
	{
		bar.setSize(sf::Vector2f(point, bar.getSize().y));
	}

	void displayBar(sf::RenderWindow &window)
	{
		TXT.setString(text);
		window.draw(box);
		window.draw(bar);
		window.draw(TXT);
	}
};