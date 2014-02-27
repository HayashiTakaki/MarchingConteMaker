using namespace std;


template <class T>
class stack {
	
private:
	int size_of_stack;
	T *array;
	
public:
	stack(){
		size_of_stack = 0;
		array = (T *)malloc(sizeof(T) * size_of_stack);		
	}
	
	~stack(){
		free(array);
	}
	
	bool empty();
	T peek();
	T pop();
	T push(T);
	int size();
	
	void show(){
		cout << size_of_stack << "element" << endl;
		for (int i = 0; i < size_of_stack; i++) {
			cout << i << ";" << array[i] << endl;
		}
	}
	
	
	
};

template<class T> bool stack<T>::empty(){
	if (size_of_stack == 0) {
		return 1;	
	}else {
		return 0;
	}
}

template<class T> T stack<T>::peek(){
	if (array == NULL) {
		cout << "stack is empty" << endl;
		exit(2);
	}
	
	return array[size_of_stack - 1];
}

template<class T> T stack<T>::pop(){
	cout << "pop  " << size_of_stack << endl;
	
	if (array == NULL) {
		cout << "stack is empty" << endl;
		exit(2);
	}
	
	T temp=array[size_of_stack - 1];
	
	size_of_stack--;
	realloc(array, size_of_stack * sizeof(T));
	return temp;
}



template<class T> T stack<T>::push(T element){
	cout << "push  " << size_of_stack << endl;	size_of_stack++;
	cout << "realloc  " << size_of_stack * sizeof(T) << endl;
	realloc(array, size_of_stack * sizeof(T));
	array[size_of_stack - 1] = element;
	
	
	return element;
}

template<class T> int stack<T>::size(){
	return size_of_stack;
}
