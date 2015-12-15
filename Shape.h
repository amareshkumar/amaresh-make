/*
 * Shape.h
 *
 *  Created on: Dec 7, 2015
 *      Author: amakumar
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

class Shape {
public:
	Shape (){
		cout << color( 10, "======\nShape C-tor\n======\n");
	}
	string color(int color=7, const string Message = "") {
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	    return Message;
	}
	virtual double get_area () = 0;
	virtual double get_perimeter() = 0;

	virtual ~Shape() {
		cout << color (12, "======\nShape D-tor\n======\n");
	}
};

#endif /* SHAPE_H_ */
