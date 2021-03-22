#include <iostream>
#include "Complex.h"
int main()
{
	Complex c1(7, -6);
	Complex c2(2, -3);
	Complex c3(7, 4);

	Complex rememberC1 = c1;
	Complex rememberC2 = c2;
	Complex rememberC3 = c3;

	//test + and +=
	std::cout << "(7, -6) +  (2, -3) = ";
	Complex testPlus;
	testPlus = c1 + c2;
	testPlus.print();

	std::cout << "(7, -6) += (2, -3) = ";
	c1 += c2;
	c1.print();
	std::cout << std::endl;
	c1 = rememberC1;
	c2 = rememberC2;

	//test - and -=
	std::cout << "(7, -6) -  (2, -3) = ";
	Complex testMinus;
	testMinus = c1 - c2;
	testMinus.print();

	std::cout << "(7, -6) -= (2, -3) = ";
	c1 -= c2;
	c1.print();
	std::cout << std::endl;
	c1 = rememberC1;
	c2 = rememberC2;

	//test * and */
	std::cout << "(7, -6) *  (2, -3) = ";
	Complex testMult;
	testMult = c1 * c2;
	testMult.print();
	
	std::cout << "(7, -6) *= (2, -3) = ";
	c1 *= c2;
	c1.print();
	std::cout << std::endl;
	c1 = rememberC1;
	c2 = rememberC2;

	//test / and /=
	std::cout << "(7, 4) /  (2, -3) = ";
	Complex testDivide;
	testDivide = c3 / c2;
	testDivide.print();

	std::cout << "(7, 4) /= (2, -3) = ";
	c3 /= c2;
	c3.print();
	std::cout << std::endl;
	c3 = rememberC3;
	c2 = rememberC2;

	//test >=
	std::cout << "Is (7,4) >= (2,-3) : " << (c3 >= c2) << std::endl;

	//test <=
	std::cout << "Is (7,4) <= (2,-3) : " << (c3 <= c2) << std::endl;
	std::cout << std::endl;

	//test ==
	Complex c4 = c3;
	std::cout << "Is (7,4) == (7,4) : " << (c4 == c3) << std::endl;

	//test !=
	std::cout << "Is (7,4) != (7,4) : " << (c4 != c3) << std::endl;


}

