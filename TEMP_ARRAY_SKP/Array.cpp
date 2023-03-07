#pragma once
#include "Array.h"
template<typename T>
myClass<T>::myClass( myClass<T>& mc)
{
	*this = mc;
}
template<typename T>
inline myClass<T>::myClass(size_t _size)
	:m_Size(_size)
{
	m_Insides = new T[_size];
}

template<typename T>
myClass<T>::myClass()
	:m_Insides(nullptr),m_Size(0)
{

}

template<typename T>
myClass<T>::~myClass()
{
	if (m_Insides != nullptr)delete[] m_Insides;
}

template<typename T>
void myClass<T>::ShowArr()
{
	for (size_t i = 0; i < m_Size; ++i)
	{
		std::cout << m_Insides[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void myClass<T>::SeedWithRandomNumbers(int min, int max)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_real_distribution<float> dist6(min, max);
	for (size_t i = 0; i < m_Size; ++i)
	{
		m_Insides[i] = static_cast<T>(dist6(rng));
	}

}

template<typename T>
void myClass<T>::ReadFromFile(std::string name)
{
	std::ifstream In(name);
	if (In.is_open())
	{

		In >> m_Size;
		if (m_Size < 1)throw " ...";
		m_Insides = new T[m_Size];
		for (size_t i = 0; i < m_Size; ++i)
		{
			In >> m_Insides[i];
		}
		In.close();
	}
	else std::cout << "nie udalo sie otworzyc pliku" << std::endl;
}

template<typename T>
T& myClass<T>::operator=(T&& other) noexcept
 {
	if (this == &other)
		return *this;

	delete[] m_Insides;
	m_Insides = exchange(other.m_Insides, nullptr);
	m_Size = exchange(other.m_Size, 0);
	return *this;
}
