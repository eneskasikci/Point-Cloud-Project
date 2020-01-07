#include "PointCloud.h"
/**
 * @file PointCloud.cpp
 * @Author Kumbukani KAMANGA 152120171097
 * @date 28th December, 2019
 */

/**
* \brief PointCloud constructor that takes the number of points as a parameter.
*\param int n: number of points.
*/
PointCloud::PointCloud(int n=0)
{
	Point x;
	pointNumber = n; 
	int i = 0;
	while( i < pointNumber)
	{
		points.push_back(x);
		i++;
	}
}

/**
* \brief PointCloud default constructor that sets the number of points to 0
*/
PointCloud::PointCloud()
{

	pointNumber = 0;
}

/**
* \brief PointCloud deconstructor.
*/
PointCloud::~PointCloud(){
}

/**
* \brief Returns total number of points in the Point Cloud.
* \return pointNumber
*/
int PointCloud::getPointNumber() const
{
	return pointNumber;
}

/**
* \brief Returns combined Point Cloud containingg points of two PointCL=louds.
*\param const PointCloud& pc2: PointCloud to be combined with current one.
* \return tmp
*/
PointCloud PointCloud::operator+(PointCloud &pc2)
{
	int pn = pointNumber;
	int pn2=pc2.getPointNumber();
	pn += pn2;	

	PointCloud tmp_cloud(0);
	tmp_cloud.pointNumber = pn;
	
	list<Point>::iterator a;
	for (a = points.begin(); a!=points.end(); a++) {
		
		tmp_cloud.points.push_back(a->returnPoint());
	}
	for (a = pc2.points.begin(); a != pc2.points.end(); a++) {
		tmp_cloud.points.push_back(a->returnPoint());
	}
	return tmp_cloud;
}

/**
* \brief Used to set coordinates of a point in the cloud.
* \param int index: point identifier.
* \param double x: x coordinate.
* \param double y: y coordinate.
* \param double z: z coordinate.
*/
void PointCloud::setPoints(int index, double x, double y, double z)
{
	int count = 0;	
	list<Point>::iterator i;
	for (i = points.begin(); i!=points.end(); i++) {	
		if (count == index) {
			i->setPoint(x, y, z);
			return;
		}
		count++;
	}
}

/**
* \brief Used to access x coordinate of a point in the cloud.
* \param int i: point identifier.
* \return points[i].getX()
*/
double PointCloud::returnX(int j)
{
	int count = 0;
	list<Point>::iterator i;
	for (i = points.begin(); i != points.end(); i++) {
		if (count == j) {
			return i->getX();
		}
		count++;
	}
	return -99;
}

/**
* \brief Used to access y coordinate of a point in the cloud.
* \param int i: point identifier.
* \return points[i].getY()
*/
double PointCloud::returnY(int j)
{
	int count = 0;
	list<Point>::iterator i;
	for (i = points.begin(); i != points.end(); i++) {
		if (count == j) {
			return i->getY();
		}
		count++;
	}
	return -99;
}

/**
* \brief Used to access z coordinate of a point in the cloud.
* \param int i: point identifier.
* \return points[i].getZ()
*/
double PointCloud::returnZ(int j)
{
	int count = 0;
	list<Point>::iterator i;
	for (i = points.begin(); i != points.end(); i++) {
		if (count == j) {
			return i->getZ();
		}
		count++;
	}
	return -99;
}

/**
* \brief Used to access specific point in the cloud.
* \param int i: point identifier.
* \return points[i]
*/
Point PointCloud::returnPoint(int j)
{
	int count = 0;
	list<Point>::iterator i;
	for (i = points.begin(); i != points.end(); i++) {
		if (count == j) {
			return *i;
		}
		count++;
	}
}

/**
* \brief Used to copy the contents of one Point Cloud to another.
* \param const PointCloud& pc2 : The point cloud to be copied.
*/
void PointCloud::operator=(const PointCloud &pc2)
{
	while (!(points.empty())) {
		points.pop_back();
	}
	list<Point>::const_iterator a;
	a = pc2.points.begin();

	while ( a != pc2.points.end()) {
		points.push_back(a->returnPoint());
		a++;
	}
	pointNumber = pc2.getPointNumber();
}

/**
* \brief Returns the points list.
* \return points
*/
list<Point> PointCloud::getCloud(void) {
	return points;
}

/**
* \brief Used to set the number of points in the cloud
* \param int i: point number.
*/
void PointCloud::setPointNumber(int i) {
	this->pointNumber = i;
}

