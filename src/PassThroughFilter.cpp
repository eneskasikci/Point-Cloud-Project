#include "PassThroughFilter.h"
/**
 * @file PassThroughFilter.cpp
 * @Author Murat Musa YALÇIN 152120181109
 * @date 10th December, 2019
 */

/**
* \brief PassThroughFılter constructor that takes the upper and lower limits as paramaters.
*\param double xmin: Lower limit for x.
*\param double xmax: Upper limit for x
*\param double ymin: Lower limit for y.
*\param double ymax: Upper limit for y
*\param double zmin: Lower limit for z.
*\param double zmax: Upper limit for z
*/
PassThroughFilter::PassThroughFilter(double xmin=0, double xmax=0, double ymin=0, double ymax=0, double zmin=0, double zmax=0)
{
	upperLimitX = xmax;
	upperLimitY = ymax;
	upperLimitZ = zmax;
	lowerLimitX = xmin;
	lowerLimitY = ymin;
	lowerLimitZ = zmin;
}

/**
* \brief PassThroughFilter deconstructor.
*/
PassThroughFilter::~PassThroughFilter(){
}

/**
* \brief Used to filter out point outside of a given range.
* \param PointCloud& pc: 
*/
void PassThroughFilter::filter(PointCloud& pc)
{
	cout << "Filtering points that lie out of speciifed bounds..." << endl;
	int removedPoints = 0;
	double testX, testY, testZ;
	int pn = pc.getPointNumber();
	int i,j;

	for (i = 0; i < pn; i++){
		testX = pc.returnX(i);
		testY = pc.returnY(i);
		testZ = pc.returnZ(i);

		if ((testX<lowerLimitX || testX>upperLimitX) || (testY<lowerLimitY || testY>upperLimitY) || (testZ<lowerLimitZ || testZ>upperLimitZ))
		{
			pc.setPoints(i, -99, -99, -99);
			removedPoints++;
		}
	}

	int nPN = pn - removedPoints;
	PointCloud fPC(nPN);
	for (i = 0,j=0; i < pn; i++){
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