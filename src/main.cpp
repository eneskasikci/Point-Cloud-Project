#include"RadiusOutlierFilter.h"
#include"Point.h"
#include"PointCloud.h"
#include"DepthCamera.h"
#include"PassThroughFilter.h"
#include"Transform.h"
#include"PointCloudRecorder.h"
#include"PointCloudGenerator.h"
#include"PointCloudInterface.h"
#include"PointCloudFilter.h"
#include"Filterpipe.h"
#include<iostream>
#include<conio.h>
#include <Eigen/Dense>
using namespace std;

int main()
{
	PointCloudRecorder write("Result.txt");
	DepthCamera read1("camera1.txt");
	DepthCamera read2("camera2.txt");
	PointCloud camera1(read1.GetRows());
	PointCloud camera2(read2.GetRows());
	Eigen::Vector3d ang1(0, 0, -90);
	Eigen::Vector3d trans1(100, 500, 50);
	Eigen::Vector3d ang2(0, 0, 90);
	Eigen::Vector3d trans2(550, 150, 50);
	Transform cam1;
	cam1.setAngles(ang1);
	cam1.setTrans(trans1);
	cam1.setRotation();
	cam1.setTranslation();
	Transform cam2;
	cam2.setAngles(ang2);
	cam2.setTrans(trans2);
	cam2.setRotation();
	cam2.setTranslation();
	read1.setTransform(cam1);
	read2.setTransform(cam2);
	RadiusOutlierFilter f(25);
	RadiusOutlierFilter* fr1= &f;
	PassThroughFilter F1(0, 400, 0, 400, -45, 45);
	PassThroughFilter* fp1 = &F1;
	PassThroughFilter F2(0, 500, 0, 500, -45, 45);
	PassThroughFilter* fp2 = &F2;
	Filterpipe f1;
	Filterpipe f2;
	f1.addfilter(fr1);
	f1.addfilter(fp1);
	read1.setFilterpipe(f1);
	f2.addfilter(fr1);
	f2.addfilter(fp2);
	read2.setFilterpipe(f2);
	PointCloudGenerator* r1 = &read1;
	PointCloudGenerator* r2 = &read2;
	PointCloudInterface a;
	PointCloudRecorder* w = &write;
	a.addGenerator(r1);
	a.addGenerator(r2);
	a.setRecorder(w);
	a.generate();
	a.record();
	cout << "Processing complete. Press any key to quit..." << endl;
	(void)_getch();
	return 0;
}