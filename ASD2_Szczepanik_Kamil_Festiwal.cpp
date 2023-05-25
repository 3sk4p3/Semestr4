#include <iostream>
#include <vector>
#include <algorithm>
# define M_PI           3.14159265358979323846 
struct Point
{
	Point(int _x, int _y):
		x(_x),y(_y)
	{}
	int x, y;
	Point() {  };
	friend bool operator<(const Point& l, const Point& r)
	{

		if (l.y < r.y)return true;
		else if (l.y == r.y)
		{
			if (l.x < r.x)return true;
		}
		 return false;
	}
	bool operator==(const Point& r)
	{
		if (x == r.x && y == r.y)return true;
		return false;
	}
};
typedef std::pair<float, int>SortedPoint;
int ccw (Point a, Point b, Point c)
{
	float area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	if (area < 0)return -1;//clockwise
	if (area > 0)return 1;//counterclockwise
	return 0;//coolinear

}
bool Graham(std::vector<Point>Points, Point Candidate)
{
	int size = Points.size();
	std::vector<Point>ConvexHull;
	int idx = 0;
	int min = Points[0].y;
	for (size_t i = 1; i < Points.size(); ++i)
	{
		if (Points[i].y < min || (Points[i].y == min && Points[i].x < Points[0].x)) {
			idx = i;
			min = Points[i].y;
		}
	}



	ConvexHull.push_back(Points[idx]);
	Points.erase(Points.begin() + idx);
	Points.push_back(Candidate);




	std::vector<SortedPoint>SortedPoints;
	SortedPoints.resize(Points.size());
	std::pair<int,int> A;

	
	for (size_t i = 0; i <Points.size() ; ++i)
	{
		A.first = Points[i].x -  ConvexHull[0].x;
		A.second = Points[i].y - ConvexHull[0].y;

		float angle = atan2(A.second, A.first);
	

		//float angle = atan2(B.second, B.first) - atan2(A.second, A.first);
		//float angle = atan2(A.first * B.second - A.second * B.first, A.first * B.first + A.second + B.second);
		angle = angle * (180.0f / M_PI);
		SortedPoints[i]=std::make_pair(angle, i);
	
	}
	std::sort(SortedPoints.begin(), SortedPoints.end(), [](auto& left, auto& right) {
		return left.first < right.first;
		});
		




	Points.push_back(ConvexHull[0]);
	SortedPoints.push_back(std::make_pair(0.0f, Points.size() - 1));
	ConvexHull.push_back(Points[SortedPoints[0].second]);
	SortedPoints.erase(SortedPoints.begin());
	Point BeforeLast=ConvexHull[0];
	Point Last=ConvexHull[1];

	for (size_t i = 0; i < SortedPoints.size(); ++i)
	{		
		int angle = ccw(BeforeLast, Last, Points[SortedPoints[i].second]);
			if (angle > 0)
		{
			
			ConvexHull.push_back(Points[SortedPoints[i].second]);
			BeforeLast = Last;
			Last = Points[SortedPoints[i].second];

		}
			else if (angle == 0)
			{
				ConvexHull.pop_back();
				ConvexHull.push_back(Points[SortedPoints[i].second]);
				BeforeLast = Last;
				Last = Points[SortedPoints[i].second];

			}
		else
		{
			ConvexHull.pop_back();
			Last = Points[SortedPoints[i].second];
			ConvexHull.push_back(Last);
		}
		

	}
	ConvexHull.pop_back();

	if (ConvexHull.size() > size)return false;
	for (auto& i : ConvexHull)
	{
		if (i == Candidate) return false;
		
	}


	return true;
}


int main()

{

	int LargeNo = 0;
	int SmallNo= 0;
	int result = 0;
	std::cin >> LargeNo;
	std::vector<Point>LargePoints;
	std::vector<Point>SmallPoints;
	LargePoints.reserve(LargeNo);
	for (size_t i = 0; i < LargeNo; ++i)
	{
		int x, y;
		std::cin >> x >> y;
		LargePoints.push_back(Point(x, y));
	}
	std::cin >> SmallNo;
	SmallPoints.reserve(SmallNo);
	for (size_t i = 0; i < SmallNo; ++i)
	{
		int x, y;
		std::cin >> x >> y;
		SmallPoints.push_back(Point(x, y));
	}
	
	//for (size_t i = 0; i < LargeNo-2; ++i)
	//{
	//	for (size_t j = i + 1; j < LargeNo - 1; ++j)
	//	{
	//		for (size_t k = j + 1; k < LargeNo; ++k)
	//		{


	//		
	//			

	//		std::vector<Point>Current;
	//			Current.push_back(LargePoints[i]);
	//			Current.push_back(LargePoints[j]);
	//			Current.push_back(LargePoints[k]);
	//			std::sort(Current.begin(), Current.end());
	//			
	//			int idx = 0; 

	//			for (auto& CurrentCandidate : SmallPoints)
	//			{
	//				
	//				if(CurrentCandidate<Current[0])
	//				{
	//					++idx;
	//					continue;
	//				}
	//				
	//				if (Graham(Current, CurrentCandidate))
	//				{
	//					SmallPoints.erase(SmallPoints.begin() + idx);
	//					++result;
	//					--idx;
	//					}
	//				++idx;

	//			}
	//			Current.clear();
	//		}
	//	}
	//}


	std::sort(LargePoints.begin(), LargePoints.end());
	for (auto& Candidate : SmallPoints)
	{
		if (Candidate < LargePoints[0])continue;
		if (Graham(LargePoints, Candidate))
		{
			++result;

		}
	}

	std::cout << result << std::endl;





	std::cin.get();
}