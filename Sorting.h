#pragma once
#include <iostream>
#include <random>
namespace mySort
{
	template <typename T>void Quicksort(T* m_Arr, int start, int end);
	template<typename T>void Swap(T*m_Arr,int i1,int i2);
	template <typename T> T* randomArrayGenerator(T low,T high,size_t size);


}
