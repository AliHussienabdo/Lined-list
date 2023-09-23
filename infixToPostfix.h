#ifndef POSTFIX_H
#define POSTFIX_H

#include "stack_List.h"
#include <iostream>
using namespace std;
//template<typename T, class Stack> 
// } Driver Code Ends
//template<typename T>
class infixToPostfix {
  public:
    // Function to convert an infix expression to a postfix expression.
    string toPostfix(string ifx){  // (6 + 2) * 5 - 8 / 4
        string pfx{""};
        char popedVal;
	
	    for(int i=0; i<ifx.size(); ++i){
		    if(ifx[i] == ' ') continue;
		    
		    if(Isdigit(ifx[i])){			
		    	pfx += ifx[i];
	    	}
	    	else if(ifx[i] == '('){
			    st.push('(');
		    }
		    else if(ifx[i] == ')'){
			    while(st.top() != '('){
			    	pfx += st.top();
				    st.pop(popedVal);
			    }
			    st.pop(popedVal); // to pop '(' from the stack
	    	}
		    else { // + , - , * , / , % pirority
		        while(!st.isStackEmpty() && priority(ifx[i]) <= priority(st.top())){
		        	pfx += st.top();
		        	st.pop(popedVal);	
				}
				st.push(ifx[i]);
		    }
	    }
	    while(!st.isStackEmpty()){
	       pfx += st.top();
		   st.pop(popedVal);
	    }
	    return pfx;
    }
    
    int postfixEvaluation(string pfix){
	    int secondOperand;
	    int firstOperand;
	    int res;
	    
	    for(int i=0;i<pfix.size();++i){
		
		    if(pfix[i] == ' ') continue;
		
		    if(Isdigit(pfix[i])){
			    stc.push(pfix[i] - '0');
		    }
		    else {
			    stc.pop(res);
			    secondOperand = res;
			    stc.pop(res);
		        firstOperand = res;
			    res = calc(firstOperand, secondOperand, pfix[i]);
			    stc.push(res);
			//cout<<firstOperand<<' '<<pfix[i]<<' '<<secondOperand<<" = "<<st.top()<<endl;
		   }
	   }
	   return stc.top();
    }
    
    
private:
	
	Stack<char>st;
	Stack<int>stc;
    // check the preority
    int calc(int fir , int sec , char op){
	    switch(op){
		    case '+': return fir + sec;
		    case '-': return fir - sec;
		    case '*': return fir * sec;
		    case '/': return fir / sec;
		    case '^': return fir ^ sec;
		    case '%': return fir % sec;
	    }
	    return 0;
    }
    int priority(char ch){
    	if(ch == '+' || ch == '-'){
    		return 1;
		}
		if(ch == '/' || ch == '*'){
			return 2;
		}
		else if(ch == '^' || ch == '%'){
			return 3;
		}
		return 0;
    }
    bool Isdigit(char d){ // ACII 0-> 48 & 9-> 57, a -> 97 & z -> 122
	    if( d >= 48 && d <= 57 ){   
		    return true;
	    }
	    return false;
    }
};

#endif

