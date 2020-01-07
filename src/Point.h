#pragma once
/**
 * @file Point.h
 * @Author Boburshoh ABDULOV 152120171073
 * @date 10th December, 2019
 */

/**
* \brief
* This class holds the coordinates of the 3D points in the point cloud.
*\n Equal operator ( = = ), is used to check whether or not two points are equal
* i.e. in the same position.
*\n The distance() function returns the distance between two points.
*/
class Point
{
private:
	double x;
	double y;
	double z;

public:
	Point(double X = 0, double Y = 0, double Z = 0) :x(X), y(Y), z(Z) {};
	void setPoint(double, double, double);
	double getX() const;
	double getY() const;
	double getZ() const;
	bool operator==(const Point &);
	double distance(const Point &)const;
	Point returnPoint() const;
	void operator=(const Point&);
};