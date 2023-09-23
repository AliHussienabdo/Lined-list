/*
this is an indexed list project, that well help us to search for a speifc string rapidly
.. search in liked list is squintialy so we reduce the time by make array of likst 
this array have 26 list like alphaptic char 
*/
#ifndef IDXLIST_H
#define IDXLIST_H
#include "List.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class IndexedList {
	public:
	    IndexedList(){
		    for(int i=0;i<26;++i){
		    	List<string>l;
			    arrayOfLists.push_back(l);
	    	}
    	}
	
    	void PrintIndexedList(){
		    for(int i=0;i<26;++i){
			    std::cout << "\nPrinting List : " << i+1 << endl;
			    arrayOfLists[i].printList();
		    }
    	}
    	
    	void sort(){
    		for(int i=0;i<26;++i){
    			arrayOfLists[i].selection_sort();
			}
		}
	
    	void remove_IndexList(string str){
	    	arrayOfLists[str[0] - 'a'].remove(str);
    	}
	
    	string* search_IndexedList(string str) {
    		return arrayOfLists[str[0] - 'a'].searchRecursivly(str);
    	}
	
    	void push_back_IndexedList(string str){
	    	arrayOfLists[str[0] - 'a'].push_back(str);
    	}
	
    	void push_front_IndexedList(string str){
	    	arrayOfLists[str[0] - 'a'].push_front(str);
    	}
	
    	void remove_back_IndexedList(string val){
	    	arrayOfLists[val[0] - 'a'].remove_back(val);
    	}
	
    	void remove_front_IndexedList(string val){
     		arrayOfLists[val[0] - 'a'].remove_front(val);
    	}
	
	private:
		vector<List<string>>arrayOfLists;
};

#endif
