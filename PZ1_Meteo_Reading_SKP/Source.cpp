#include <algorithm>
#include "Forecast.h"

int main()
{
	
	std::unique_ptr<Forecast>myForecast = std::make_unique<Forecast>();
	myForecast->LoadData("dwa_griby.grib");
	myForecast->FillSection(0);
	
	std::cin.get();
}