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

public:
	Card(
		Fruction fruction = Fruction::NUN,
		std::string cardName = "NuN",
		bool isSun = false,
		int point = 15,
		Position posCard = Position::ALL,
		std::string imgPath = "assets\\")
	{
		this->fruction = fruction;
		this->cardName = cardName;
		this->isSun = isSun;
		this->point = point;
		this->posCard = posCard;
		this->imgPath = imgPath;
		isSelect = false;
	}
	void info()
	{
		std::cout << "\n log:"
				  << "\n\t fruction: " << (int)fruction
				  << "\n\t cardName: " << cardName
				  << "\n\t isSun: " << (isSun ? "yes" : "no")
				  << "\n\t point: " << point
				  << "\n\t posCard: " << (int)posCard
				  << "\n\t imgPath: " << imgPath;
	}

	// getData
	Position getPosCard() { return posCard; }
	std::string getName() { return cardName; }
	int getPoint() { return point; }
	bool getSelect() { return isSelect; }

	//setData
	void setSelect(bool isSelect) {this->isSelect = isSelect;}
};