#include "Sorting.h"

namespace mySort {
	template<typename T>
	void Quicksort(T* m_Arr, int start, int end)
	{
		if (start < end)
		{
			int pivot= start;
			for (size_t i = start+1; i <= end; ++i)
			{
				if (m_Arr[i] < m_Arr[start])
				{
					++pivot;
					mySort::Swap<T>(m_Arr, pivot, i);
				}
			}
			mySort::Swap<T>(m_Arr, pivot,start);
			mySort::Quicksort<T>(m_Arr, start, pivot - 1);
			mySort::Quicksort<T>(m_Arr, pivot+1, end);

		}


	}

	template<typename T>
	void Swap(T* m_Arr, int i1, int i2)
	{
			T buf = m_Arr[i1];
			m_Arr[i1] = m_Arr[i2];
			m_Arr[i2] = buf;
	}

	template<typename T>
	T* randomArrayGenerator(T low, T high, size_t size)
	{

	


		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_real_distribution<double> dist(low, high);
		T* m_Arr = new T[size];
		std::cout << "Generated Array\n";
			for (size_t i = 0; i < size; ++i)
			{

				m_Arr[i] = static_cast<T>(dist(mt));
				std::cout << m_Arr[i] << " ";
			}
		std::cout << std::endl;
		return m_Arr;


	}






}