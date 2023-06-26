#include <iostream>
#include <math.h>

using namespace std;

class Person
{
	string name;
	string surname;
	unsigned long long pesel;
public:
	Person(string imie, string nazwisko, long long ID)
	{
		name = imie;
		surname = nazwisko;
		pesel = ID;
	}
	~Person()
	{
		name = "";
		surname = "";
		pesel = 0;
	}
	void SetName(string imie)
	{
		name = imie;
	}
	void SetSurame(string nazwisko)
	{
		surname = nazwisko;
	}
	void SetPesel(unsigned long long ID)
	{
		pesel = ID;
	}
	int GetYear()
	{
		return pesel / pow(10, 9);
	}
	int GetMonth()
	{
		return (int)(pesel / pow(10, 7)) % 100;
	}
	int GetDay()
	{
		return (int)(pesel / pow(10, 5)) % 100;
	}
	bool isMen()
	{
	
		if (((long long)(pesel / pow(10, 1)) % 10)%2==1)return true;
		else return false;
	}
	int GetControlValue()
	{
		int mm[4] = { 1,3,7,9 };
		int counter = 0;
		int buf = 0;
		
		for (int i = 10; i >0; --i)
		{
			if (counter == 4)counter = 0;
			buf += (mm[counter]*((long long)(pesel / pow(10, i)) % 10));
			counter++;
		}
		return buf;
	}
	bool IsCorrect()
	{
		if (pesel % 10 == (10-GetControlValue()%10)%10)return true;
		else return false;
	}
	void ShowAll()
	{
		cout << name << endl;
		cout << surname << endl;
		cout << pesel << endl;
		if (IsCorrect() == true)cout << "Pesel correct."<<endl;
		else cout << "pesel incorrect"<<endl;
		if (isMen() == true)cout << "M"<<endl;
		else cout << "K"<<endl;
		cout << GetYear() << "." << GetMonth() << "." << GetDay() << endl;
	}
};






int main()
{
	string imie = "K";
	string nazwisko = "S";
	long long ID = 12345678978;

	Person XD (imie, nazwisko, ID);
	XD.ShowAll();


	return 0;
}