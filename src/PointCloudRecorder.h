#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include"PointCloud.h"
using namespace std;
/**
 * @file PointCloudRecorder.h
 * @Author Kumbukani KAMANGA 152120171097
 * @date 10th December, 2019
 */


/**
* \brief This is used to save the points in apoint clouds to a file.
* \nWhen save() is called, the points of the point cloud gicen as a paramtere are saved to a text file.
* \nReturns true if it saves successfully.
*/
class PointCloudRecorder
{
private:
	string filename;
	fstream rec;
public:
	PointCloudRecorder(string);
	~PointCloudRecorder();
	bool save(const PointCloud&);
};

