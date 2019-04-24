// Code written by Bordeanu Calin

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <algorithm>
#include <random>
#include <string>

#define WIDTH  1200
#define HEIGHT 850

struct Obiect
{
	sf::RectangleShape forma;
	int marime;
};

void DrawObjects(Obiect obiecte[], sf::RenderWindow &window, int n)
{
	for (int j = 0; j < n; ++j) {
		window.draw(obiecte[j].forma);
	}
}

void SwapObjects(Obiect &a, Obiect &b)
{
	float aux = a.forma.getPosition().y;
	float sizeAux = a.forma.getSize().y;
	a.forma.setPosition(sf::Vector2f(a.forma.getPosition().x, b.forma.getPosition().y));
	a.forma.setSize(sf::Vector2f(a.forma.getSize().x, b.forma.getSize().y));
	b.forma.setPosition(sf::Vector2f(b.forma.getPosition().x, aux));
	b.forma.setSize(sf::Vector2f(b.forma.getSize().x, sizeAux));

	int auxMarime = a.marime;
	a.marime = b.marime;
	b.marime = auxMarime;
}

void Shuffle(Obiect obiecte[], int n, sf::RenderWindow &window, sf::Text &sortText, sf::Text infoText, int delay)
{
	sortText.setString("Shuffling");
	srand(time(0));
	for (int i = 0; i < n; ++i) {
		Sleep(delay);
		int random = rand() % (n-1);
		SwapObjects(obiecte[i], obiecte[random]);

		window.clear();
		DrawObjects(obiecte, window, n);
		window.draw(sortText);
		window.draw(infoText);
		window.display();
	}
	sortText.setString("Shuffled");
}

void BubbleSort(Obiect obiecte[], int n, sf::RenderWindow &window, sf::Text &sortText, sf::Text infoText, int delay)
{
	sortText.setString("Bubble\nSort");
	bool sortat = false;

	while (!sortat) {
		sortat = true;
		for (int i = 0; i < n - 1; ++i) {
			obiecte[i + 1].forma.setFillColor(sf::Color(0, 255, 0));
			obiecte[i].forma.setFillColor(sf::Color(255, 0, 0));
			Sleep(delay);
			if (obiecte[i].marime > obiecte[i + 1].marime) {
				SwapObjects(obiecte[i], obiecte[i + 1]);
				sortat = false;
			}

			window.clear();
			DrawObjects(obiecte, window, n);
			window.draw(sortText);
			window.draw(infoText);
			window.display();

			obiecte[i].forma.setFillColor(sf::Color(255, 255, 255));
			obiecte[i + 1].forma.setFillColor(sf::Color(255, 255, 255));

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				sortText.setString("Stopped");
				return;
			}
		}
	}
	sortText.setString("Sorted");
}

void InsertionSort(Obiect obiecte[], int n, sf::RenderWindow &window, sf::Text &sortText, sf::Text infoText, int delay)
{
	sortText.setString("Insertion\nSort");
	bool gata = false;
	int c = 1;
	while (c != n) {
		gata = false;
		for (int i = c; i > 0 && !gata; --i) {
			obiecte[i].forma.setFillColor(sf::Color(0, 255, 0));
			Sleep(delay);

			if (obiecte[i].marime < obiecte[i - 1].marime) {
				SwapObjects(obiecte[i], obiecte[i - 1]);
				obiecte[i - 1].forma.setFillColor(sf::Color(255, 0, 0));
			}
			else {
				++c;
				gata = true;
			}

			window.clear();
			DrawObjects(obiecte, window, n);
			window.draw(sortText);
			window.draw(infoText);
			window.display();
			obiecte[i].forma.setFillColor(sf::Color(255, 255, 255));
			obiecte[i - 1].forma.setFillColor(sf::Color(255, 255, 255));

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				sortText.setString("Stopped");
				return;
			}
		}
	}
	sortText.setString("Sorted");
}

void CocktailSort(Obiect obiecte[], int n, sf::RenderWindow &window, sf::Text &sortText, sf::Text infoText, int delay)
{
	sortText.setString("Bubble\nSort");
	bool sortat = false;

	while (!sortat) {
		sortat = true;
		for (int i = 0; i < n - 1; ++i) {
			obiecte[i + 1].forma.setFillColor(sf::Color(0, 255, 0));
			obiecte[i].forma.setFillColor(sf::Color(255, 0, 0));
			Sleep(delay);
			if (obiecte[i].marime > obiecte[i + 1].marime) {
				SwapObjects(obiecte[i], obiecte[i + 1]);
				sortat = false;
			}

			window.clear();
			DrawObjects(obiecte, window, n);
			window.draw(sortText);
			window.draw(infoText);
			window.display();

			obiecte[i].forma.setFillColor(sf::Color(255, 255, 255));
			obiecte[i + 1].forma.setFillColor(sf::Color(255, 255, 255));

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				sortText.setString("Stopped");
				return;
			}
		}
		if (!sortat) {
			for (int i = n-1; i > 0; --i) {
				obiecte[i - 1].forma.setFillColor(sf::Color(0, 255, 0));
				obiecte[i].forma.setFillColor(sf::Color(255, 0, 0));
				Sleep(delay);
				if (obiecte[i].marime < obiecte[i - 1].marime) {
					SwapObjects(obiecte[i], obiecte[i - 1]);
					sortat = false;
				}

				window.clear();
				DrawObjects(obiecte, window, n);
				window.draw(sortText);
				window.draw(infoText);
				window.display();

				obiecte[i].forma.setFillColor(sf::Color(255, 255, 255));
				obiecte[i - 1].forma.setFillColor(sf::Color(255, 255, 255));

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
					sortText.setString("Stopped");
					return;
				}
			}
		}
	}
	sortText.setString("Sorted");
}

