/*
 * Quad.h
 *
 *  Created on: Dec 9, 2015
 *      Author: amakumar
 */

#ifndef QUAD_H_
#define QUAD_H_

#include "Shape.h"

#include <string>
#include <iostream>

using namespace std;

class Quad : public Shape {

public:
	Quad ():quad_type_name("Quadrilaterals") {
		cout  << "------\nQuad C-tor\n------\n";
	}

	string get_quad_tyte (){
		return quad_type_name;
	}
	virtual ~Quad (){
		cout  << "------\nQuad D-tor\n------\n";
	}
private:
	const string quad_type_name;
};


#endif /* QUAD_H_ */
