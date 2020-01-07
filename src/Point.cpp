#include "Point.h"
#include <math.h>

/**
 * @file Point.h
 * @Author Boburshoh ABDULOV 152120171073
 * @date 28th December, 2019
 */

 /**
 * \brief operator== that compares the x, y, and z coordinates
 * of two points and returns true or false accordingly
* \param const Point& right : point to be compared with.
 * \return true/false
 */
bool Point::operator==(const Point &right)
{
	if ((x == right.x) && (y == right.y) && (z == right.z))
		return true;
	else
		return false;
}

/**
* \brief Used to set the coordinates of a point.
* \param double x: x coordinate to be assignment.
* \param double y: y coordinate to be assignment.
* \param double z: z coordinate to be assignment.
*/
void Point::setPoint(double X, double Y, double Z)
{
	x = X;
	y = Y;
	z = Z;
}

/**
* \brief Used to know the x coordinate of the point.
* \return x
*/
double Point::getX() const
{
	return x;
};

/**
* \brief Used to know the y coordinate of the point.
* \return y
*/
double Point::getY() const
{
	return y;
};

/**
* \brief Used to know the z coordinate of the point.
* \return z
*/
double Point::getZ() const
{
	return z;
};

/**
* \brief Used to know the distance between two points.
* \param const Point& P
* \return dist
*/
double Point::distance(const Point & P)const
{
	double dist;
	dist = sqrt(pow((x - P.x), 2) + pow((y - P.y), 2) + pow((z - P.z), 2));
	return dist;
};

/**
* \brief Returns itself (poiint object).
* \return x
*/
Point Point::returnPoint() const {
	Point x(x, y, z);
	return x;
}

/**
* \brief operator= that copies the x, y, and z coordinates
* of another point.
* \param const Point& pc2 : point to be equated to.
*/
void Point::operator=(const Point&pc2)
{
	setPoint(pc2.x, pc2.y, pc2.z);
}

