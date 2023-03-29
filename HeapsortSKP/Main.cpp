#include <iostream>
#include <vector>


void Heapify(std::vector<int>&Arr, int idx,int max)
{
	int left = 2 * idx+1;
	int right = 2 * idx + 2;
	int largest = 0;
	if (left < max && Arr[left] > Arr[idx])largest = left;
	else largest = idx;
	if (right < max && Arr[right] > Arr[largest])largest = right;
	if (largest != idx)
	{
		int buf = Arr[idx];
		Arr[idx] = Arr[largest];
		Arr[largest] = buf;
		Heapify(Arr, largest,max);
	}
}std::vector<int> PrintArr(std::vector<int>& Arr, int size,std::vector<int>&Buffer)
{
	Buffer.clear();
	Buffer.push_back(Arr[size]);
	for (size_t i = 0; i <= size-1; ++i)
	{
		Buffer.push_back(Arr[i]);
	}
	return Buffer;
}
void BuildMaxHeap(std::vector<int>&Arr)
{
	for (int i = Arr.size()/2-1; i >= 0;--i)
	{
		Heapify(Arr, i,Arr.size());
	}
}
void Heapsort(std::vector<int>& Arr,std::vector<std::vector<int>>&Result)
{
	BuildMaxHeap(Arr);
	int n = Arr.size()-1;
	int cnt = 0;
	std::vector<int>Buf;
	Buf.clear();
	for (int i = n; i >= 1; --i)
	{
		int buf = Arr[0];
		Arr[0] = Arr[i];
		Arr[i] = buf;
		Heapify(Arr, 0,i);
		Result.push_back(PrintArr(Arr, n - cnt, Buf));
		++cnt;
	}
}


int main()
{
	int k;
	std::cin >> k;

	//wynik danej iteracji
	std::vector<int>Buffer;
	std::vector<std::vector<int>>Result;
	for (size_t i = 0; i < k; ++i)
	{
		int size;
		std::cin >> size;
		Buffer.clear();
		Buffer.resize(size);

		//pisanie do vecgtora
		for (size_t j = 0; j < size; ++j)
		{
			int buffer = 0;
			std::cin >> buffer;
			Buffer[j] = buffer;
		}

		Heapsort(Buffer,Result);
		Result.push_back(Buffer);
	}
	for (auto& i : Result)
	{
		for (auto& j : i)
		{
			std::cout << j<<" ";
		}
		std::cout << std::endl;
	}
	
	std::cin.get();
}
