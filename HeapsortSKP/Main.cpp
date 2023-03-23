#include <iostream>
#include <vector>


int MyHeapsort(std::vector<int >&ToSort)
{

	int buf=0;
	for (size_t i = ToSort.size() - 1; i > 0; --i)
	{
		if (ToSort[i] > ToSort[i / 2])
		{
			 buf = ToSort[i];
			ToSort[i] = ToSort[i / 2];
			ToSort[i / 2] = buf;
		}
	}
	 buf = ToSort[0];
	ToSort.erase(ToSort.begin() + 0);
	return buf;

}
int main()
{
	int k;
	std::cin >> k;
	std::vector<int>Buffer;
	std::vector<std::vector<int>>Result;
	
	Result.reserve(k);
	for (size_t i =0; i <k; ++i)
	{
		Buffer.clear();
		int size;
		std::cin >> size;
		Buffer.reserve(size);
		for (size_t j = 0; j < size; ++j)
		{
			int buffer = 0;
		std::cin >> buffer;
		Buffer.push_back(buffer);

		}
		std::vector<int>Sorted;
		Sorted.reserve(size);

		for (size_t j = 0; j < size; ++j)
		{
			int start = MyHeapsort(Buffer);
			Sorted.push_back(start);
			std::cout << start << " ";
			for (auto& i : Buffer)
			{
				std::cout << i << " ";
			}
			std::cout << std::endl;
		}
		Result.push_back(Sorted);
		Sorted.clear();

	}
	for (auto& i : Result)
	{
		for (auto& j : i)
		{
			std::cout << j << " ";
			}
		std::cout << std::endl;
	
	}
	
std::cin.get();
}
