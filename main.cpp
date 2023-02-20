#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Main.hpp>

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <thread>
#include <chrono>
#include <list>
#include <time.h>
#include <string>

#include "main_settings.h"

#include "menuScreen.h"
#include "gameScreen.h"
#include "cardScreen.h"
#include "selectScreen.h"

void uploadData(Decks &deck, Player &player)
{
	deck.init("assets/card.txt", player);
	// deck.info();
}

int main()
{
	setlocale(LC_ALL, "");
	// FreeConsole();
	std::thread th(uploadData, std::ref(decks), std::ref(player));

	sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), "The Gwent");
	window.setFramerateLimit(60);
	sf::View view;
	view.setCenter(window.getSize().x / 2, window.getSize().y / 2);
	int winWidth = screenWidth, winHeight = screenHeight;

	Screen screen = Screen::MENU;

	srand(time(NULL));

	th.join();
	decks.info();

	do
	{
		switch (screen)
		{
		case Screen::MENU:
			std::cout << "\nlog: menu: start in";
			menu::screen(window, view, screen);
			std::cout << "\nlog: menu: out\n";
			break;
		case Screen::GAME:
			std::cout << "\nlog: game: start in";
			game::screen(window, view, screen);
			std::cout << "\nlog: game: out\n";
			break;
		case Screen::CARD:
			std::cout << "\nlog: card: start in";
			card::screen(window, view, screen);
			std::cout << "\nlog: card: out\n";
			break;
		case Screen::SELECT:
			std::cout << "\nlog: card: start in";
			fruct::screen(window, view, screen);
			std::cout << "\nlog: card: out\n";
			break;
		}
	} while (screen != Screen::END);
	decks.info();

	decks.~Decks();
	std::cout << "\nlog: end process";

	return 0;
}