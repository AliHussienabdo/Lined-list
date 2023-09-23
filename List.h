#ifndef LIST_H
#define LIST_H
#include "ListNode.h"
#include <iostream>
#include <vector>
using namespace std;

template<typename NODETYPE>
class List {
	public:
		List (void){ // default constructor
			
			firstPtr = nullptr;
			lastPtr = nullptr;
			List_size = 0;
		}
		// copy constructor
		List (const List<NODETYPE>& l){
			this->operator=(l);
		}
		~List() {
            if (!isEmpty()) { // List is not empty
                std::cout << "\n\nDestroying nodes ...\n";

                ListNode<NODETYPE>* currentPtr{firstPtr};
                ListNode<NODETYPE>* tempPtr{nullptr};

                while (currentPtr != nullptr) { // delete remaining nodes
                    tempPtr = currentPtr;
                    std::cout << tempPtr->data << '\n';
                    currentPtr = currentPtr->nextPtr;
                    --List_size;
                    delete tempPtr;
               } 
            }
		}

       void push_front(const NODETYPE& value) {
            ListNode<NODETYPE>* newPtr{getNewNode(value)}; // new node

            if (isEmpty()) { // List is empty
                firstPtr = lastPtr = newPtr; // new list has only one node
            } 
            else { // List is not empty
                newPtr->nextPtr = firstPtr; // point new node to old 1st node
                firstPtr = newPtr; // aim firstPtr at new node
            } 
            ++List_size;
        } 
		// insert node at back of list
       void push_back(const NODETYPE& value) {
            ListNode<NODETYPE>* newPtr{getNewNode(value)}; // new node
            if (isEmpty()) { // List is empty
                firstPtr = lastPtr = newPtr; // new list has only one node
            } 
            else { // List is not empty
                lastPtr->nextPtr = newPtr; // update previous last node
                lastPtr = newPtr; // new last node
            } 
            ++List_size;
        } 
        
		bool remove_front(NODETYPE& value){
			if(isEmpty()){
				return false;
			}
			else {
				ListNode<NODETYPE>* temp {firstPtr};
				
				if(firstPtr == lastPtr){
					firstPtr = lastPtr = nullptr;
				}
				else {
				    firstPtr = firstPtr->nextPtr;
				}
				value = temp->data;
				--List_size;
				delete temp;
				return true;
			}
			return false;
		}
		
		bool remove_back(NODETYPE& value){
			
			if(isEmpty()){
				return false;
			}
			else {
				ListNode<NODETYPE>* temp {firstPtr}; 
				
				if(firstPtr == lastPtr){					
					firstPtr = lastPtr = nullptr;
				}
				else {
					while(temp->nextPtr != lastPtr){
						temp = temp->nextPtr;
				    }
					lastPtr = temp;
					temp = temp->nextPtr = nullptr;	
				}
				value = lastPtr->data; // the value of the last element that would be removed
				--List_size;
				delete temp;
				return true;
			}
			return false;
		}
		
		void remove(NODETYPE val){ // remove specific element
		    if(isEmpty()){
		     	std::cout << "Empty List ... \n";
		     	return;
			}
			// if the val was at the first
			if(firstPtr->data == val){
				this->remove_front(val);
				return;
			}
			ListNode<NODETYPE>* temp = firstPtr->nextPtr; // the second value
			ListNode<NODETYPE>* prev = firstPtr;
			 
			while(temp->nextPtr != nullptr){
				if(temp->data == val){
					prev->nextPtr = temp->nextPtr;
					delete temp;
					List_size--;
					return;
				}
				prev = temp;
				temp = temp->nextPtr;
			}
			// if we reach here that is mean that we didn't find the value in the all the list but we 
			// didn't search for it at the last node so we will search for it 
			if(temp->data == val){
				this->remove_back(val); // pass to remove back func and it will handle it 
			}
			else {
				std::cout << "This Value isn't exist in the List...\n\n";
			}
		}
		
