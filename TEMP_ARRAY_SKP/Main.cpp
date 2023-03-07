#include "Array.cpp"


int main()
{

	myClass<int>mc(5);
	mc.SeedWithRandomNumbers(1, 15);
	myClass<int>mc2(15);
	mc2.SeedWithRandomNumbers(2, 24);
	mc.ShowArr();
	mc2.ShowArr();
	mc2 = mc;
	mc2.ShowArr();
	myClass<int>mc3(mc);
	mc3.ShowArr();
	myClass<double>mc4(10);
	mc4.SeedWithRandomNumbers(1,50);
	mc4.ShowArr();

	std::cin.get();
}