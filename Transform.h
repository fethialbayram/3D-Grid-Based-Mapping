
#pragma once

#include "PointCloud.h"
#include <Eigen/Dense>

/*Trans ve angle degerlerine gore donusum matrisini olusturur
daha sonrasinda doTrans fonksiyonu ile alinan nokta ya da nokta bulutunu bu donusume tabi tutarak nokta bulutunu dondurur.
*/
class Transform{
	Eigen::Vector3d angles;
	Eigen::Vector3d trans;
	Eigen::Matrix4d transMatrix;
public:
	Transform();
	~Transform();
	void setAngles(double, double, double);
	void setTrans(double, double, double);
	Eigen::Matrix4d getTransMatrix();
	void setTransMatrix(Eigen::Matrix4d);
	double* getAngles();
	double* getTrans();
	list<Point> doTransForm(list<Point>points);
	PointCloud doTransform(PointCloud);
	void setRotation(Eigen::Vector3d ang);
	void setTranslation(Eigen::Vector3d tr);
};