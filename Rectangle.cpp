/*
 * Rectangle.cpp
 *
 *  Created on: Dec 7, 2015
 *      Author: amakumar
 */

#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(int l, int b):len(l), br(b) {
	std::cout << "-----\nRectangle C-tor\n-----\n";

}

Rectangle::~Rectangle() {
	std::cout << "-----\nRectangle D-tor\n-----\n";
}

