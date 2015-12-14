/*
 * Triangle.cpp
 *
 *  Created on: Dec 7, 2015
 *      Author: amakumar
 */

#include "Triangle.h"
#include <iostream>

Triangle::Triangle(int bs, int ht, int s1, int s2, int s3): base(bs), height(ht), side1(s1), side2(s2), side3(s3){
	//tname = "Regular Triangle";
	std::cout << "------\nTriangle c-tor\n------\n";

}

Triangle::~Triangle() {
	std::cout << "------\nTriangle d-tor\n------\n";
}


double Triangle::get_area(){

	return 0.5 * base * height;
}

double Triangle::get_perimeter(){

	return side1 + side2 + side3;
}


