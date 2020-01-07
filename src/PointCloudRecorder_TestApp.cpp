#include"PointCloud.h"
#include"Point.h"
#include"PointCloudRecorder.h"
#include<iostream>
#include<time.h>
#include<conio.h>
/**
 * @file PointCloudRecorder_TestApp.cpp
 * @Author Kumbukani KAMANGA 152120171097
 * @date 10th December, 2019
 */

 /**
 *\brief Test app to test the PointCloudRecorder class.
 */
int main() {
	srand(time(NULL));
	PointCloud pc(15);
	int x, y, z;
	for (int i = 0; i < pc.getPointNumber(); i++)
	{
		x = rand() % 100 + 1;
		y = rand() % 100 + 1;
		z = rand() % 100 + 1;
		pc.setPoints(i, x, y, z);
	}

	PointCloudRecorder R("TEST.txt");

	if (R.save(pc))
	{
		cout << "SUCCESS";
	}
	else
	{
		cout << "FAIL";
	}
	_getch();
	return 0;
}