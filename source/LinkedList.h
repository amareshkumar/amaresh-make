/* 
 * File:   LinkedList.h
 * Author: Jay Mata Di
 *
 * Created on December 12, 2015, 11:11 PM
 */

#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

#include <iostream>

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

        void add_to_last (node *front, node *last){
            node *current = front;       
            while ( current->next != nullptr ) {
                current = current->next; 
            }
            //found the last node
            current->next = last;
        }

        void add_to_front (node* front){
            
            front->next = phead; 
            phead = front;
        }
        
        void add_in_middle (){
        }
        
        void display_list (){
            if (!phead){
                cout << "No item to display!!. Please add some item in the list. \n";
                return;
            }
            while (phead){
                cout << phead->info << " " ;
                phead = phead->next;
            }
        }
        
        int return_front_node (node* front) {
            return front->info;
        } 
        
    private: 
        node* phead; 
    };


#ifdef	__cplusplus
}
#endif

#endif	/* LINKEDLIST_H */

