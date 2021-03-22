#include <iostream>
#include "String.h"

int main()
{
	String s1;
	s1.setString("Kristiana");
	std::cout << "string s1: ";
	s1.print();
	std::cout << std::endl;

	//test getLength()
	std::cout << "the length of s1: " << s1.getLength() << std::endl;
	std::cout << std::endl;

	//test add(char symbol)
	s1.add('9');
	std::cout << "add 9 : ";
	s1.print();
	std::cout << std::endl;

	//test insertAt(size_t index, char symbol)
	s1.insertAt(2, 'O');
	std::cout << "add 'O' on index 2: ";
	s1.print();
	std::cout << std::endl;

	//test removeAt(size_t index)
	s1.removeAt(2);
	std::cout << "removed symbol on index 2: ";
	s1.print();
	std::cout << std::endl;

	//test trimStart();
	s1.trimStart();
	std::cout << "removed first element: ";
	s1.print();
	std::cout << std::endl;

	//test trimEnd();
	s1.trimEnd();
	std::cout << "removed last element: ";
	s1.print();
	std::cout << std::endl;

	//test trimStart(size_t numberOfElementsToRemove)
	s1.trimStart(2);
	std::cout << "removed first 2 element: ";
	s1.print();
	std::cout << std::endl;

	//test trimEnd(size_t numberOfElementsToRemove)
	s1.trimEnd(2);
	std::cout << "removed last 2 element: ";
	s1.print();
	std::cout << std::endl;

	//test operator +
	String s3 = s1 + "DOYOUWORK";
	std::cout << "+ DOYOUWORK: ";
	s3.print();
	std::cout << std::endl;

	//test operator + for string
	String s2;
	s2.setString("TEST");
	s3 = s2 + s1;
	std::cout << "TEST +: ";
	s3.print();
	std::cout << std::endl;

	//test operator +=
	s2 += s1;
	std::cout << "+=: ";
	s2.print();
	std::cout << std::endl;

	//test operator ==
	std::cout << "==: " << (s1 == s2) << std::endl;
	std::cout << std::endl;

	//test operator !=
	std::cout << "!=: " << (s1 != s2) << std::endl;
	std::cout << std::endl;

	//test operator []
	std::cout << "[0]: " << s1[0] << std::endl;
	std::cout << std::endl;
}
