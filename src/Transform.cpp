#include "Transform.h"
#include "PointCloud.h"
#include "Point.h"
#include<iostream>
#include <math.h>
#include <string>
#include <Eigen/Dense>
using namespace std;
/**
 * @file Transform.cpp
 * @Author Ahmad ZAIDAN 152120171076
 * @date 10th December, 2019
 */

 /**
 * \brief SetAngles function that sets the angles array.
 *\param double array angle: angles.
 */
void Transform::setAngles(Eigen::Vector3d angle) {
	for (int i = 0; i < 3; i++) {
		angles(i) = angle(i);
	}
}
/**
* \brief SetTrans function that sets the Trans array.
*\param double array tr: trans.
*/
void Transform::setTrans(Eigen::Vector3d tran) {
	for (int i = 0; i < 3; i++)
		trans(i) = tran(i);
}
/**
* \brief SetRotation function that sets the Rotation Matrix.
*/
void Transform::setRotation()
{
	cout << "Setting rotation..."<<endl;
	double c = angles.z() * 3.14159265359 / 180;
	double b = angles.y() * 3.14159265359 / 180;
	double a = angles.x() * 3.14159265359 / 180;
	transmatrix(0, 0) = (cos(c * cos(b)));
	transmatrix(0, 1) = cos(c) * sin(b) * sin(a) - sin(c) * cos(a);
	transmatrix(0, 2) = cos(c) * sin(b) * cos(a) + sin(c) * sin(a);
	transmatrix(1, 0) = sin(c) * cos(b);
	transmatrix(1, 1) = sin(c) * sin(b) * sin(a) + cos(c) * cos(a);
	transmatrix(1, 2) = sin(c) * sin(b) * cos(a) - cos(c) * sin(a);
	transmatrix(2, 0) = -sin(b);
	transmatrix(2, 1) = cos(b) * sin(a);
	transmatrix(2, 2) = cos(b) * cos(a);
}
/**
* \brief SetTranslation function that sets the Translation Matrix.
*/
void Transform::setTranslation() {
	cout << "Setting translation..." << endl;
	transmatrix(0,3) = trans(0);
	transmatrix(1,3) = trans(1);
	transmatrix(2,3) = trans(2);
	transmatrix(3,0) = 0;
	transmatrix(3,1) = 0;
	transmatrix(3,2) = 0;
	transmatrix(3,3) = 1;
}
/**
* \brief Transform function that transforms a point.
*\param Point p: Point.
*\return Point
*/
Point Transform::doTransform(Point p) {
	Eigen::Vector4d pointt;
	Point res;
	pointt(0) = p.getX();
	pointt(1)= p.getY();
	pointt(2) = p.getZ();
	pointt(3) = 1;
	Eigen::Vector4d C;
	for (int i = 0; i < 4; i++)
	{
		C(i) = 0;
	}
	C = transmatrix*pointt;
	res.setPoint(C(0), C(1), C(2));
	return res;
}

/**
* \brief Transform function that transforms a pointcloud.
*\param PointCloud pc: PointCloud.
*\return PointCloud
*/
PointCloud Transform::doTransform(PointCloud pc) {
	
	PointCloud Transcloud(pc.getPointNumber());
	Point x;
	for (int i = 0; i < pc.getPointNumber(); i++) {
		Transcloud.setPoints(i,doTransform(pc.returnPoint(i)).getX(), doTransform(pc.returnPoint(i)).getY(), doTransform(pc.returnPoint(i)).getZ());
	}
	return Transcloud;
}