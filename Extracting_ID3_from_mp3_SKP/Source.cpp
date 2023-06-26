#include "MP3.h"
int main()
{
	MP3 Plik;
	Plik.read("KDA.mp3");
	Plik.SetTitle("ojojojojoj");
	Plik.SetComment("Jest kurwa problem ;-;");
	Plik.write("KDA.mp3");
	Plik.read("KDA.mp3");
	
	return 0;
}