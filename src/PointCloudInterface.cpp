#include "PointCloudInterface.h"
/**
 * @file PointCloudInterface.cpp
 * @Author Kumbukani KAMANGA 152120171097
 * @date 28th December, 2019
 */


/**
* \brief Adds a generator to the generators vector.
* \param PointCloudGenerator* gen: Depthcamera object.
*/
void PointCloudInterface::addGenerator(PointCloudGenerator*gen)
{
	generators.push_back(gen);
}

/**
* \brief Used to set the recorder.
* \param PointCloudRecoder* rec: recorder object.
*/
void PointCloudInterface::setRecorder(PointCloudRecorder* rec)
{
	recorder = rec;
}

/**
* \brief Used to generate a pointcloud by refining it and transforming where necesssary.
* \return true
*/
bool PointCloudInterface::generate()
{
	PointCloud tmp(0);
	for(int i=0;i<generators.size();i++)
	{
		tmp = generators[i]->captureFor();
		pointCloud = pointCloud + tmp;		
	}

	return true;
}

/**
* \brief Prints the point cloud to console.
*/
void PointCloudInterface::showCloud() {
	for (int i = 0; i < pointCloud.getPointNumber(); i++) {
		cout << pointCloud.returnX(i) << "\t" << pointCloud.returnY(i) << "\t" << pointCloud.returnZ(i) << endl;
	}
}

/**
* \brief Used to save the pointcloud points to a file.
* \return true
*/
bool PointCloudInterface::record()
{
	if (recorder->save(pointCloud))
		return true;
	else
		return false;
}
