#pragma once
#include<fstream>
#include<iostream>
#include"Transform.h"
#include"Filterpipe.h"
#include"PointCloudGenerator.h"
#include "PointCloud.h"
#include"Point.h"
#include<string>
using namespace std;
/**
 * @file DepthCamera.h
 * @Author Ahmad ZAIDAN 152120171076
 * @date 10th December, 2019
 */


/**
* \brief This is used to read the points from the file and saves them in a pointcloud.
* \nWhen capture() is called, the points are read and saved into a point cloud.
*/
class DepthCamera:public PointCloudGenerator
{
private:
	string filename;
public:
	DepthCamera(string filename_);
	PointCloud capture();
	int GetRows();
	PointCloud captureFor();
};

