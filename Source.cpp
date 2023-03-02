#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>



std::vector<std::pair<long*, std::string*>>HashTable;
std::string textIn;
std::ifstream File;
int casesNo = 0;
int ArrSize = 0;
int SimpleHash(long _key) {
	while (true)
	{
		if(HashTable[_key%ArrSize].first==NULL&& HashTable[_key % ArrSize].second == NULL)return _key % ArrSize;

		++_key;
	}
}
void main()
{
	//HashTable.resize(5);
	//HashTable[2] = { new long(2),new std::string("xddd")};
	//HashTable[2] = { NULL ,NULL};
	//for (size_t i = 0; i < 5; ++i)
	//{
	//	if (HashTable[i].first!=NULL&& HashTable[i].second != NULL)
	//	{
	//	std::cout << *HashTable[i].first << " " << *HashTable[i].second << std::endl;

	//	}
	//}

	File.open("dane.txt");
	if (File.is_open())
	{
		File >> casesNo;
		for (size_t i = 0; i < casesNo; ++i)
		{
		HashTable.clear();

						while (true)
						{

							File >> textIn;
							if (textIn == "stop")exit;
							else if(textIn=="add")
							{
								int index = 0;
								long _key = 0;
								std::string  _value = "";
								File >> _key >> _value;
								index = SimpleHash(_key);
								HashTable[index] = { new long(_key),new std::string(_value) };
					
							}
							else if (textIn == "print")
							{
								for (size_t i = 0; i < ArrSize; ++i)
								{
									if (HashTable[i].first != NULL && HashTable[i].second != NULL) {
									std::cout <<i<<" "<< * HashTable[i].first << " " << *HashTable[i].second << std::endl;
									}
								}
								std::cout<<std::endl << std::endl;
							}
							else if (textIn == "delete")
							{
								long _key = 0;
								File >> _key;

								auto it = std::find_if(HashTable.begin(), HashTable.end(), [&](const std::pair<long*,std::string*> &pnt)
									{	
										if(pnt.first!=NULL)return *pnt.first == _key;
											
						
									});
								it->first = NULL;
								it->second= NULL;
								std::cout<<"first in delete: "<<it->first<<std::endl;
								std::cout<<"second in delete: "<<it->second <<std::endl;

							}
							else if(textIn=="size")
							{
								File >> ArrSize;
								HashTable.resize(ArrSize);
							}

						}
		}


		File.close();
	}
	else std::cout << "nie udało się otworzyć pliku." << std::endl;
	



	std::cin.get ();
}