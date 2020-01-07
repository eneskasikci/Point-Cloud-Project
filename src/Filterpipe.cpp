#include "Filterpipe.h"
using namespace std;
/**
 * @file PassThroughFilter.cpp
 * @Author Murat Musa YALÇIN 152120181109
 * @date 01 January, 2020
 */
 /**
 * \brief Used to add all the filter objects to a vector.
 * \param PointCloudFilter* filter : The filter objects.
 */
void Filterpipe::addfilter(PointCloudFilter* filter) {
	filters.push_back(filter);
}
/**
* \brief To run all the filter objects in the vector
* \param PointCloud& pc : The point cloud to be filtered.
*/
void Filterpipe::filterout(PointCloud& pc) {
	for (int i = 0; i < filters.size(); i++) {
		filters[i]->filter(pc);
	}
}
