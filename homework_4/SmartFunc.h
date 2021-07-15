#pragma once
#include "Vector.h"
#include <functional>

template<typename T>
using funcPtrMap = void(*)(T&);

template<typename T>
using funcPtrFilter = bool(*)(T&);

template<typename T>
using funcPtrReduce = T(*)(Vector<T>&);

template<typename T>
struct SmartFunc
{
private:
	void (*mapPtr)(T&);         //pointer to a function that makes changes to an element
	bool (*filterPtr)(T&);      //pointer to a function which checks if an element fulfils some requirements
	T (*reducePtr)(Vector<T>&); //pointer to a function which makes some operation to the elements of a vector

public:
	void setMap(funcPtrMap<T> newFunc);
	void useMap(Vector<T>& vec);

	void setFilter(funcPtrFilter<T> newFuncBool);
	Vector<T> useFilter(Vector<T>& vec);

	void setReduce(funcPtrReduce<T> newFuncReduce);
	T useReduce(Vector<T>& vec);

	Vector<T> useFilterWithMap(Vector<T>& vec, funcPtrFilter<T> funcFilter, funcPtrMap<T> funcMap);   //filt a vector then map 
	T useFilterWithReduce(Vector<T>& vec, funcPtrFilter<T> funcFilter, funcPtrReduce<T> funcFilt);//filt a vector then reduce
	T useMapWithReduce(Vector<T>& vec, funcPtrMap<T> funcMap, funcPtrReduce<T> funcFilt);  //Map a vector then reduce
};



template<typename T>
void SmartFunc<T>::setMap(funcPtrMap<T> newFunc)
{
	this->mapPtr = newFunc;
}

template<typename T>
void SmartFunc<T>::useMap(Vector<T>& vec)
{

	size_t vecSize = vec.getSize();
	for (size_t i = 0; i < vecSize; i++)
	{
		this->mapPtr(vec[i]);
	}

}

template<typename T>
void SmartFunc<T>::setFilter(funcPtrFilter<T> newFuncBool)
{
	this->filterPtr = newFuncBool;
}

template<typename T>
Vector<T> SmartFunc<T>::useFilter(Vector<T>& vec)
{
	Vector<T> filtered;

	size_t vecSize = vec.getSize();
	for (size_t i = 0; i < vecSize; i++)
	{
		if (this->filterPtr(vec[i]))
		{
			filtered.push_back(vec[i]);
		}
	}

	return filtered;
}

template<typename T>
void SmartFunc<T>::setReduce(funcPtrReduce<T> newFuncReduce)
{
	this->reducePtr = newFuncReduce;
}

template<typename T>
T SmartFunc<T>::useReduce(Vector<T>& vec)
{
	T result = reducePtr(vec);
	return result;
}

template<typename T>
Vector<T> SmartFunc<T>::useFilterWithMap(Vector<T>& vec, funcPtrFilter<T> funcFilter, funcPtrMap<T> funcMap)
{
	Vector<T> afterFilter = useFilter(vec);
	useMap(afterFilter);
	return afterFilter;
}

template<typename T>
T SmartFunc<T>::useFilterWithReduce(Vector<T>& vec, funcPtrFilter<T> funcFilter, funcPtrReduce<T> funcFilt)
{
	Vector<T> afterFilter = useFilter(vec);
	return useReduce(afterFilter);
}

template<typename T>
T SmartFunc<T>::useMapWithReduce(Vector<T>& vec, funcPtrMap<T> funcMap, funcPtrReduce<T> funcFilt)
{
	useMap(vec);
	return useReduce(vec);
}