void SelectionSort(Obiect obiecte[], int n, sf::RenderWindow &window, sf::Text &sortText, sf::Text infoText, int delay)
{
	sortText.setString("Selection\nSort");
	int c = 0;
	while (c != n) {
		int min = obiecte[c].marime;
		int pos = c;
		obiecte[c].forma.setFillColor(sf::Color(0, 255, 0));
		for (int i = c + 1; i < n; i++) {
			obiecte[i].forma.setFillColor(sf::Color(255, 0, 0));

			Sleep(delay);
			if (obiecte[i].marime < min) {
				min = obiecte[i].marime;
				obiecte[pos].forma.setFillColor(sf::Color(255, 255, 255));
				pos = i;
				obiecte[pos].forma.setFillColor(sf::Color(255, 0, 0));
			}

			window.clear();
			DrawObjects(obiecte, window, n);
			window.draw(sortText);
			window.draw(infoText);
			window.display();

			obiecte[i].forma.setFillColor(sf::Color(255, 255, 255));

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				sortText.setString("Stopped");
				return;
			}
		}
		SwapObjects(obiecte[c], obiecte[pos]);
		obiecte[c].forma.setFillColor(sf::Color(255, 255, 255));
		c++;
	}
	sortText.setString("Sorted");
}

void Init(Obiect obiecte[], int n) 
{
	for (int i = 0; i < n; ++i) {
		obiecte[i].forma.setFillColor(sf::Color(255, 255, 255));
		obiecte[i].forma.setSize(sf::Vector2f(15, 10*i+50));
		obiecte[i].forma.setPosition(sf::Vector2f(20*i+20, HEIGHT - obiecte[i].forma.getSize().y));
		obiecte[i].marime = i;
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Sorting Visualiser", sf::Style::Close);
	
	const int n = 55;
	int delay = 10;
	Obiect obiecteDeSortat[n];
	Init(obiecteDeSortat, n);

	sf::Text sortText;
	sf::Text infoText;
	sf::Font font;
	font.loadFromFile("arial.ttf");
	
	sortText.setString("Sorted");
	sortText.setPosition(sf::Vector2f(WIDTH - 150, 10));
	sortText.setFillColor(sf::Color(255, 255, 255));
	sortText.setFont(font);

	infoText.setString("Space - Shuffle       K - Enable console commands\nB - Bubble Sort\nI - Insertion Sort\nC - Cocktail Sort\nX - Selection Sort");
	infoText.setPosition(sf::Vector2f(10, 10));
	infoText.setFillColor(sf::Color(255, 255, 255));
	infoText.setFont(font);

	std::cout << "Type help to list all commands\n";
	std::cout << "Type done to exit the console\n";

	bool sortat = false;
	while (window.isOpen()) {
		sf::Event listenForActions;
		if (window.pollEvent(listenForActions)) {
			if (listenForActions.type == sf::Event::Closed) 
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) 
				Shuffle(obiecteDeSortat, n, window, sortText, infoText, 20);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) 
				BubbleSort(obiecteDeSortat, n, window, sortText, infoText, delay);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) 
				InsertionSort(obiecteDeSortat, n, window, sortText, infoText, delay);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
				CocktailSort(obiecteDeSortat, n, window, sortText, infoText, delay);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
				SelectionSort(obiecteDeSortat, n, window, sortText, infoText, delay);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
				while (true) {
					std::cout << "Command: ";
					std::string s; std::cin >> s;
					if (s == "getdelay") std::cout << delay << "ms\n";
					else if (s == "setdelay") {
						int x; std::cin >> x;
						if (x < 0) x = 0;
						delay = x;
					}
					else if (s == "help") {
						std::cout << "getdelay\nsetdelay (x)\ndone\nhelp\nexit\n";
					}
					else if (s == "done") {
						window.requestFocus();
						break;
					}
					else if (s == "exit") return 0;
					else std::cout << "Unknown command\n";
				}
			}
		}
		
		window.clear();
		DrawObjects(obiecteDeSortat, window, n);
		window.draw(sortText);
		window.draw(infoText);
		window.display();
	}
}