#pragma once
#include<iostream>
#include "Vector.h"
#include "WaterCard.h"
#include "WindCard.h"
#include "FireCard.h"
#include "EarthCard.h"
#include "CardType.h"
#include <random>
#include "time.h"

template <typename T> //T = <WaterCard, WindCard, FireCard, EarthCard>
class Deck
{
private:
	Vector<T> cards;
public:
	Vector<T> getCards() const;
	void shuffle();
	Deck<T>& removeExtraCards();
	Deck<T>& removeDuplicateCards();
	T drawCard();
	Deck<T>& addCard(const T& card);
	Deck<T> operator+(const T& card);
	Deck<T>& operator+=(const T& card);
};

template <typename T>
Vector<T> Deck<T> ::getCards() const
{
	return this->cards;
}

template <typename T>
Deck<T>& Deck<T>::removeExtraCards()
{
	size_t size = this->cards.getSize();
	if (size <= 30) // the task requires no more than 30 cards
	{
		return *this;
	}
	while (size != 30)
	{
		cards.pop_back();
		size = this->cards.getSize();
	}
	return *this;
}

template <typename T>
Deck<T>& Deck<T>::removeDuplicateCards() // the task requires the cards to be unique
{
	size_t size = this->cards.getSize();
	for (size_t i = 0; i < size; i++)
	{
		T temp = cards[i];
		for (size_t j = i + 1; j < size; j++)
		{
			if (temp == cards[j])
			{
				cards.pop_at(j);
				size--;
				j--;
			}
		}
	}
	return *this;
}

template <typename T>
void Deck<T>::shuffle()
{
	size_t size = this->cards.getSize();
	if (size >= 30) // the task requires no more than 30 cards
	{
		std::cout << "Invalid deck!" << std::endl;
		return;
	}
	for (size_t i = 0; i < size; i++)
	{
		int random = rand() % size;
		T temp = this->cards[i];
		this->cards[i] = this->cards[random];
		this->cards[random] = temp;
	}
}

template <typename T>
Deck<T>& Deck<T>::addCard(const T& card)
{
	this->cards.push_back(card);
	return *this;
}

template <typename T>
T Deck<T>::drawCard()
{
	T firstCard = this->cards[0];
	this->cards.pop_front();
	this->cards.push_back(firstCard);
	return firstCard;
}

template <typename T>
Deck<T> Deck<T>:: operator+(const T& card)
{
	Deck<T> newDeck;
	newDeck.cards = this->cards + card;
	return newDeck;
}

template <typename T>
Deck<T>& Deck<T>:: operator+=(const T& card)
{
	this->cards += card;
	return *this;
}



