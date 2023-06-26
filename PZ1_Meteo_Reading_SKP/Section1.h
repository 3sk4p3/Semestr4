#pragma once
#include "SectionBase.h"
class Section1:public SectionBase
{
private:
	char m_Length[3];
	char m_TableVersion[1];
	char m_CenterID[1];//from table 0
	char m_ProcessIDNumber[1];//from table A
	char m_GridID[1];	//from table BA
	char m_GDSorBMSFlag[1];//from table 1
	char m_ParameterAndUnits[1];//from table 2
	char m_TypeofLevelOrLayer[1];//from table 3&3a
	char m_XofTheLevelorLayer[2];//from table 3
	char m_YearofCentury[1];
	char m_MonthOfYear[1];
	char m_DayofMonth[1];
	char m_HourOfDay[1];
	char m_MinuteOfHour[1];
	char m_ForecastTimeUnit[1];//from table 4
	char m_P1PeriodOfTime[1];//number of units
	char m_P2PeriodOfTimeOrIntervalBetweenAnalyses[1];//number of units
	char m_TimeRangeIndicator[1];//from table 5
	char m_NumberIncludedInAverage[2];//when octet 21 (Table 5) indicates an average or accumulation; otherwise set to zero. 
	char m_NumberMissingFromAveragesOrAccumulations[1];
	char m_CenturyOfInitialTime[1];//=20 until Jan. 1, 2001) 
	char m_IDofSubcenter[1];//from table C
	char m_DecimalScaleFactor[2];//D A negative value is indicated by setting the high order bit (bit No. 1) in octet 27 to 1 (on). 
	//if length>28:
	//char m_Reserved[11]
	//if length>40
	//char OriginatingCenterUsage[?]







public:
	Section1() {};
	Section1(const Section1& S1)=delete;
	Section1& operator=(const Section1& S1) = delete;
	int ReadToSection(size_t offset, std::vector<char>& I_Data) override;
	int GetSize();
	void DisplaySection() override;
	void DisplayDate();
	void DisplayFlagInfo();




};
