#pragma once
#include"PointCloud.h"
#include"PointCloudRecorder.h"
#include"PointCloudGenerator.h"
#include<vector>

/**
 * @file PointCloudInterface.h
 * @Author Kumbukani KAMANGA 152120171097
 * @date 28th December, 2019
 */

 /**
 * \brief A class that used to make the refinement and processing of the cloud simpler.
*/
class PointCloudInterface
{
	PointCloud pointCloud;
	PointCloud patch;
	vector<PointCloudGenerator*> generators;
	PointCloudRecorder* recorder;

public:
	void addGenerator(PointCloudGenerator*);
	void setRecorder(PointCloudRecorder*);
	bool generate();
	void showCloud();
	bool record();
};

