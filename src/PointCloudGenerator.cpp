#include "PointCloudGenerator.h"
/**
 * @file PointCloudInterface.h
 * @Author Boburshoh ABDULOV 152120171073
 * @date 28th December, 2019
 */
 
/**
* \brief Used to set the filterpipe.
* \param Filterpipe filterPipe: Filterpipe object.
*/
void PointCloudGenerator::setFilterpipe(Filterpipe filterPipe) {

	this->filterPipe = filterPipe;

}

/**
* \brief Used to set the transform.
* \param Transform transfrom: Transform object.
*/
void PointCloudGenerator::setTransform(Transform transform) {

	this->transform = transform;

}