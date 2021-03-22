#include "String.h"

void String::copy(const String& other)
{
	this->string = new char[strlen(other.string) + 1];
	strcpy_s(this->string, strlen(other.string) + 1, other.string);
	//this->size = other.size;
	//this->capacity = other.capacity;
	//if (this->size < this->capacity)
	//{
	//	for (size_t i = 0;i < size;i++)
		//{
		//	this->string[i] = other.string[i];
	//	}
	//}
}

void String::erase()
{
	delete[] this->string;
}

/*
void String::resizeUp()
{
	this->capacity *= 2;
	char* newString = new char[this->capacity];
	for (size_t i = 0;i < this->size;i++)
	{
		newString[i] = this->string[i];
	}
	erase();
	this->string = newString;
}

void String::resizeDown()
{
	this->capacity /= 2;
	if (this->size < this->capacity)
	{
		char* newString = new char[this->capacity];
		for (size_t i = 0;i < this->size;i++)
		{
			newString[i] = this->string[i];
		}
		this->erase();
		this->string = newString;
	}
}
*/
String::String()
{
	//this->capacity = 16;
	//this->size = 0;
	this->string = new char[8];
	strcpy_s(this->string, 8, "default");
}

String::String(const String& other)
{
	this->copy(other);
}
String& String::operator=(const String& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}
	return *this;
}

String::~String()
{
	this->erase();
}

void String::print() const
{
	std::cout << this->string << std::endl;
	//std::cout << this->size << std::endl;
	//std::cout << this->capacity << std::endl;
}

void String::setString(const char* newString)
{
	if (newString != nullptr)
	{
		delete[] this->string;
		this->string = new char[strlen(newString) + 1];
		strcpy_s(this->string, strlen(newString) + 1, newString);
	}
}
const char* String::getString()const
{
	return this->string;
}

/*
void String::setSize(size_t newSize)
{
	this->size = newSize;
}
size_t String::getSize() const
{
	return this->size;
}

void String::setCapacity(size_t newCapacity)
{
	this->capacity = newCapacity;
}
size_t String::getCapacity() const
{
	return this->capacity;
}
*/
String& String::add(char symbol)
{
	size_t lengthOfString = getLength();
	String newString;
	newString.string = new char[lengthOfString + 2]; // +2 because one for the new element and 1 for the \0 as lengthOfString does not count \0
	strcpy_s(newString.string, lengthOfString + 2, string);
	newString.string[lengthOfString] = symbol;
	newString.string[lengthOfString + 1] = '\0';
	*this = newString;
	return *this;
}

size_t String::getLength() const
{
	return strlen(string);
}

String& String::insertAt(size_t index, char symbol)
{
	if (index < getLength() + 1)
	{
		String newString;
		newString.string = new char[getLength() + 2];
		for (size_t i = 0, j = 0;i < getLength() + 1;i++)
		{
			if (i != index)
			{
				newString.string[i] = this->string[j];
				j++; //if i == index I dont increase j and that is how I do not miss the symbol on the index position
			}
			else
			{
				newString.string[i] = symbol;
			}
		}
		newString.string[getLength() + 1] = '\0';
		*this = newString;
	}
	return *this;

}

String& String::removeAt(size_t index)
{
	if (index < getLength())
	{
		String newString;
		newString.string = new char[getLength() + 1];
		for (size_t i = 0, j = 0;i < getLength();i++)
		{
			if (i != index)
			{
				if (j < getLength() - 1)
				{
					newString.string[j] = this->string[i];
					j++;
				}
			}
		}
		newString.string[getLength() - 1] = '\0';
		*this = newString;
	}
	return *this;
}

String String::operator+(const String& other)
{
	String result;
	result.string = new char[strlen(string) + strlen(other.string) + 1];

	strcpy_s(result.string, strlen(this->string) + strlen(other.string) + 1, this->string);
	strcat_s(result.string, strlen(this->string) + strlen(other.string) + 1, other.string);

	return result;
}

String String::operator+(const char* other) // when we want to combine a variable of type String with char array: s1 + "Something";
{
	String result;
	result.string = new char[strlen(string) + strlen(other) + 1];

	strcpy_s(result.string, strlen(this->string) + strlen(other) + 1, this->string);
	strcat_s(result.string, strlen(this->string) + strlen(other) + 1, other);

	return result;
}

String& String::operator+=(const String& other)
{	
	*this = *this + other;
	return *this;
}

String& String::operator+=(const char* other)
{
	*this = *this + other;
	return *this;
} 

void String::trimStart()
{
	*this = removeAt(0);
}

void String::trimEnd()
{
	*this = removeAt(getLength() - 1);
}

void String::trimStart(size_t numberOfElementsToRemove)
{
	if (numberOfElementsToRemove < getLength() - 1)
	{
		for (size_t i = 0;i < numberOfElementsToRemove;i++)
		{
			trimStart();
		}
	}
}

void String::trimEnd(size_t numberOfElementsToRemove)
{
	if (numberOfElementsToRemove < getLength() - 1)
	{
		for (size_t i = 0;i < numberOfElementsToRemove;i++)
		{
			trimEnd();
		}
	}
}

bool String::operator==(const String& other)
{
	return strcmp(this->string, other.string) == 0;
}

bool String::operator!=(const String& other)
{
	return strcmp(this->string, other.string) != 0;
}

char& String::operator[] (size_t i)
{
	return this->string[i];
}
