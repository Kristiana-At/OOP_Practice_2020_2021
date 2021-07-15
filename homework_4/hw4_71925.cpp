#include <iostream>
#include "SmartFunc.h"

//three example functions
template<typename T>
void addOne(T& element)
{
	element++;
}

template<typename T>
bool isEven(T& element)
{
	return (element % 2 == 0);
}

template<typename T>
T multAll(Vector<T>& vec)
{
	T a = vec[0];
	size_t vecSize = vec.getSize();
	for (size_t i = 1; i < vecSize; i++)
	{
		a *= vec[i];
	}
	return a;
}

int main()
{
	SmartFunc<int> operate;
	Vector<int> example;
	example.push_back(1);
	example.push_back(3);
	example.push_back(5);
	example.push_back(8);

	std::cout << "original\n" << example;

	Vector<int> filteredExample;
	operate.setFilter(isEven);
	filteredExample = operate.useFilter(example);
	std::cout << "\nfiltered(get only the even elements)\n" << filteredExample;

	int result;
	operate.setReduce(multAll);
	result = operate.useReduce(example);
	std::cout << "\nreduced(multiply all elements)\n" << result << std::endl;

	operate.setMap(addOne);
	operate.useMap(example);
	std::cout << "\nmapped(add 1 to each)\n" << example;

	std::cout << "\nEXAMPLES OF FUNCTION COMBINATIONS (work with the following vector)\n" << example;
	
	Vector<int> filtAndMap = operate.useFilterWithMap(example, isEven, addOne);
	std::cout << "\n1. Filter with map(add 1 to the even elements)\n" << filtAndMap;

	int filtAndReduce = operate.useFilterWithReduce(example, isEven, multAll);
	std::cout << "\n2. Filter with reduce(multiply all even elements)\n" << filtAndReduce << std::endl;

	int mapAndReduce = operate.useMapWithReduce(example, addOne, multAll);
	std::cout << "\n3. Map with reduce(add 1 to each element then multiply them all)\n" << mapAndReduce << std::endl;
}

