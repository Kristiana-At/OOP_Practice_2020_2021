#pragma once
#include "String.h"
#include "Deck.h"
#include "WaterCard.h"
#include "FireCard.h"
#include "WindCard.h"
#include "EarthCard.h"
#include <fstream>
#include<iostream>
#include<cstring>

template <typename T, typename S >
class Player
{
private:
	String name;
	size_t wins = 0;
	size_t losses = 0;
	Deck<T> deck1;
	Deck<S> deck2;
public:
	//Player();
	void setName(String newName);
	String getName()const;
	void setWins(size_t newWins);
	size_t getWins() const;
	void setLosses(size_t newStrength);
	size_t getLosses() const;
	void setDeck1(Deck<T> newDeck1);
	Deck<T> getDeck1()const;
	void setDeck2(Deck<S> newDeck2);
	Deck<S> getDeck2()const;
	T drawCardFromDeck1();
	S drawCardFromDeck2();
	int drawCard(T& otherT, S& otherS);
	void savePlayer(String playerName) const;
	Player& loadPlayer(String playerName);
	Vector<String> readerHelper(std::ifstream& file);
	Vector<size_t> takeDigitsFromFile(Vector<String> linesFromFile);
	Deck<WaterCard> loadDeckWater(String fileName);
	Deck<FireCard> loadDeckFire(String fileName);
	Deck<EarthCard> loadDeckEarth(String fileName);
	Deck<WindCard> loadDeckWind(String fileName);
	void printPlayer();
};

template <typename T, typename S>
void Player<T, S>::setName(String newName)
{
	this->name = newName;
}
template <typename T, typename S>
String Player<T, S>::getName() const
{
	return this->name;
}
template <typename T, typename S>
void Player<T, S>::setWins(size_t newWins)
{
	this->wins = newWins;
}
template <typename T, typename S>
size_t Player<T, S>::getWins()const
{
	return this->wins;
}
template <typename T, typename S>
void Player<T, S>::setLosses(size_t newLosses)
{
	this->losses = newLosses;
}
template <typename T, typename S>
size_t Player<T, S>::getLosses()const
{
	return this->losses;
}

template <typename T, typename S>
void Player<T, S>::setDeck1(Deck<T> newDeck1)
{
	this->deck1 = newDeck1;
}

template <typename T, typename S>
Deck<T> Player<T, S>::getDeck1()const
{
	return this->deck1;
}

template <typename T, typename S>
void Player<T, S>::setDeck2(Deck<S> newDeck2)
{
	this->deck2 = newDeck2;
}

template <typename T, typename S>
Deck<S> Player<T, S>::getDeck2()const
{
	return this->deck2;
}

template <typename T, typename S>
T Player<T, S>::drawCardFromDeck1()
{
	return deck1.drawCard();
}

template <typename T, typename S>
S Player<T, S>::drawCardFromDeck2()
{
	return deck2.drawCard();
}

template <typename T, typename S>
int Player<T, S>::drawCard(T& otherT, S& otherS)
{
	int t[2] = { 1,2 }; //1 for the first deck and 2 for the second one
	int index = rand() % (2); //get 0 or 1
	if (t[index] == 1)
	{
		otherT = drawCardFromDeck1();
	}
	else
	{
		otherS = drawCardFromDeck2();
	}
	return t[index]; // by that number I will know whick card to use in the game;
}

template <typename T, typename S>
void Player<T, S>::savePlayer(String playerName) const
{
	playerName += ".txt";

	std::ofstream file(playerName.getString());
	if (file.is_open())
	{
		file << this->name.getString() << std::endl;
		file << this->wins << std::endl;
		file << this->losses << std::endl;
		file << std::endl;
		file.close();
	}
	else
	{
		std::cout << "Error!";
	}
}

template <typename T, typename S>
Vector<String> Player<T, S>::readerHelper(std::ifstream& file) // returns a vector containing each line of the text file as a String
{
	Vector<String> allLines;
	String currentLine;
	currentLine.setString("");
	char c; //each symbol of the text file

	/*
	//count lines of file
	int numberOfLines = 0;
	while (file.get(c))
	{
		//c = file.get();
		if (c == '\n')
			numberOfLines++;
	}*/

	int numberOfLines = 0;
	while (file.get(c))
	{
		if (c != '\n')
		{
			currentLine.add(c);
		}
		else
		{
			allLines.push_back(currentLine);
			currentLine.setString("");
			numberOfLines++;
		}
	}

	return allLines;
}

template <typename T, typename S>
Vector<size_t> Player<T, S>::takeDigitsFromFile(Vector<String> linesFromFile) //Returns a vector containing all digits from the file
{
	Vector<size_t> digitLine;
	for (size_t i = 0;i < linesFromFile.getSize();i++)
	{
		if ((i % 4) != 0)
		{
			digitLine.push_back((size_t)(atoi(linesFromFile[i].getString()))); // atoi converts const char* to int and then I cast it to size_t
		}
	}
	return digitLine;
}

