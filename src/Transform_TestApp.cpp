#include "Transform.h"
#include "PointCloud.h"
#include "Point.h"
#include<time.h>
#include<iostream>
#include <stdlib.h>
#include <Eigen/Dense>
using namespace std;

/**
 * @file Transform_TestApp.cpp
 * @Author Ahmad ZAIDAN 152120171076
 * @date 10th December, 2019
 */

/**
*\brief Test app to test the Transform class.
*/
int main() {
	Eigen::Vector3d ang(0, 0, -90);
	Eigen::Vector3d trans(100,500,50);
	PointCloud pc(10);
	srand(time(NULL));
	double x, y, z;
	int pn = pc.getPointNumber();
	for (int i = 0; i < pn; i++)
	{
		x = rand() % 100 + 1;
		y = rand() % 100 + 1;
		z = rand() % 100 + 1;
		pc.setPoints(i, x, y, z);
	}
	Transform camera1;
	camera1.setAngles(ang);
	camera1.setTrans(trans);
	camera1.setRotation();
	camera1.setTranslation();
	cout << "POINT CLOUD POINTS BEFORE TRANSFORMATION: " << endl;;
	for (int i = 0; i < pn; i++)
	{
		cout << pc.returnX(i) << "\t";
		cout << pc.returnY(i) << "\t";
		cout << pc.returnZ(i) << "\t" << endl;
	}
	pc=camera1.doTransform(pc);
	cout << "POINT CLOUD POINTS AFTER TRANSFORMATION:" << endl;
	for (int i = 0; i < pn; i++)
	{
		cout << pc.returnX(i) << "\t";
		cout << pc.returnY(i) << "\t";
		cout << pc.returnZ(i) << "\t" << endl;
	}


	system("pause");
}
