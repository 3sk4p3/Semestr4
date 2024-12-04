#include <iostream>
#include <vector>
#include <string>
#include <sstream>
std::vector<std::pair<long, std::string>>HashTable;
std::vector<std::pair<long,long>> OutOfOrder;//wanted,current
std::vector<std::string> CompleteResult;
std::string Result;
int casesNo = 0;
int ArrSize = 0;
int SimpleHash(long _key) {
	while (true)
	{
		if(HashTable[_key%ArrSize].first==NULL)return _key % ArrSize;

		++_key;
	}
}
long DeleteFromMap(long _key)
{
	long idx = _key;
	while (true)
	{
		if (HashTable[idx % ArrSize].first == _key)
		{
			HashTable[idx % ArrSize].first = NULL;
			break;
		}

		++idx;
	}
	return idx%ArrSize;
}
long Remap(const std::pair<long,long>&mp)
{
	int idx = 0;
	idx = SimpleHash(HashTable[mp.second].first);
	HashTable[idx].first = HashTable[mp.second].first;
	HashTable[idx].second = HashTable[mp.second].second;
	HashTable[mp.second].first = NULL;
	return mp.second;

}
void main()
{	

	
	std::string command ;

	std::cin >> casesNo;
	CompleteResult.resize(casesNo);
				std::cin.ignore();
	for (size_t i = 0; i < casesNo; ++i)
	{
		Result.clear();
		HashTable.clear();
		
		while (1)
		{
				getline(std::cin, command);
				std::stringstream test(command);
				if (command == "stop")break;
			while (true)
			{	
				 std::string strval;
				 
				 if (!test)break;
				 test >> strval;
				 if (strval == "size")
				 {
					 test >> ArrSize;
					 HashTable.resize(ArrSize);
				 }
				 else if (strval == "add")
				 {	
					 long key=0;
					 std::string val;
					 int idx = 0;
					 test >> key;
					 idx = SimpleHash(key);
					 test >> val;
					 if ((key%ArrSize) != idx)
					 {
						 OutOfOrder.push_back({ key%ArrSize,idx});
					 }
					 HashTable[idx] =std::make_pair(long(key),std::string(val));
				 }
				 else if (strval == "print")
				 {
					 int idx = 0;
					 for (auto& i : HashTable)
					 {
						 if (i.first != NULL)Result += std::to_string(idx) + " " + std::to_string(i.first) + " " + i.second + "\n";
						 ++idx;
					 }
					 Result += "\n";
				 }

				 else if (strval == "delete")
				 {
					 long key;
					 test >> key;
					 long freedIndex;
					 freedIndex=DeleteFromMap(key);//index ktory sie wlasnie zwolnil
					 for (auto& i : OutOfOrder)
					 {
						 if (i.first == freedIndex) {

							 freedIndex=Remap(i);
						 }
					 }
					
					 
				 }

				 
				 
			}

		
			



		}
		CompleteResult.push_back(Result);
	}
	for (auto& i : CompleteResult)
	{
		std::cout << i << std::endl;
	}


	std::cin.get ();
}