template <typename T, typename S>
Player<T, S>& Player<T, S>::loadPlayer(String playerName)
{
	playerName += ".txt";
	std::ifstream file(playerName.getString());

	if (file.is_open())
	{

		Vector<String> allLines = readerHelper(file);
		//Vector<size_t> digitLine = takeDigitsFromFile(allLines); //= takeDigitsFromFile(playerName);		
		//int indexOfDeck1, indexOfDeck2;
		this->name = allLines[0];
		this->wins = atoi(allLines[1].getString());
		this->losses = atoi(allLines[2].getString());

		//std::cout << this->name << std::endl;
		//std::cout << this->wins << std::endl;
		//std::cout << this->losses << std::endl;
		
		/*switch (indexOfDeck1)
		{
		case 1: this->deck1 = readDeck1Water(indexOfDeck1, allLines);
			break;
		case 2: this->deck1 = readDeck1Fire(indexOfDeck1, allLines);
			break;
		case 3: this->deck1 = readDeck1Earth(indexOfDeck1, allLines);
			break;
		case 4: this->deck1 = readDeck1Wind(indexOfDeck1, allLines);
			break;
		}
		switch (indexOfDeck2)
		{
		case 1: this->deck2 = readDeck1Water(indexOfDeck2, allLines);
			break;
		case 2: this->deck2 = readDeck1Fire(indexOfDeck2, allLines);
			break;
		case 3: this->deck2 = readDeck1Earth(indexOfDeck2, allLines);
			break;
		case 4: this->deck2 = readDeck1Wind(indexOfDeck2, allLines);
			break;
		}*/
		file.close();
	}
	else
	{
		std::cout << "Error loading player!" << std::endl;
	}
	return *this;
}

template <typename T, typename S>
Deck<WaterCard> Player<T, S> ::loadDeckWater(String fileName)
{
	Deck<WaterCard> deck;

	fileName += ".txt";
	std::ifstream file(fileName.getString());

	if (file.is_open())
	{
		Vector<String> allLines = readerHelper(file);

		WaterCard card;
		for (size_t i = 4, k = 5, j = 6, m = 7; m < allLines.getSize(); i += 4, k += 4, j += 4, m += 4)
		{
			if (atoi(allLines[k].getString()) == 1)
			{
				card.setName(allLines[i]);
				card.setStrength((size_t)atoi(allLines[j].getString()));
				card.setBonusStrength((size_t)atoi(allLines[m].getString()));
				deck.addCard(card);
			}
		}
		file.close();
	}
	else
	{
		std::cout << "Error loading Water deck" << std::endl;
	}
	return deck;
}

template <typename T, typename S>
Deck<FireCard> Player<T, S> ::loadDeckFire(String fileName)
{
	Deck<FireCard> deck;

	fileName += ".txt";
	std::ifstream file(fileName.getString());

	if (file.is_open())
	{
		Vector<String> allLines = readerHelper(file);

		FireCard card;
		for (size_t i = 4, k = 5, j = 6, m = 7; m < allLines.getSize(); i += 4, k += 4, j += 4, m += 4)
		{
			if (atoi(allLines[k].getString()) == 1)
			{
				card.setName(allLines[i]);
				card.setStrength((size_t)atoi(allLines[j].getString()));
				card.setBonusStrength((size_t)atoi(allLines[m].getString()));
				deck.addCard(card);
			}
		}
		file.close();
	}
	else
	{
		std::cout << "Error loading Fire deck" << std::endl;
	}
	return deck;
}

template <typename T, typename S>
Deck<EarthCard> Player<T, S> ::loadDeckEarth(String fileName)
{
	Deck<EarthCard> deck;

	fileName += ".txt";
	std::ifstream file(fileName.getString());

	if (file.is_open())
	{
		Vector<String> allLines = readerHelper(file);

		EarthCard card;
		for (size_t i = 4, k = 5, j = 6, m = 7; m < allLines.getSize(); i += 4, k += 4, j += 4, m += 4)
		{
			if (atoi(allLines[k].getString()) == 1)
			{
				card.setName(allLines[i]);
				card.setStrength((size_t)atoi(allLines[j].getString()));
				card.setBonusStrength((size_t)atoi(allLines[m].getString()));
				//card.print();
				deck.addCard(card);
			}
		}
		file.close();
	}
	else
	{
		std::cout << "Error loading Earth deck" << std::endl;
	}
	return deck;
}

template <typename T, typename S>
Deck<WindCard> Player<T, S> ::loadDeckWind(String fileName)
{
	Deck<WindCard> deck;

	fileName += ".txt";
	std::ifstream file(fileName.getString());

	if (file.is_open())
	{
		Vector<String> allLines = readerHelper(file);

		WindCard card;
		for (size_t i = 4, k = 5, j = 6, m = 7; m < allLines.getSize(); i += 4, k += 4, j += 4, m += 4)
		{
			if (atoi(allLines[k].getString()) == 1)
			{
				card.setName(allLines[i]);
				card.setStrength((size_t)atoi(allLines[j].getString()));
				card.setBonusStrength((size_t)atoi(allLines[m].getString()));
				deck.addCard(card);
			}
		}
		file.close();
	}
	else
	{
		std::cout << "Error loading Wind deck" << std::endl;
	}
	return deck;
}

template <typename T, typename S>
void  Player<T, S>::printPlayer()
{
	std::cout << this->name << std::endl;
	std::cout << this->wins << std::endl;
	std::cout << this->losses << std::endl;
	std::cout << "DECK 1" << std::endl;
	std::cout << deck1.getCards();
	std::cout << "DECK 2" << std::endl;
	std::cout << deck2.getCards();
}
