#pragma once
#include <iostream>

class String
{
private:
	char* string;
	//size_t size;
	//size_t capacity;

	void copy(const String& other);
	void erase();

	//void resizeUp();
	//void resizeDown();

public:
	String();
	String(const String& other);
	String& operator=(const String& other);
	~String();

	void print() const;
	void setString(const char* newString);
	const char* getString()const;

	//void setSize(size_t newSize);
	//size_t getSize() const;
	//void setCapacity(size_t newCapacity);
	//size_t getCapacity() const;

	String& add(char symbol);
	size_t getLength() const;
	String& insertAt(size_t index, char symbol);
	String& removeAt(size_t index);
	void trimStart();
	void trimEnd();
	void trimStart(size_t numberOfElementsToRemove);
	void trimEnd(size_t numberOfElementsToRemove);
	String operator+(const String& other);
	String operator+(const char* other);
	String& operator+=(const String& other);
	String& operator+=(const char* other);
	bool operator==(const String& other);
	bool operator!=(const String& other);
	char& operator[](size_t index);
};

