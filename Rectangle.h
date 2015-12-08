/*
 * Rectangle.h
 *
 *  Created on: Dec 7, 2015
 *      Author: amakumar
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"

class Rectangle: public Shape {
public:
	Rectangle(int len=0, int br=0);
	virtual ~Rectangle();

	double get_area (){

		return len * br;
	}

	double get_perimeter () {
			return 0.5 * (len + br);
	}
private:
	int len;
	int br;
};

#endif /* RECTANGLE_H_ */
