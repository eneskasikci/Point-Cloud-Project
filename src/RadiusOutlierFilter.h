#pragma once
#include "PointCloud.h"
#include<iostream>
#include "Point.h"
#include "PointCloudFilter.h"
using namespace std;
/**
 * @file RadiusOutlierFilter.h
 * @Author Enes KASIKCI 152120181108
 * @date 10th December, 2019
 */

/**
* \brief A class that filters out points of a point cloud that don't have any neighbors
*\nfilter() filters out unwanted points.
*/
class RadiusOutlierFilter :public PointCloudFilter
{
public:
	RadiusOutlierFilter(double radius_);
	~RadiusOutlierFilter();
	void filter(PointCloud& pc) override;
private:
	double radius;
};
