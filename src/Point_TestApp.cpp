#include"Point.h"
#include<iostream>
#include<conio.h>

using namespace std;
/**
 * @file Point_TestApp.cpp
 * @Author Boburshoh ABDULOV 152120171073
 * @date 10th December, 2019
 */

 /**
 *\brief Test app to test the Point class.
 */
int main()
{
	int x, y, z;

	cout << "Enter X Y and Z for point: ";
	cin >> x >> y >> z;
	Point TEST(x, y, z);

	cout << "Testing getX(),getY(),and getZ()"<<endl;
	cout << "x: " << TEST.getX()<<endl;	
	cout << "y: " << TEST.getY()<<endl;
	cout << "z: " << TEST.getZ()<<endl;

	cout << "Creating second point with your x y z...";
	Point TEST2(x,y,z);
	cout << "\n\nIf testPoint1 == testPoint2 TRUE will be printed" << endl;
	
	if (TEST == TEST2)
	{
		cout << "TRUE"<<endl;
	}
	else
	{
		cout << "FALSE" << endl;
	}
	cout << "\n\nSince testPoint1 and testPoint 2 have the same coordinates, the ditance() function should return 0" << endl;
	cout << "\n\ntestPoint1.distance(testPoint2) = " << TEST.distance(TEST2);

	cout << "Enter new x,y,z. Testing distance between testPoint1 and testPoint2"<<endl;
	cin >> x>>y>> z;
	TEST2.setPoint(x, y, z);

	cout << "\n\ntestPoint1.distance(testPoint2) = " << TEST.distance(TEST2);

	_getch();
	return 0;
}