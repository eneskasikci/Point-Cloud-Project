#include "DepthCamera.h"
#include "PointCloud.h"
#include "Point.h"
#include<time.h>
#include<iostream>
#include <stdlib.h>
#include <Eigen/Dense>
using namespace std;
/**
 * @file TDepthCamera_TestApp.cpp
 * @Author Ahmad ZAIDAN 152120171076
 * @date 10th December, 2019
 */

 /**
 *\brief Test app to test the DepthCamera class.
 */
int main() {
	DepthCamera read("camera1.txt");
	PointCloud p(read.GetRows());
	Eigen::Vector3d ang(0, 0, -90);
	Eigen::Vector3d trans(100, 500, 50);
	Transform cam;
	cam.setAngles(ang1);
	cam.setTrans(trans1);
	cam.setRotation();
	cam.setTranslation();
	read.setTransform(cam1);
	RadiusOutlierFilter f(25);
	RadiusOutlierFilter* fr1= &f;
	PassThroughFilter F1(0, 400, 0, 400, -45, 45);
	PassThroughFilter* fp1 = &F1;
	Filterpipe f1;
	f1.addfilter(fr1);
	f1.addfilter(fp1);
	read.setFilterpipe(f1);
	p = read.captureall();
	int pn = p.getPointNumber();
	for (int i = 0; i < pn; i++)
	{
		cout << p.returnX(i) << "\t";
		cout << p.returnY(i) << "\t";
		cout << p.returnZ(i) << "\t" << endl;
	}
	system("pause");
	return 0;
}
