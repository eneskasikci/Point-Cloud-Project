
#include "PointCloudRecorder.h"
#include"PointCloud.h"
/**
 * @file PointCloudRecorder.cpp
 * @Author Kumbukani KAMANGA 152120171097
 * @date 10th December, 2019
 */

/**
* \brief PointCloudRecorder constructor that takes the name of the file to save to.
*\param string fname: file name.
*/
PointCloudRecorder::PointCloudRecorder(string fname ="PointMap.txt")
{
	filename = fname;
}

/**
* \brief PointCloudRecorder desstructor
*\nCloses the save file.
*/
PointCloudRecorder::~PointCloudRecorder()
{
	rec.close();
}


/**
* \brief Saves the coordinates of the points in the point cloud to a text file.
*\nThis function returns true if the operation was succesful and false if otherwise.
*\param const PointCloud& pc: a point cloud.
*\return bool
*/
bool PointCloudRecorder::save(const PointCloud& pc)
{
	cout << "Saving pointcloud..." << endl;
	rec.open(filename,ios::out);
	 int i = 0;
	 list<Point>::const_iterator a;
	 a = pc.points.begin();

	 while (a != pc.points.end()) {
		 rec << a->getX() << "\t" << a->getY() << "\t" << a->getZ() << endl;
		 a++;
	 }
	if (rec)
		return true;
	else
		return false;
}
