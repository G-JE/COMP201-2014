#include <iostream>
#include <string>

//parametrized type
template <typename T>
class Node {
public:
	Node(T d, Node * n)
		data = d;
		next = n;
	}
	T data;
	Node * next, previous;
};

template <typename T>
class Stack {
public: 
	Stack(){
		head = NULL;
	}
	void push(T element) {
		Node<T> * node = new Node<T>(element, head);
		head = node;
	}
	T peek() {
		return head->data;
	}
	T * pop(){
		Node<T> * node;
		head = head->next;
		delete head;
		head = node;
	}
private:
	Node<T> * head;
		
	
};
int main()
{
Node<std::string> node2("world");
Node<std::string> node1("hello", &node2);
Node<float> number2(1.0);
Node<float> number1(1.0, &number2);
std::cout << "Hi" << std::endl;

for(Node<float> * pointer = &number1; pointer != NULL; pointer = pointer->next){
	std::cout << pointer->data << " ";
	
}

return 0;

}