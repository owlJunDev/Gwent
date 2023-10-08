#include "Player.h"

Player::Player() { 
    path = "save/savePlayer.sv";
    uploadSave();
}
Player::~Player() {}

void Player::setFruction(Fruction fruction) { this->fruction = fruction; }
void Player::saveFruction() { this->sFruction = fruction; }
void Player::setName(std::string name) { this->name = name; }
void Player::setPath(std::string path) { this->path = path; }

Fruction Player::getFruction() { return fruction; }
Fruction Player::getSaveFruction() { return this->sFruction; }
std::string Player::getName() { return name; }
std::string Player::getPath() { return path; }

void Player::uploadSave()
{
    std::fstream saveFile(path);
    std::string param;
    saveFile.close();
    if (saveFile.is_open())
    {
        getline(saveFile, param, '|');
        if (param == "" or param.empty())
        {
            loadSave();
        }
        name = param;
        getline(saveFile, param, '|');
        fruction = Fruction(std::stoi(param));
        getline(saveFile, param, '|');
        sFruction = Fruction(std::stoi(param));
    }
    else
    {
        loadSave();
    }
}

void Player::loadSave()
{
    std::ofstream saveFile(path);
    name = "Player";
    fruction = Fruction::NEUTRAL;
    sFruction = Fruction::NEUTRAL;
    saveFile << name + "|" + std::to_string(fruction) + "|" + std::to_string(sFruction) + "|";
}