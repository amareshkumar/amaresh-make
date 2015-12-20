/* 
 * File:   LinkedList.cpp
 * Author: Jay Mata Di
 * LinkedList implementation file
 * Created on December 12, 2015, 11:11 PM
 */

#include "LinkedList.h"

  
/* Changing this logic to keep track of head */ 
node* LinkedList::add_to_front ( node *head, node *front ){
	
	front->next = phead; 
	phead = front;
	return phead; 
}

node* LinkedList::add_to_last ( node *front, node *last ){
	node *current = front;
	//when the list is emply. add this as the only item
	if (!front) {
		front = last; 
		last->next = nullptr; 
		return front; 
	}
	
	while ( current->next != nullptr ) {
		current = current->next; 
	}
	//found the last node
	current->next = last;
	last->next = nullptr;
	
	return front; 
}

node* LinkedList::add_after_pos ( node *head, node *item, int pos){
		
	if (!head) {
		cout << "No items in the list\n";
		return head; 
	}
	
	//Check for the boundary condition 
	int population = LinkedList::population( head );
	if ( population < pos){
		cout << "\nOops!, the no of items in the list is only: " << population << endl; 
		return head; 
	}
	
	node *current = head; 
	int i = 1; 
	while ( i < pos ) {
		current = current->next; 
		i++;
	}
	
	//add the item here at i == pos 
	item->next = current->next; 
	current->next = item; 
	
	//return head of new list with one extra node
	return head; 
}

void LinkedList::display_list (node* phead){
	int no_of_nodes = 0; 
	if (!phead){
		cout << "No item to display!!. Please add some item in the list. \n";
		return;
	}
	while (phead){
		cout << phead->info << " " ;
		phead = phead->next;
		no_of_nodes++;
	}
	cout << "\nTotal elements: " << no_of_nodes << endl;
}

int return_front_node (node *head) {
	return head->info;
} 

int LinkedList::get_last_node (node *head) {
	node *current = head; 
	if (!current){
		cout << "No item in the list!! \n";
		return 0;
	}
	while (current->next){
		//cout << current->info << " " ;
		current = current->next;       
	}
	return current->info; 
}

//Populate list with vector items
node* LinkedList::populate_list (node* head, vector<int> &vect){
	for (int i = 0 ; i < vect.size(); i++) 
		head =  add_to_last (head, new node(vect[i]));
		
	return head; 
}

//Remove a node from the list
node* LinkedList::remove_last_item ( node *head){
	node* current = head; 
	
	while (current->next->next) {
		current = current->next;
	}
	delete current->next; 
	current->next = nullptr; 
	
	return head; 
}

node* LinkedList::remove_first_item (node *phead){
	phead = phead->next; 
	
	return phead; 
}

int LinkedList::population (node* phead){
	if (!phead){
		cout << "No item to display!!. Please add some item in the list. \n";
		return 0;
	}
	while (phead){
		cout << phead->info << " " ;
		phead = phead->next;
		no_of_items++;
	}
	return no_of_items; 
}

node* LinkedList::reverse_list ( node* head ) {
	node *newhead = nullptr;
	
	while ( head ){
		node *pnext = head->next; 
		head->next = newhead; 
		newhead = head; 
		head = pnext;
	}
	return newhead; 
}