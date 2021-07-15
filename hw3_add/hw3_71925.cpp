#include <iostream>
#include "String.h"
#include "Vector.h"
#include "Deck.h"
#include "CardType.h"
#include "WindCard.h"
#include "EarthCard.h"
#include "FireCard.h"
#include "WaterCard.h"
#include "Player.h"

int main()
{
	srand((unsigned int)time(0)); // the shuffled order of the cards to be different each time when we run the program

	WaterCard w1, w2, w3, w4, w5, w6;
	FireCard f1, f2, f3, f4, f5, f6, f7;

	w1.setBonusStrength(8);

	String name;
	name.setString("Krisi");
	f1.setName(name);

	Deck<WaterCard> deck1;
	deck1.addCard(w1);
	deck1.addCard(w2);
	deck1.addCard(w3);
	deck1.addCard(w4);
	deck1.addCard(w5);
	deck1.addCard(w6);

	Deck<FireCard> deck2;
	deck2.addCard(f1);
	deck2.addCard(f2);
	deck2.addCard(f3);
	deck2.addCard(f4);
	deck2.addCard(f5);
	deck2.addCard(f6);
	deck2.addCard(f7);

	//deck1.removeDuplicateCards();
	//deck2.removeDuplicateCards();

	//Realized the game just with the case of having 2 players who have the following decks
	Player<WaterCard, FireCard> player1, player2, player3;

	String playerName1; // initialize by setters
	playerName1.setString("Krisi");
	player1.setName(playerName1);
	player1.setDeck1(deck1);
	player1.setDeck2(deck2);

	String playerName2; // initialize by loading from a file
	playerName2.setString("Ivo");
	player2.loadPlayer(playerName2);
	player2.setDeck1(player2.loadDeckWater(player2.getName()));
	player2.setDeck2(player2.loadDeckFire(player2.getName()));

	String playerName3;
	playerName3.setString("Nicky"); // initialize by loading from a file
	player3.loadPlayer(playerName3);
	player3.setDeck1(player3.loadDeckWater(player3.getName()));
	player3.setDeck2(player3.loadDeckFire(player3.getName()));

	std::cout << "----------PLAYER 1----------" << std::endl;
	player2.printPlayer();
	std::cout << "----------PLAYER 2----------" << std::endl;
	player3.printPlayer();

	std::cout << "----------GAME----------" << std::endl;

	//no more than 30 cards are needed also there must not be duplicate cards
	player2.getDeck1().removeDuplicateCards();
	player2.getDeck1().removeExtraCards();
	player3.getDeck1().removeDuplicateCards();
	player3.getDeck1().removeExtraCards();

	//first I check if both of the decks of both of the players are not empty
	if (!player2.getDeck1().getCards().isEmpty() && !player2.getDeck2().getCards().isEmpty() && !player3.getDeck1().getCards().isEmpty() && !player3.getDeck2().getCards().isEmpty())
	{
		int player1Points = 0, player2Points = 0; //counters for points
		WaterCard card1water, card2water;
		FireCard card1fire, card2fire;

		//shuffling the decks before the game
		player2.getDeck1().shuffle();
		player3.getDeck1().shuffle();
		player2.getDeck2().shuffle();
		player3.getDeck2().shuffle();

		while (player1Points != 5 || player2Points != 5) //on each iteration of the while loop players are drowing cards, drawing until 5points are reached
		{
			int fromDeckPlayer1 = player2.drawCard(card1water, card1fire);
			int fromDeckPlayer2 = player3.drawCard(card2water, card2fire);

			//there are 4 possible matches of the cards of both players
			if (fromDeckPlayer1 == 1 && fromDeckPlayer2 == 1) // == 1, this means that the player drew card from deck 1
			{
				if (card1water.getStrength() > card2water.getStrength())
				{
					player1Points++;
				}
				else if (card1water.getStrength() < card2water.getStrength())
				{
					player2Points++;
				}
			}
			if (player1Points == 5 || player2Points == 5) break; // after each if case I check if 5 points are reached and if so, the game stops

			//if the players drew cards from different decks, in this case with water and fire the cards "contrates"? and we add bonus strength as well
			if (fromDeckPlayer1 == 1 && fromDeckPlayer2 == 2) 
			{
				if (card1water.contraPoints() > card2fire.contraPoints())
				{
					player1Points++;
				}
				else if (card1water.contraPoints() < card2fire.contraPoints())
				{
					player2Points++;
				}
			}
			if (player1Points == 5 || player2Points == 5) break;

			if (fromDeckPlayer1 == 2 && fromDeckPlayer2 == 2)
			{
				if (card1fire.getStrength() > card2fire.getStrength())
				{
					player1Points++;
				}
				else if (card1fire.getStrength() < card2fire.getStrength())
				{
					player2Points++;
				}
			}
			if (player1Points == 5 || player2Points == 5) break;

			if (fromDeckPlayer1 == 2 && fromDeckPlayer2 == 1)
			{
				if (card1fire.contraPoints() > card1water.contraPoints())
				{
					player1Points++;
				}
				else if (card1fire.contraPoints() < card1water.contraPoints())
				{
					player2Points++;
				}
			}
			if (player1Points == 5 || player2Points == 5) break;
		}
		if (player1Points == 5)
		{
			player2.setWins(player2.getWins() + 1);
			player3.setLosses(player3.getLosses() + 1);
			std::cout << player2.getName() << " is the winner!\n\n";
		}
		else if(player2Points == 5)
		{
			player3.setWins(player3.getWins() + 1);
			player2.setLosses(player2.getLosses() + 1);
			std::cout << player3.getName() << " is the winner!\n\n";
		}
	}
	else
	{
	std::cout << "Not enough decks!" << std::endl;
	}

	//saving players to file after the game is finished
	player1.savePlayer(player1.getName());

	for (size_t i = 0;i < player1.getDeck1().getCards().getSize();i++)
	{
		player1.getDeck1().getCards()[i].toFile(playerName1);
	}
	for (size_t i = 0;i < deck2.getCards().getSize();i++)
	{
		player1.getDeck2().getCards()[i].toFile(playerName1);
	}

	player2.savePlayer(player2.getName());

	for (size_t i = 0;i < player2.getDeck1().getCards().getSize();i++)
	{
		player2.getDeck1().getCards()[i].toFile(playerName2);
	}
	for (size_t i = 0;i < player2.getDeck2().getCards().getSize();i++)
	{
		player2.getDeck2().getCards()[i].toFile(playerName2);
	}

	player3.savePlayer(player3.getName());

	for (size_t i = 0;i < player3.getDeck1().getCards().getSize();i++)
	{
		player3.getDeck1().getCards()[i].toFile(playerName3);
	}
	for (size_t i = 0;i < player3.getDeck2().getCards().getSize();i++)
	{
		player3.getDeck2().getCards()[i].toFile(playerName3);
	}

}