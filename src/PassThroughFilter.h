#pragma once
#include"PointCloud.h"
#include "PointCloudFilter.h"
/**
 * @file PassThroughFilter.h
 * @Author Murat Musa Musa YALCIN 152120181109
 * @date 10th December, 2019
 */

/**
* \brief A class that filters out points of a point cloud that lie outside of a given range
*\nfilter() filters out unwanted points.
*/
class PassThroughFilter : public PointCloudFilter
{
private:
	double upperLimitX;
	double upperLimitY;
	double upperLimitZ;
	double lowerLimitX;
	double lowerLimitY;
	double lowerLimitZ;
public:
	PassThroughFilter(double, double, double, double, double, double);
	void filter(PointCloud&) override;
	~PassThroughFilter();
};
