#include <iostream>
//#include "indexed_List.h"
#include "List.h"
//#include "ListNode.h"
#include <vector>
//#include <map>
//#include "queue_list.h"
//#include <random>
//#include "stack_list.h" // Stack class definition
//#include "infixToPostfix.h"
//#include <stack>
using namespace std;
	
int main() { 

    List<int>l;
    for(int i = 0; i < 20; ++i) {
        l.push_back(rand() % 100 - 1);
    }

    l.mergeSort();
    l.printList();

    l.push_back(1000);
    l.printList();
    cout << "\nthe size of list should be 21 : but it is : " << l.size() << endl;
    //l.mergeSort();
    //l.printList();

    cin.get();

}
