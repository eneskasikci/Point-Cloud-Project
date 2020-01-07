#pragma once
#include "PointCloud.h"
#include "Point.h"
#include<iostream>
#include <math.h>
#include <string>
#include <Eigen/Dense>
using namespace std;
/**
 * @file Transform.h
 * @Author Ahmad ZAIDAN 152120171076
 * @date 10th December, 2019
 */

 /**
 * \brief A class that transorms a point cloud to a wanted coordinate system
 *\ndotransform(point p) Transforms points.
 *\ndotransform(pointCloud pc) sends the points in the point cloud to the other dotransform to transform them.
 */
class Transform
{
private:
	Eigen::Vector3d angles;
	Eigen::Vector3d trans;
	Eigen::Matrix4d transmatrix;
public:
	void setAngles(Eigen::Vector3d angle);
	void setTrans(Eigen::Vector3d tran);
	void setRotation();
	void setTranslation();
	Point doTransform(Point p);
	PointCloud doTransform(PointCloud pc);
};

