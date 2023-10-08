class Player
{
private:
    Fruction fruction;
    Fruction sFruction;
    std::string name;
    std::string path;
    sf::RectangleShape iconPlayer;
public:
    Player();
    ~Player();

    void setName(std::string name);
    void setPath(std::string path);
    void setFruction(Fruction fruction);
    void saveFruction();

    void uploadSave();
    void loadSave();

    std::string getName();
    std::string getPath();
    Fruction getFruction();
    Fruction getSaveFruction();
};