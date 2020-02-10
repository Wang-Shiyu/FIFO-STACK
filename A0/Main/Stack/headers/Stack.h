
#ifndef STACK_H
#define STACK_H

// this is the node class used to build up the LIFO stack
template <class Data>
class Node {

private:

	Data holdMe;
	Node *next;
	
public:

	void setHoldMe (Data pushMe) { this->holdMe = pushMe; }

	void setNext (Node<Data> *next) { this->next = next; }

	Data getHoldMe () { return this->holdMe; }

	Node<Data> *getNext() { return this->next; }
};

// a simple LIFO stack
template <class Data> 
class Stack {

	Node <Data> *head;

public:

	// destroys the stack
	~Stack () { 
		Node<Data> * current = head;
		while (current) {
			Node<Data> * next = current->getNext();
			delete current;
			current = next;
		}
		head = NULL;
	}

	// creates an empty stack
	Stack () { 
		head = NULL;
	}

	// adds pushMe to the top of the stack
	void push (Data pushMe) { 
		Node <Data> * newNode = new Node<Data>();
		newNode->setHoldMe(pushMe);
		newNode->setNext(head);
		head = newNode;
	}

	// return true if there are not any items in the stack
	bool isEmpty () {
		return head == NULL;
	}

	// pops the item on the top of the stack off, returning it...
	// if the stack is empty, the behavior is undefined
	Data pop () {
		if (isEmpty()) {
			//std::cout << "The stack is empty." << std::endl;
			return Data();
		}
		Data res = head->getHoldMe();
		Node <Data> *deleteNode = head; 
		head = head->getNext();
		delete deleteNode;
		return res;
	}
};

#endif
