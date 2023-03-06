#include "Sorting.cpp"
const int Arr_Size = 25;
int main()
{
	double* m_Arr = mySort::randomArrayGenerator<double>(1.0f, 11.5f, Arr_Size);
	mySort::Quicksort<double>(m_Arr, 0, Arr_Size-1);
	std::cout << "Sorted Array:\n";
	for (size_t i = 0; i < Arr_Size; ++i)
	{
		std::cout << m_Arr[i] << " ";
	}


	//nie jestem do konca pewny czy dobrze to usuwam?
	delete[]m_Arr;
	std::cin.get();
}