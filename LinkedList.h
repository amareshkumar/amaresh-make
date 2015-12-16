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

#ifdef	__cplusplus
extern "C" {
#endif

    struct node {
    public: 
        node ( int value ): info ( value), next (nullptr) {
        }
        int info; 
        node* next;     
    };
    
    class LinkedList {
    public:
        LinkedList (): phead(nullptr){
        }
        
        LinkedList ( node* item ): phead(item){
            item->next = nullptr; 
        }

        

        /* 
		void add_to_front ( node *head, node *front ){
            
            front->next = phead; 
            phead = front;
			//head = phead; // added to keep the head updated. 
        }*/
        
		/* Changing this logic to keep track of head */ 
		node* add_to_front ( node *head, node *front ){
            
            front->next = phead; 
            phead = front;
			return phead; 
        }
		
		node* add_to_last ( node *front, node *last ){
            node *current = front;
			//when the list is emply. add this as the only item
			if (current) {
				current = last; 
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
		
        node* add_after_pos ( node *head, node *item, int pos){
			node *current = head; 
			int i = 1; 
			while ( i < pos ) {
				current = current->next; 
			}
			//add the item here as i == pos 
			item->next = current->next; 
			current = item; 
			
			//return head of new list with one extra node
			return head; 
        }
        
        void display_list (node* phead){
            if (!phead){
                cout << "No item to display!!. Please add some item in the list. \n";
                return;
            }
            while (phead){
                cout << phead->info << " " ;
                phead = phead->next;
            }
        }
        
        int return_front_node (node *head) {
            return head->info;
        } 
		
		int get_last_node (node *head) {
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
		node* populate_list (node* head, vector<int> &vect){
			for (int i = 0 ; i < 10; i++) 
				head =  add_to_last (head, new node(vect[i]));
				
			return head; 
		}
        
    private: 
        node* phead; 
    };


#ifdef	__cplusplus
}
#endif

#endif	/* LINKEDLIST_H */

