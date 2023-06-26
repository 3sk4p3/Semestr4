#include "Engine.h"
int main()
{
	//gwarantuje zwolnienie pamięci, elementów zaalakowanych na stosie, przy normalnym wyjściu z programu
	//oraz przy zakończeniu programu poprzez wyjątek.
	//https://en.cppreference.com/w/cpp/memory/unique_ptr
	

	std::unique_ptr<Engine> Game= std::make_unique<Engine>();
	Game->Start();
	
	std::cin.get();
}