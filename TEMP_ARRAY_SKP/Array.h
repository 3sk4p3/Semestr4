#pragma once
#include <iostream>
#include <fstream>
#include <random>

template <typename T> class myClass
{

public:
	myClass(myClass<T>& mc);
	myClass(size_t _size);
	myClass();
	~myClass();
	void ShowArr();
	inline const T& operator[](size_t idx) const { return m_Insides[idx]; }
	inline  T& operator[](size_t idx) { return m_Insides[idx]; }
	void SeedWithRandomNumbers(int min,int max);
	void ReadFromFile(std::string name);
private:
	size_t m_Size;
	T* m_Insides;
	T& operator=(T&& other) noexcept;




};
