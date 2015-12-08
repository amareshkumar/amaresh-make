/*
 * Rectangle.cpp
 *
 *  Created on: Dec 7, 2015
 *      Author: amakumar
 */

#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(int l, int b):len(l), br(b) {
	std::cout << "Rectangle c-tor\n";

}

Rectangle::~Rectangle() {
	std::cout << "Rectangle d-tor\n";
}

