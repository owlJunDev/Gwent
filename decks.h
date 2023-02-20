class Decks
{
private:
	std::vector<Card> mainDeck;

	sf::RectangleShape card;
	sf::Texture textureCard;
	Label cardName, point, pageTitle;

	Fruction fruction;

	int sizeX = 150, sizeY = 250;

	// list playCard
	int column = 0, pageRow = 0, allRow = 0, count = 0;
	int rangeX = 0, rangeY = 0, range = 0;
	int page = 0, maxPage = 0;

	std::vector<int> countCardRow;
	std::vector<int> countNilf;
	std::vector<int> countNord;

public:
	Decks() {}
	Decks(std::string path, Player& player) { init(path, player); }

	Fruction getFruction() {return fruction;}
	
	void setFruction(Fruction fruction) {
		if (this->fruction != fruction)
		{
			this->fruction = fruction;
			recalculationCountCardPage(fruction == Fruction::KINGDOMNORTH ?
										countNord.size() :
										fruction == Fruction::NILFGAARD ?
											countNilf.size() :
											count);
			for (auto card: mainDeck)
				card.setSelect(false);
		}
	}

	void recalculationCountCardPage(int count)
	{
		countCardRow.clear();
		allRow = ((count - (count % column)) / column) + 1;

		for (int i = 0; i < allRow; i++)
		{
			countCardRow.push_back(column);
		}
		maxPage = count / int(pageRow * column);

		if (float(float(count) / float(column)) > float(allRow - 1))
		{
			countCardRow.at(allRow - 1) = count % column;
			maxPage++;
		}
		else
		{
			countCardRow.pop_back();
		}
	}

	void saveSelectPlayerDeck()
	{
		std::cout << "\nlog: save";
		std::ofstream saveDeck("assets/saveCardDeck.txt");
		for (int i = 0; i < count; i++)
			if (mainDeck.at(i).getSelect())
				saveDeck << std::to_string(i) + '|';
	}

	void init(std::string pathCard, Player& player, std::string pathSaveCard = "assets\\saveCardDeck.txt")
	{
		std::cout << "\nlog: start uploadData\n";
		std::string param;
		std::ifstream file(pathCard), save(pathSaveCard);

		card.setSize(sf::Vector2f(sizeX, sizeY));
		card.setFillColor(sf::Color(240, 230, 140));
		card.setOutlineColor(sf::Color(12, 0, 0));
		card.setOutlineThickness(2);

		cardName.setColor(sf::Color::Black);
		point.setColor(sf::Color::Black);

		cardName.setFontSize(24);

		range = 48;
		column = (winWidth - 100) / (sizeX + range);
		pageRow = (winHeight - 100) / (sizeY + range);

		rangeX = winWidth / (column + 1);
		rangeY = winHeight / (pageRow + 1);
		std::cout << "\nlog: card: ";

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

			Fruction fr = Fruction(std::stoi(param));
			switch (fr)
			{
			case Fruction::NILFGAARD:
				countNilf.push_back(count);
				break;
			case Fruction::KINGDOMNORTH:
				countNord.push_back(count);
				break;

			default:
				countNilf.push_back(count);
				countNord.push_back(count);
				break;
			}

			getline(file, param, '|'); // name
			if (param == "" or param.empty())
			{
				break;
			}
			for (int i = 0; i < param.length(); i++)
				if (param[i] == ' ')
					param[i] = '\n';
			std::string name = param;

			getline(file, param, '|'); // hero
			if (param == "" or param.empty())
			{
				break;
			}
			bool isSoul = std::stoi(param);

			getline(file, param, '|'); // point
			if (param == "" or param.empty())
			{
				break;
			}
			int point = std::stoi(param);

			getline(file, param, '|'); // pos
			if (param == "" or param.empty())
			{
				break;
			}
			Position pos = (param == "меч" ? Position::SHORT : (param == "лук" ? Position::MID : Position::LONG));

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
			std::string path = (param == "assets\\" ? "" : param);

			Card cCard(fr, name, isSoul, point, pos, path);
			count++;

			mainDeck.push_back(cCard);
		} while (!file.eof());

		

		uploadSave(pathSaveCard, player);

		recalculationCountCardPage(fruction == Fruction::KINGDOMNORTH ?
										countNord.size() :
										fruction == Fruction::NILFGAARD ?
											countNilf.size() :
											count);

		std::cout << "\nlog: end uploadData\n";
	}

	void uploadSave(std::string pathSave, Player& player) {
		std::ifstream save(pathSave);
		std::string param;

		getline(save, param, '|');
		std::string playerName = param;
		getline(save, param, '|');
		Fruction frPlayer = Fruction(std::stoi(param));
		fruction = frPlayer;
		player.initPlayer(playerName, frPlayer);

		do // read saved cards and player
		{
			getline(save, param, '|'); // path
			if (!param.empty())
				mainDeck.at(std::stoi(param)).setSelect(true);
		} while (!save.eof());

	}

	void setPage(int page)
	{
		if (page >= 0 && page < maxPage)
			this->page = page;
	}

	int getPage() { return page; }

	void drawFieldPlaying(sf::RenderWindow &win)
	{
		int qty[3]{2, 50, 15};

		sf::RectangleShape field(sf::Vector2f(win.getSize().x - 6, 115));

		card.setFillColor(sf::Color::Green);
		card.setOutlineColor(sf::Color(0, 0, 0));
		card.setOutlineThickness(-2);

		field.setPosition(sf::Vector2f(3, 50));
		field.setOutlineColor(sf::Color(255, 0, 0));
		field.setOutlineThickness(3);

		int size[3];
		for (int i = 0; i < 3; i++)
		{
			size[i] = (card.getSize().x * qty[i] > field.getSize().x) ? (field.getSize().x - card.getSize().x) / (qty[i] - 1) : card.getSize().x;
			size[i] < card.getSize().x / 2 ? size[i] = card.getSize().x / 2 : size[i];
		}

		for (int j = 0; j < 3; j++)
		{
			field.setPosition(sf::Vector2f(field.getPosition().x, 50 + field.getSize().y * j));
			win.draw(field);
			for (int i = 0; i < qty[j]; i++)
			{
				card.setPosition(sf::Vector2f(field.getPosition().x + size[j] * i, field.getPosition().y));
				win.draw(card);
			}
		}
	}

	void drawPlayDeckFruction(sf::RenderWindow &win)
	{
		int iteratorCard = page * pageRow * column;
		int row = allRow < pageRow ? allRow : (page + 1 == maxPage ? (allRow % pageRow == 0 ? pageRow : allRow % pageRow) : pageRow);
		pageTitle.text = "page " + std::to_string(page + 1) + '/' + std::to_string(maxPage);
		pageTitle.setPosition(winWidth / 2 - 128, 0);
		int iCard;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < countCardRow.at(i + pageRow * page); j++)
			{
				iCard = fruction == Fruction::KINGDOMNORTH ?
							countNord.at(iteratorCard) :
							fruction == Fruction::NILFGAARD ?
								countNilf.at(iteratorCard) :
								iteratorCard;
				int x = rangeX * (j + 1) - sizeX / 2, y = rangeY * (i + 1) - sizeY / 2;
				card.setPosition(x, y);
				// card.setTexture(&mainDeck.at(iteratorCard).getTexture());
				if (mainDeck.at(iCard).getSelect())
				{
					card.setOutlineColor(sf::Color::Red);
					card.setOutlineThickness(6);
				}
				else
				{
					card.setOutlineThickness(0);
				}
				point.text = std::to_string(mainDeck.at(iCard).getPoint());
				point.setPosition(x, y);

				cardName.text = mainDeck.at(iCard).getName();
				cardName.setPosition(x, y + sizeY / 2);

				iteratorCard++;

				win.draw(card);
				point.displayText(win);
				cardName.displayText(win);
			}
		}
		pageTitle.displayText(win);
	}

	void clickAllCard(sf::Vector2i mouse)
	{
		int iteratorCard = page * pageRow * column;
		int row = allRow < pageRow ? allRow : (page + 1 == maxPage ? (allRow % pageRow == 0 ? pageRow : allRow % pageRow) : pageRow);
		int iCard;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < countCardRow.at(i + pageRow * page); j++)
			{
				iCard = fruction == Fruction::KINGDOMNORTH ?
							countNord.at(iteratorCard) :
							fruction == Fruction::NILFGAARD ?
								countNilf.at(iteratorCard) :
								iteratorCard;
				int x = rangeX * (j + 1) - sizeX / 2, y = rangeY * (i + 1) - sizeY / 2;
				if ((mouse.x >= x && mouse.x < x + sizeX) &&
					(mouse.y >= y && mouse.y < y + sizeY))
				{
					mainDeck.at(iCard).setSelect(!mainDeck.at(iCard).getSelect());
					break;
				}
				iteratorCard++;
			}
		}
	}

	void info()
	{
		system("cls");
		std::cout << "\n log:"
				  << "\n\t sizeX: " << sizeX
				  << "\n\t sizeY: " << sizeY
				  << "\n\t column: " << column
				  << "\n\t pageRow: " << pageRow
				  << "\n\t allRow: " << allRow
				  << "\n\t rangeX: " << rangeX
				  << "\n\t rangeY: " << rangeY
				  << "\n\t range: " << range
				  << "\n\t count: " << count
				  << "\n\t maxPage: " << maxPage
				  << "\n\t cardPage: " << column * pageRow
				  << "\n\t sizeRow: " << countCardRow.size()
				  << "\n\t nord: " << countNord.size()
				  << "\n\t nilf: " << countNilf.size();
	}
};