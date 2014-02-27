#include <iostream>
#include "stack.cpp"
using namespace std;


template <class T>
class queue {
	
private:
	int size_of_q;
	stack<T> Q;
	stack<T> temp;
	
public:
	queue(){
		size_of_q = 0;
	}
	
	
	void add(T);
	T peek();
	T remove();
	int size();
	
	
	void show(){
		cout << "Q-" << Q.size << endl;
		cout << "temp-" << temp.size << endl;
		
		
		
	}
	
	
	
};



template<class T> T queue<T>::peek(){
	if (!Q.empty()) {
		cout << "stack is empty" << endl;
		exit(2);
	}
	
	return Q.peek();
}

template<class T> T queue<T>::remove(){
	if (!Q.size()) {
		cout << "stack is empty" << endl;
		exit(2);
	}
	
	return Q.pop();
}

template<class T> void queue<T>::add(T element){
	while (Q.size()) {
		temp.push(Q.pop());
	}
	Q.push(element);
	
	while (temp.size()) {
		Q.push(temp.pop());
	}
	
	return; 
}

template<class T> int queue<T>::size(){
	return Q.size();
}

