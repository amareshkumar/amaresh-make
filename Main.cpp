/*
 * Main.cpp
 *
 *  Created on: Dec 7, 2015
 *      Author: amakumar
 */


#include <iostream>
#include <memory>
#include <chrono>


#include "Triangle.h"
#include "Shape.h"
#include "Rectangle.h"

using namespace std;

int main() {
		auto sp_tring = make_shared < Triangle > (10, 8, 10, 4, 5);
		std::cout << "==================================================\n";
		cout << "Area of trianlge: " << sp_tring->get_area() << "\nAnd the perimeter is: " << sp_tring->get_perimeter() << endl;

		shared_ptr < Triangle > sp_tring2 = sp_tring;
		cout << "Area of trianlge: " << sp_tring2->get_area() << "\nAnd the perimeter is: " << sp_tring2->get_perimeter() << endl;
		std::cout << "==================================================\n";
		unique_ptr < Rectangle > auto_ptr_rec (new Rectangle (5, 10));
		//cout << "Area of Rectangle: " << auto_ptr_rec->get_area() << "\nAnd the Perimeter is: " << auto_ptr_rec->get_perimeter() << endl;

		unique_ptr < Rectangle > auto_ptr_rec2 (move(auto_ptr_rec));
		std::cout << "==================================================\n";
		cout << "Area of Rectangle: " << auto_ptr_rec2->get_area() << "\nAnd the Perimeter is: " << auto_ptr_rec2->get_perimeter() << endl;

		std::cout << "==================================================\n";

		return 0;
}
