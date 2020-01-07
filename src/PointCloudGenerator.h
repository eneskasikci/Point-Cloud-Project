#pragma once
#include"PointCloud.h"
#include "Transform.h"
#include "Filterpipe.h"
/**
 * @file PointCloudInterface.h
 * @Author Boburshoh ABDULOV 152120171073
 * @date 28th December, 2019
 */
 /**
 * \brief A class creates the required objects for the capturefor object which are filterpipe and transform
*/
class PointCloudGenerator {
protected:
	Transform transform;
	Filterpipe filterPipe;

public:
	PointCloudGenerator() {}

	virtual PointCloud capture() = 0;
	virtual PointCloud captureFor() = 0;
	void setFilterpipe(Filterpipe);
	void setTransform(Transform);
};