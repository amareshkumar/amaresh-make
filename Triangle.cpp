/*
 * Triangle.cpp
 *
 *  Created on: Dec 7, 2015
 *      Author: amakumar
 */

#include "Triangle.h"
#include <iostream>

Triangle::Triangle(int bs, int ht, int s1, int s2, int s3): base(bs), height(ht), side1(s1), side2(s2), side3(s3){
	std::cout << "triangle c-tor\n";

}

Triangle::~Triangle() {
	std::cout << "triangle d-tor\n";
}


double Triangle::get_area(){

	return ( double (1/2) * base * height);
}

double Triangle::get_perimeter(){

	return side1 + side2 + side3;
}


