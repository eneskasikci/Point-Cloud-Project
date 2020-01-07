#pragma once
#include"Point.h"
#include<iostream>
#include<list>
using namespace std;
/**
 * @file PointCloud.h
 * @Author Kumbukani KAMANGA 152120171097
 * @date 10th December, 2019
 */

/**
* \brief A class that holds an array of points to form a "cloud".
* \nHolds the points it has in a dynamically created array of points. The array's
* size is taken as a parameter in the constructor function when the object is created.
* \+ operator, returns a single point cloud with points that both point clouds have. 
*\n= operator, allows a point cloud to copy another one and take all of its points and overwrites its members.
*/
class PointCloud
{
	list<Point> points;
	//Point* points;
	int pointNumber;
	friend class PointCloudRecorder;
public:
	PointCloud(int );
	PointCloud();
	void setPoints(int, double, double, double);
	~PointCloud();
	int getPointNumber() const;
	PointCloud operator+(PointCloud &);
	void operator=(const PointCloud &);

	double returnY(int i);
	double returnZ(int i);
	double returnX(int i);
	Point returnPoint(int i);
	void setPointNumber(int);
	list<Point> getCloud(void);
};

