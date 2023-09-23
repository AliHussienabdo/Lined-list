// Fig. 19.16: Queue.h
// Queue class-template definition.
#ifndef QUEUE_H
#define QUEUE_H

#include "List.h" // List class definition

template< typename QUEUETYPE >
class Queue : private List<QUEUETYPE> {
public:
   // enqueue calls List member function insertAtBack
   void enqueue(const QUEUETYPE& data) {
      this->push_back(data);
   } 
   
    QUEUETYPE front(){
   	    return this->firstElem();
    }

   // dequeue calls List member function removeFromFront
   bool dequeue(QUEUETYPE& data) {
      return this->remove_front(data);
   } 

   // isQueueEmpty calls List member function isEmpty
   bool isQueueEmpty() const {
      return this->isEmpty();
   } 

   // printQueue calls List member function print
   void printQueue() const {
      this->printList();
   } 
}; 

#endif
