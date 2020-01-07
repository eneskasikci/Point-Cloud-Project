#include "RadiusOutlierFilter.h"
#include <windows.h>
/**
 * @file RadiusOutlierFilter.cpp
 * @Author Enes KASIKCI 152120181108
 * @date 10th December, 2019
 */

/**
* \brief RadiusOutlierFilter constructor that takes the radius to filter.
*\param double radius: radius.
*/

// Constructor
RadiusOutlierFilter::RadiusOutlierFilter(double radius_ = 25) {
	radius = radius_;
}
/**
* \brief Filter the points that don't have any neighbors.
*\nThis function edits the point cloud directly.
*\param const PointCloud& pc: a point cloud.
*/
void RadiusOutlierFilter::filter(PointCloud& pc) {
	cout << "Filtering points outside radius of " << radius<<"..."<<endl;
	int removed = 0;
	int pn = pc.getPointNumber();
	int x;
	int testX, testY, testZ;
	int neighbor;
	Point X;
	for (int i = 0; i < pn; i++) {
		neighbor = 0;
		X = pc.returnPoint(i);
		
		for (int j = i; j < pn; j++) {
		
			if (j == i)
				continue;
			if (X.distance(pc.returnPoint(j)) < radius) {
				neighbor++;
				break;
			}
		}
		if (neighbor == 0) {
			removed++;
			pc.setPoints(i, -99, -99, -99);
		}
	}
	int nPN = pn - removed;
	PointCloud fPC(nPN);
	int j = 0;
	for (int i = 0; i < pn; i++)
	{
		testX = pc.returnX(i);
		testY = pc.returnY(i);
		testZ = pc.returnZ(i);
		if (testX != -99 && testY != -99 && testZ != -99) {
			fPC.setPoints(j, testX, testY, testZ);
			j++;
		}
	}


	pc = fPC;
	
}

//Destructor
RadiusOutlierFilter::~RadiusOutlierFilter() {

}
