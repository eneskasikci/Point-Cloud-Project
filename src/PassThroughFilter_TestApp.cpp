#include"PassThroughFilter.h"
#include"Point.h"
#include"PointCloud.h"
#include<time.h>
#include<iostream>
#include<conio.h>
using namespace std;
/**
 * @file PassThroughFilter_TestApp.cpp
 * @Author Murat Musa YAL�IN 152120181109
 * @date 10th December, 2019
 */

/**
*\brief Test app to test the PassThroughFilter class.
*/
int main()
{
	PointCloud pc(10);
	srand(time(NULL));
	double x,y,z;
	int pn = pc.getPointNumber();
	for (int i = 0; i <pn; i++)
	{
		x = rand() % 100 + 1;
		y = rand() % 100 + 1;
		z = rand() % 100 + 1;
		pc.setPoints(i, x, y, z);
	}

	pc.setPoints(5, -5, 2, 3);
	pc.setPoints(9, 0, 2, -45);
	pc.setPoints(3, 0, 402, 40);


	cout << "POINT CLOUD POINTS BEFORE FILTER: " << endl;;
	for (int i = 0; i < pn; i++)
	{
		cout << pc.returnX(i) << "\t";
		cout << pc.returnY(i) << "\t";
		cout << pc.returnZ(i) << "\t" << endl;
	}
	cout << endl<<endl;

	PassThroughFilter F(0, 400, 0, 400, -45, 45);

	F.filter(pc);
	pn = pc.getPointNumber();
	cout << "POINT CLOUD POINTS AFTER FILTER:" << endl;
	for (int i = 0; i < pn; i++)
	{
		cout << pc.returnX(i) << "\t";
		cout << pc.returnY(i) << "\t";
		cout << pc.returnZ(i) << "\t" << endl;
	}



	_getch();
	return 0;
}
