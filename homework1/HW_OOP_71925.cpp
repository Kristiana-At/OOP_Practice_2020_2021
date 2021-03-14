#include <iostream>
#include "Crypto.h"
#include "Film.h"
#include "FilmRanking.h"

int main()
{
	//Task 1
	std::cout << "TASK 1\n";
	Crypto c1;
	c1.setName("LV");
	c1.setCurrentPrice(1.9);
	c1.setLastPrice(2.0);
	c1.print();
	std::cout << c1.priceDifference() << "%\n" << std::endl;

	//Task 2
	std::cout << "TASK 2\n";
	Film film1, film2, film3, film4, film5;
	film1.print();
	film2.setName("Clue");
	film2.setNumberOfRewards(5);

	film3.setName("Angel of mine");
	film3.setDirectorName("Kim Farrant");
	film3.setNumberOfRewards(4);

	film4.setName("Stoker");
	film4.setNumberOfRewards(2);

	film5.setName("A simple favor");
	film5.setNumberOfRewards(1);
	std::cout << std::endl;

	//Task 3
	std::cout << "TASK 3\n";
	FilmRanking filmsForRanking;
	filmsForRanking.addFilm(film1);
	filmsForRanking.addFilm(film4);
	filmsForRanking.addFilm(film3);
	filmsForRanking.addFilm(film2);
	filmsForRanking.addFilm(film5);
	int n = 3;
	filmsForRanking.printTopRankedFilms(n);
	//std::cout << "current capacity:" << filmsForRanking.getCapacity() << " current size:" << filmsForRanking.getSize() << std::endl;

}

