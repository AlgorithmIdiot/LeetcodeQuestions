#pragma once
//200 0 200 10 200 50 200 30 200 25

#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

class Point
{
private:

public:
	Point(int _x, int _y) : x(_x), y(_y)
	{

	}
	~Point()
	{}
	int x, y;

};

Point source(0, 0);
int minLengh = INT_MAX;


int calculateLength(const Point& A, const Point& B)
{
	return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
}

void LeftMin(vector<Point>& PointList, const Point& pre, int currentLength)
{
	if (PointList.empty())
	{
		currentLength += calculateLength(pre, source);
		if (currentLength <= minLengh) minLengh = currentLength;
	}

	//
	for (int i = 0; i < PointList.size(); i++)
	{
		currentLength += calculateLength(pre, PointList[0]);
		vector<Point> temp(PointList.begin() + 1, PointList.end()); // construct the temparary list [1, end() )
		LeftMin(temp, PointList[0], currentLength);
		// put the second element to the first for permutation
		rotate(PointList.begin(), PointList.begin() + 1, PointList.end());
	}
}

int main()
{
	ifstream file("Points.txt");
	vector<Point> PointList;
	int temp_x, temp_y;
	while (file >> temp_x >> temp_y)
	{
		Point temp_Point(temp_x, temp_y);
		PointList.push_back(temp_Point);
	}
	//for (int i = 0; i < PointList.size(); i++)
	LeftMin(PointList, source, 0);
	cout << minLengh << endl;
	cin.get();
	return 0;

}