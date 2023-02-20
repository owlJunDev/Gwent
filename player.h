class Player {
    private:
        std::string name;
        sf::RectangleShape icon;
        Fruction fruction;

    public:
        Player () {}       
        Player (std::string name, Fruction fruction)  {
            this->name = name;
            this->fruction = fruction;
            sf::Texture texture;
            texture.loadFromFile("assets\\logo.png");
        }
        void initPlayer (std::string name, Fruction fruction)  {
            this->name = name;
            this->fruction = fruction;
            sf::Texture texture;
            texture.loadFromFile("assets\\logo.png");
        }

        std::string getName() { return name; }
        int getFruction() { return int(fruction); };

        void setName(std::string name){ this->name = name; }
        void setFruction (Fruction fruction) { this->fruction = fruction; }
};