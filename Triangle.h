/*
 * Triangle.h
 *
 *  Created on: Dec 7, 2015
 *      Author: amakumar
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Shape.h"

class Triangle: public Shape {
public:
	Triangle(int base=0, int height=0, int side1=0, int side2=0, int side3=0);
	virtual ~Triangle();

	double get_area ();
	double get_perimeter ();
private:
	int base;
	int height;
	int side1, side2, side3;
};

#endif /* TRIANGLE_H_ */
