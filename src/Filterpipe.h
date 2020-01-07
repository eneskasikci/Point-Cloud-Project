#pragma once
#include"PassThroughFilter.h"
#include"PointCloudFilter.h"
#include"PointCloud.h"
#include"RadiusOutlierFilter.h"
#include<vector>
#include<iostream>
using namespace std;
/**
 * @file PassThroughFilter.cpp
 * @Author Murat Musa YALÇIN 152120181109
 * @date 01 January, 2020
 */
class Filterpipe
{
	vector<PointCloudFilter*> filters;
public:
	void addfilter(PointCloudFilter* filter);
	void filterout(PointCloud& pc);
};

