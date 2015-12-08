/*
 * Shape.h
 *
 *  Created on: Dec 7, 2015
 *      Author: amakumar
 */

#ifndef SHAPE_H_
#define SHAPE_H_

class Shape {
public:

	virtual double get_area () = 0;
	virtual double get_perimeter() = 0;
};

#endif /* SHAPE_H_ */
