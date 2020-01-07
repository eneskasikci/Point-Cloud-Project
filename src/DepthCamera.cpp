#include "DepthCamera.h"
#include<fstream>
#include<iostream>
#include"Point.h"
#include "PointCloud.h"
#include<string>
using namespace std;
/**
 * @file DepthCamera.cpp
 * @Author Ahmad ZAIDAN 152120171076
 * @date 10th December, 2019
 */

/**
* \brief DepthCamera constructor that takes the name of the file to read from.
*\param string filename_: file name.
*/
DepthCamera::DepthCamera(string filename_) {
	filename = filename_;
}
/**
* \brief Function that gets the number of points in the file.
*\return int
*/
int DepthCamera::GetRows()
{
	ifstream inf(filename);
	if (!inf)
	{
		return 0;
	}

	int nRows = 0;
	while (inf)
	{
		nRows += 1;
		string strLine;
		getline(inf, strLine);
	}

	return nRows - 1;
}
/**
* \brief Read the coordinates from a flile and saves them in a point cloud.
*\return PointCloud
*/
PointCloud DepthCamera::capture() {
	cout << "Capturing points from file \""<<filename <<"\"..." <<endl;
	PointCloud pointcloud1(GetRows());
	int x;
	int y;
	int z;
	int i = 0;
	ifstream read(filename);
	if (!read)
	{
		cout << "Could not load, check file name and directory" << endl;
	}
	else {
		while (!read.eof()) {
			read >> x;
			read >> y;
			read >> z;
			pointcloud1.setPoints(i, x, y, z);
			i++;
		}
	}
	read.close();
	return pointcloud1;
}
/**
* \brief Read the coordinates from a file,filter them,transform them and saves them in a point cloud.
*\return PointCloud
*/
PointCloud DepthCamera::captureFor() {
	PointCloud tmp;	
	tmp = capture();	
	filterPipe.filterout(tmp);	
	tmp = transform.doTransform(tmp);	
	return tmp;
}