		void split(const size_t index_of_split , List<NODETYPE>& newList){
			
			if(index_of_split >= size() || index_of_split < 0){
				std::cout<<"The index : "<< index_of_split <<" is out of ring\n";
				return;
			}

			int data ;
			
			size_t idx = index_of_split;
			ListNode<NODETYPE>* temp = this->firstPtr;
			//
			while(idx--){
				temp = temp->nextPtr;
				std::cout << temp->data << std::endl;
			}
			
			newList.List_size = this->size() - index_of_split - 1;
			this->List_size = index_of_split + 1; 

			newList.firstPtr = temp->nextPtr;
			newList.lastPtr = this->lastPtr;

			this->lastPtr = temp;
			this->lastPtr->nextPtr = nullptr;

			

			// newList.lastPtr = this->lastPtr; // Least added
			
			// this->lastPtr = temp;
			// newList.firstPtr = temp->nextPtr;
			
			// this->lastPtr->nextPtr = nullptr;
			
			// while(temp != nullptr){
			// 	temp = temp->nextPtr;
			// }
			// newList.lastPtr = temp;
		}
		
		void concatenate(List<NODETYPE>& b){
			// simply we but make the lastPtr->next of this to point to firstPtr of second 
			// and make Lastptr point to lastPtr of second 
			// instad of allocate and deallocate 
			lastPtr->nextPtr = b.firstPtr;
			lastPtr = b.lastPtr;
			this->List_size += b.size();
			b.firstPtr = b.lastPtr = nullptr;
        }
        
        void DeleteList(){
        	NODETYPE val;
        	while (!isEmpty()) { // List is not empty
        	    this->remove_front(val);
            }
		}
		
		void reverse(){
			
			ListNode<NODETYPE>* curr = firstPtr;
	        ListNode<NODETYPE>* prev = nullptr;
         	ListNode<NODETYPE>* next = nullptr;
	
	        while(curr != nullptr){
		        next = curr->nextPtr;
		        curr->nextPtr = prev;
		        prev = curr;
		        curr = next;
	        }
	        
	        ListNode<NODETYPE>* temp = firstPtr;
	        firstPtr = lastPtr;
	        lastPtr = temp;
	        temp = prev = curr = next = nullptr;
		}
		
		void printList()const{
			if(isEmpty()){
				std::cout << "The list is empty ... ";
				return;
			}
			else {
				ListNode<NODETYPE>* currentPtr {firstPtr};
				while(currentPtr  != nullptr){
					std::cout<<currentPtr->data<<' ';
					currentPtr = currentPtr->nextPtr;
				}
			}
			std::cout << "\n\n"; 
		}
		
		void operator=(const List<NODETYPE>& second){
			
			this->DeleteList(); // to deallocate all the nodes
			
			if(second.isEmpty()){
				return;
			} 
			
			ListNode<NODETYPE>* temp = second.firstPtr;
			
			while(temp != nullptr){
				this->push_back(temp->data);
				temp = temp->nextPtr;
			}
		}

		void mergeSort(){
			//ListNode<NODETYPE>* temp = list->firstPtr;
			if(this->size() <= 1){
				return;
			}
			List<NODETYPE>NewList;
			this->split(this->size()/2-1,NewList);

			NewList.mergeSort();
			this->mergeSort();

			// *this = merge(*this,NewList);
			
			this->firstPtr = mergeHelper(this,&NewList);
			this->List_size += NewList.size();
			
			NewList.firstPtr = NULL; // we add that to avoid destruing the list
			NewList.List_size = 0;
			// NewList.lastPtr = NULL;

		}
		
