// Fig. 19.13: Stack.h
// Stack class-template definition.
#ifndef STACK_H
#define STACK_H

#include "List.h" // List class definition

template<typename STACKTYPE>
class Stack : private List<STACKTYPE> {
public:
   // push calls the List function insertAtFront
   void push(const STACKTYPE& data) {
      this->push_front(data);
    } 
    
    STACKTYPE top(){
    	return this->firstElem();
	}

   // pop calls the List function removeFromFront
   bool pop(STACKTYPE& data) {
      return this->remove_front(data);
   } 

   // isStackEmpty calls the List function isEmpty
   bool isStackEmpty() const {
      return this->isEmpty();
   } 

   // printStack calls the List function print
   void printStack() const {
      this->printList();
   } 
}; 

#endif

