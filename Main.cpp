/*
 * Main.cpp
 *
 *  Created on: Dec 7, 2015
 *      Author: amakumar
 */


#include <iostream>
#include <memory>
#include <chrono>
#include <pthread.h>
#include <vector>
#include <math.h>


#include "Triangle.h"
#include "Shape.h"
#include "Rectangle.h"
#include "SmtPtr.h"
#include "Quad.h"
#include "LinkedList.h"

using namespace std;

void access_tri_mem_fun (Shape* sp){
	Triangle* tptr3 = dynamic_cast < Triangle* > (sp);
	if(sp){
		cout << tptr3->tri_name() << endl;
	}
}

template <typename T> 
long avg_arr_elements (T array[], int no_el){
	int sum = 0;
	for (int i = 0 ; i < no_el; i++){
		sum = sum + array[i]; 
	}
	return long((sum)/no_el); 
}

int main() {
		cout << "==================================================\n";
#ifdef SMART_PTR
		auto sp_tring = make_shared < Triangle > (10, 8, 10, 4, 5);
		std::cout << "==================================================\n";
		cout << "\nArea of trianlge: " << sp_tring->get_area() << "\nAnd the Perimeter is: " << sp_tring->get_perimeter() << endl;

		shared_ptr < Triangle > sp_tring2 = sp_tring;
		cout << "\nArea of trianlge: " << sp_tring2->get_area() << "\nAnd the Perimeter is: " << sp_tring2->get_perimeter() << endl;
		std::cout << "==================================================\n";
		unique_ptr < Rectangle > auto_ptr_rec (new Rectangle (5, 10));
		//cout << "Area of Rectangle: " << auto_ptr_rec->get_area() << "\nAnd the Perimeter is: " << auto_ptr_rec->get_perimeter() << endl;

		unique_ptr < Rectangle > auto_ptr_rec2 (move(auto_ptr_rec));
		std::cout << "==================================================\n";
		cout << "\nArea of Rectangle: " << auto_ptr_rec2->get_area() << "\nAnd the Perimeter is: " << auto_ptr_rec2->get_perimeter() << endl;

		auto_ptr_rec2.reset (new Rectangle (10, 2));
		cout <<"After resetting auto_ptr_rec2\n";
		cout << "\nArea of Rectangle: " << auto_ptr_rec2->get_area() << "\nAnd the Perimeter is: " << auto_ptr_rec2->get_perimeter() << endl;
		std::cout << "==================================================\n";

		cout <<" Using my own smart pointer:\n";
		std::cout << "==================================================\n";

		SmartPtr < Triangle > pTriSmartPtr ( new Triangle (10, 8, 10, 4, 5) );
		cout << "\nArea of trianlge: " << pTriSmartPtr->get_area() << "\nAnd the Perimeter is: " << pTriSmartPtr->get_perimeter() << endl;
		SmartPtr < Rectangle > pRecSmartPtr (new Rectangle (5, 10));
		cout << "\nArea of Rectangle: " << pRecSmartPtr->get_area() << "\nAnd the Perimeter is: " << pRecSmartPtr->get_perimeter() << endl;
		std::cout << "==================================================\n";

#endif
		cout << "==================================================\n";
#ifdef POLYMORPHISM
		cout << "Polymorphism and Casting in C++\n";

		std::cout << "==================================================\n";

		cout << "Using Shape class pointer\n";
		Shape* sptr = new Triangle (10, 8, 10, 4, 5);
		cout << "\nArea of trianlge: " << sptr ->get_area() << "\nAnd the Perimeter is: " << sptr ->get_perimeter() << endl;

		cout << "Accessing derived class member function...\n";
		cout << "Using some other function (internally uses dynamic_cast\n";
		access_tri_mem_fun (sptr);

		cout << "Using dynamic_cast directly\n";
		cout << (dynamic_cast < Triangle* > (sptr))->tri_name() << endl;

		cout << "Copying the value of sptr(base) to tptr (derived) \n";
		Triangle* tptr = static_cast < Triangle* > (sptr);
		cout << "\nArea of Trianlge: " << tptr ->get_area() << "\nAnd the Perimeter is: " << tptr ->get_perimeter() << endl;

		cout << "Before copying the value of tptr2(derived) to sptr2(base) \n";
		Triangle* tptr2 = new Triangle (10, 8, 10, 4, 5);
		Shape* sptr2 = static_cast < Shape* > (tptr2);
		cout << "\nArea of Trianlge: " << sptr2 ->get_area() << "\nAnd the Perimeter is: " << sptr2 ->get_perimeter() << endl;


//		Rectangle* pRec = new Rectangle (5, 10);
//		cout << "\nArea of trianlge: " << pRec->get_area() << "\nAnd the Perimeter is: " << pRec->get_perimeter() << endl;
//		cout << "After\n";
//		Shape* sptr2 = static_cast < Shape* > (pRec);
//		cout << "\nArea of trianlge: " << sptr2->get_area() << "\nAnd the Perimeter is: " << sptr2->get_perimeter() << endl;

		delete sptr;
		delete tptr2;
		//delete pRec;

#endif //POLYMORPHISM
		cout << "==================================================\n";	
#ifdef THREADING
		cout << "Multithreading practises\n";
		
		//declare an array of int
		int int_arr[5] = {1, 6, 8, 10, 15};
		cout << "The average of int array is: " << avg_arr_elements (int_arr, 5);
		
		
		#endif //THREADING
		cout << "==================================================\n";
#ifdef LINKED_LIST
                cout << "Linked List operations and their implementation\n";
				std::cout << "==================================================\n";
                //create a head node with info value 5
                node* head = new node (5);
                               
                LinkedList list (head); 
				cout << "Adding items to the front\n" ;
				
                /*list.add_to_front(new node (2));
                list.add_to_front (new node (10));
                list.add_to_front (new node (20));
                list.add_to_front (new node (100)); */
				
				//To get the head update with insertion and deletetion
                head = list.add_to_front (head, new node (2));
                head = list.add_to_front (head, new node (10));
                head = list.add_to_front (head, new node (20));
                head = list.add_to_front (head, new node (100));
				
                cout << "Elements in the list are: ";
				list.display_list( head );
				cout << endl;
				
				cout << "Adding items to last\n";
                head = list.add_to_last (head, new node(1000));
                head = list.add_to_last (head, new node(5555));
				               
				cout << "Elements in the list are: ";
                list.display_list( head );
                
				cout <<"\n------\n";
               
                cout << "The first node in the list is: "; 
                cout << list.return_front_node(head) << endl;;
				cout << "The last node in the list: ";
				cout << list.get_last_node (head) << endl;
				
				int pos = 0; 
				cout << "enter the position to insert the new node: "; 
				cin >> pos;
				cout << "Enter the value: ";
				int value;
				cin >> value; 
				//value = (new node (value1))->info; 
				cout << "\nList after adding new node at position " << pos << " with value " << value <<" is:\n";
				head = list.add_after_pos (head, new node (value), pos);
				//delete head;
				list.display_list (head); 
				
				cout << "elements in the list after removing last item from the list\n";
				head = list.remove_last_item (head);
				list.display_list ( head );
				cout << endl; 
				cout << "elements in the list after removing head node from the list\n";
				head = list.remove_first_item  (head) ;
				list.display_list ( head );
				//cout << "No of items:" << list.population (head) << endl;
				cout << endl; 
				
				cout << "------------------\n";
				
				cout << "Populating new list with vectors...\n";
				
				node* head2 = new node(1);
				LinkedList list2 ( head2 );
				cout << "Items in the list before initializing with vectors: " ;
				list2.display_list( head2 );
				
				vector <int> myIntVect; 
				cout << "vector's items are:\n";
				for (int i = 0 ; i < 10; i++) {
					//add randon integer values in the vector
					int value = rand() % 500;
					myIntVect.push_back ( value );
					cout << value << " ";
				}
                head2 = list2.populate_list (head2, myIntVect); 
				cout << "\nItems in the list after initializing with vector's elements are:\n" ;
				list2.display_list( head2 );
				
				cout << "\n------------------\n";
				cout <<"Reverse linkedlist...\n";
				head2 = list2.reverse_list (head2);
				cout << "After reversal, the list became:";
				list2.display_list( head2 );
				cout << "\n------------------\n";
				std::cout << "==================================================\n";
#endif //LINKED_LIST
		cout << "==================================================\n";
#ifdef QUEUE

#endif //QUEUE
        cout << "==================================================\n";        
		return 0;
}  //Function main() Ends here!!