		void selection_sort(){
			
			if(isEmpty() || size() == 1){
				return;
			}
			
			ListNode<NODETYPE>* curr = firstPtr;
			
			for(curr ; curr != nullptr ;curr = curr->nextPtr){
				
				for(ListNode<NODETYPE>* temp = curr->nextPtr; temp != nullptr ; temp = temp->nextPtr){
					
					if(temp->data < curr->data){
						//swap(&temp->data, &curr->data);
						NODETYPE tmp = temp->data;
						temp->data = curr->data;
						curr->data = tmp;
					}
				}
			}
		}
		
		NODETYPE MIN()  {
			
			if(isEmpty()){
				return NULL;
			}
			
			ListNode<NODETYPE>* temp = firstPtr;
			NODETYPE min = temp->data;
			
			while(temp != nullptr){
				if(temp->data < *min){
					min = temp->data;
				}
				temp = temp->nextPtr;
			}
			return min;
		}
		// take the index of node .. like array start of 0 ,, return The value itself by refrence
		//  we can access it or modify it if we want, if we want to prevent the user to modify the value 
		// we could retruen const refernce
		NODETYPE& operator[]( size_t index){ 
			                                
			if(index >= size() || index < 0 || isEmpty()){	
//			    throw std::out_of_range("subcript out of range\n");	
                std::cout<<"subcript out of range\n";
                throw;  
			}
			ListNode<NODETYPE>* temp = firstPtr;
			
			while(index--){ // traverse till the specified index if 
				temp = temp->nextPtr;
			}
			return temp->data;
		}
		
		size_t size() const {
			return List_size;
		}
		
		bool isEmpty() const {
			return firstPtr==nullptr;
		}
		// a utility function necessary for class stack and queue
		NODETYPE firstElem(){
			if(isEmpty()){
				return 0;
			}
			return firstPtr->data;
		}
		
		void recursivePrintReverse(){
			if(!isEmpty()){
				ListNode<NODETYPE>* tempFirstPtr = firstPtr;
				PrintListRecursivlyHelper(tempFirstPtr);
			}
			else {
				std::cout<<"The list is Empty...\n";
			}	
		}
		
		NODETYPE* searchRecursivly(NODETYPE val){
			ListNode<NODETYPE>* temp = firstPtr;
			return searchValRecursivlyHelper(temp,val);
		}
		
	private:
		
		ListNode<NODETYPE>* firstPtr{nullptr}; // pointer to first node
        ListNode<NODETYPE>* lastPtr{nullptr}; // pointer to last node
        size_t List_size = 0;

		
		ListNode<NODETYPE>* mergeHelper(List<NODETYPE>* list1, List<NODETYPE>* list2){
			ListNode<NODETYPE>* answer;

			if(list1->firstPtr == NULL){
				this->lastPtr = list2->lastPtr;
				return list2->firstPtr;
			}
			if(list2->firstPtr == NULL){
				this->lastPtr = list1->lastPtr;
				return list1->firstPtr;
			}


			if(list1->firstPtr->data <= list2->firstPtr->data){
				answer = list1->firstPtr;
				list1->firstPtr = firstPtr->nextPtr;
			}
			else {
				answer = list2->firstPtr;
				list2->firstPtr = list2->firstPtr->nextPtr;
			}

			answer->nextPtr = mergeHelper(list1,list2);
			return answer;
		}
        
        void PrintListRecursivlyHelper(ListNode<NODETYPE>* temp){
		    if(temp->nextPtr != nullptr){
				PrintListRecursivlyHelper(temp->nextPtr);
			}
			std::cout<<temp->getData()<<" ";
		}
		
		NODETYPE* searchValRecursivlyHelper(ListNode<NODETYPE>* temp, NODETYPE val)const{
			if(temp == nullptr){
				return 0;
			}
			if(temp->data == val){
				return &temp->data;
			}
			return 	searchValRecursivlyHelper(temp->nextPtr,val);
		}
		
		ListNode<NODETYPE>* getNewNode(const NODETYPE& value){
			return new ListNode<NODETYPE>{value};
		}
};

#endif
