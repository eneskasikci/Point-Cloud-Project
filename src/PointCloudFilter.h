#pragma once
#include "PointCloud.h"
#include<iostream>


/**
 * @file PointCloudFilter.h
 * @Author Enes KASIKCI 152120181108
 * @date 28th December, 2019
 */

class PointCloudFilter
{
public:
	virtual void filter(PointCloud&pc) = 0;
};
