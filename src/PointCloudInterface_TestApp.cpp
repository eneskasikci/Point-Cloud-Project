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
#include <time.h>
#include<fstream>
using namespace std;

/**
 * @file PointCloudInterface_TestApp.cpp
 * @Author Kumbukani KAMANGA 152120171097
 * @date 28th December, 2019
 */

 /**
 *\brief Test app to test the PointCloudInterface class.
 */
int main()
{
	srand(time(NULL));
	double randValX,randValY;
	int randVal_x,randVal_y,randVal_z;
	double Cam1[300],Cam2[300];
	PointCloud pc(100);
	cout << "-----------------------------POINTCLOUD INTERFACE TESTAPP-----------------" << endl;
	cout << "Creating random 100 random points for \"cam1\"" << endl;
	for (int i = 0; i < 300; i++)
	{
		randVal_x = rand() % 100 + 1;
		randVal_y = rand() % 100 + 1;
		randValX = (double)randVal_y / 100;
		randValX += randVal_x;
		cout << randValX << "\t";
		Cam1[i] = randValX;

		randVal_y = rand() % 100 + 1;
		randVal_x = rand() % 100 + 1;
		randValY = (double)randVal_x / 100;
		randValY += randVal_y;
		cout << randValY << "\t";
		Cam1[i + 1] = randValY;


		randVal_z = rand() % 100 + 1;
		cout << (double)randVal_z << endl;
		Cam1[i + 2] = (double)randVal_z;
		i += 2;
	}
	cout << "\nWriting to PCITest_cam1.txt" << endl;
	fstream file("PCITest_cam1.txt", ios::out);
	for (int i = 0; i < 300; i++) {
		if (i != 296) {
			file << Cam1[i] << "\t" << Cam1[i + 1] << "\t" << Cam1[i + 2] << endl;
		}
		else
		{
			file << Cam1[i] << "\t" << Cam1[i + 1] << "\t" << Cam1[i + 2];

		}
		i += 2;
	}
	file.close();


	cout << "Creating random 100 random points for \"cam2\"" << endl;
	for (int i = 0; i < 300; i ++)
	{
		randVal_x = rand() % 100 + 1;
		randVal_y = rand() % 100 + 1;
		randValX = (double)randVal_y / 100;
		randValX += randVal_x;
		cout << randValX << "\t";
		Cam2[i] = randValX;

		randVal_y = rand() % 100 + 1;
		randVal_x = rand() % 100 + 1;
		randValY = (double)randVal_x / 100;
		randValY += randVal_y;
		cout << randValY << "\t";
		Cam2[i + 1] = randValY;


		randVal_z = rand() % 100 + 1;
		cout << (double)randVal_z << endl;
		Cam2[i + 2] = (double)randVal_z;
		i += 2;
	}
	cout << "\nWriting to PCITest_cam1.txt" << endl;
	fstream file2("PCITest_cam2.txt", ios::out);
	for (int i = 0; i < 300; i ++) {
		if (i != 296) {
			file2 << Cam2[i] << "\t" << Cam2[i + 1] << "\t" << Cam2[i + 2] << endl;
		}
		else {
			file2 << Cam2[i] << "\t" << Cam2[i + 1] << "\t" << Cam2[i + 2];
		}

		i += 2;
	}
	file2.close();



	
	PointCloudRecorder write("Result.txt");
	DepthCamera read1("PCITest_cam1.txt");
	DepthCamera read2("PCITest_cam2.txt");
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
	RadiusOutlierFilter* fr1 = &f;
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

	cout << "PROCESSED CLOUD POINTS:" << endl;
	a.showCloud();
	cout << "Processing complete. Press any key to quit..." << endl;
	(void)_getch();
	return 0;
}