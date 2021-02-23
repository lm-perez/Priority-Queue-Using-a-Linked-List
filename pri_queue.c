#include <stdlib.h>
#include <stdio.h>
#include "pri_queue.h"
/** @file pri_queue.c */
static Node_ptr_t head = NULL;
/**
 * Insert a Node into a priority queue.
 * @param priority
 * @param data
 * @author LIANNE PEREZ
 */
void PQ_insert(int priority, char * data) {
        
    // Creates new node with data and priority to insert
    Node_ptr_t new = malloc(sizeof(Node_t));
    new -> data = data;
    new -> priority = priority;
    new -> next = NULL;
    
    // Check if list is empty; head is new 
    if(head == NULL){
        
        head = new;
        
    } else {
        // Checking for priority; finding one with less priority
        Node_ptr_t j = head, previous = NULL;
        
        while((j -> priority) > priority){
            
            previous = j;
            j = j -> next;
            
        }
        // j = node with less priority; add to top of list
        if(previous == NULL){
            
            new -> next = head;
            head = new;
            
        } else {
            //if priority is slightly higher, add between
            new -> next = j;
            previous -> next = new;
            
        }
        
    }
    
}
/**
 * Delete and return the node with the highest priority.
 * @return The highest priority Node.
 */
Node_ptr_t PQ_delete() {
  
    //if list is empty
    if(head == NULL)
        
        return NULL;
    
    //if not empty, move head forward and return the previous head
    Node_ptr_t prev = head;
    head = head -> next;
    return prev;
}

/**
 * Do NOT modify this function.
 * @return A pointer to the head of the list.  (NULL if list is empty.)
 */
Node_ptr_t PQ_get_head() {
    return head;
}

/**
 * Do NOT modify this function.
 * @return the number of items in the queue
 */
int PQ_get_size() {
    int size = 0;
    Node_ptr_t tmp;
    for(tmp = head; tmp != NULL; tmp = tmp->next, size++);
    return size;
}


