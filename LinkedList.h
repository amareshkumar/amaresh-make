/* 
 * File:   LinkedList.h
 * Author: Jay Mata Di
 *
 * Created on December 12, 2015, 11:11 PM
 */

#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

#include <iostream>
#include <vector>

using namespace std; 

struct node {
public: 
	node ( int value ): info ( value), next (nullptr) {
	}
	int info; 
	node* next;     
};

class LinkedList {
public:
	LinkedList (): phead(nullptr), no_of_items(0){
	}
	
	LinkedList ( node* item ): phead(item), no_of_items(0){
		item->next = nullptr; 
	}

	/* Changing this logic to keep track of head */ 
	node* add_to_front ( node *head, node *front );
	node* add_to_last ( node *front, node *last );
	node* add_after_pos ( node *head, node *item, int pos);
	int get_last_node (node *head);
	//Populate list with vector items
	node* populate_list (node* head, vector<int> &vect);
	//Remove a node from the list
	node* remove_last_item ( node *head);
	node* remove_first_item (node *phead);
	void display_list (node* phead);
	int population (node* phead);
	int return_front_node (node *head){
		return head->info;
	}
	
	node* sort_list_asc (node* head);
	node* sort_list_desc (node* head);
	node* reverse_list (node* head);
	
private: 
	node* phead; 
	int no_of_items; 
};

#endif	/* LINKEDLIST_H */

