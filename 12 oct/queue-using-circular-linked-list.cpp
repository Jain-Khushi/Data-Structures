#include <bits/stdc++.h>
using namespace std;

template<class T>
class Node {
	public:
	T data;
	 Node<T>* next;
};

template<class T>
class Queue {
	public:
	 Node<T>*front;
	 Node<T> *rear;
};

template<class T>
void enqueue(Queue<T>* q, int value)
{
	Node<T>* temp = new Node<int>();
	temp->data = value;
	if (q->front == NULL)
		q->front = temp;
	else
		q->rear->next = temp;

	q->rear = temp;
	q->rear->next = q->front;
}

template <class T>
int dequeue(Queue<T>* q)
{
	if (q->front == NULL) {
		cout<<"Queue empty\n";
		return 0;
	}

	
	int value; 
	if (q->front == q->rear) {
		value = q->front->data;
		delete q->front;
		q->front = NULL;
		q->rear = NULL;
	}
	else 
	{
		Node<T>* temp = q->front;
		value = temp->data;
		q->front = q->front->next;
		q->rear->next = q->front;
		delete temp;
	}

	return value;
}

template <class T>
void displayQueue(Queue<T>* q)
{
	Node<T>* temp = q->front;
	cout<<"\nElements in Circular Queue are: ";
	while (temp->next != q->front) {
		cout<<temp->data<<"\n";
		temp = temp->next;
	}
	cout<<temp->data<<"\n";
}

void menu()
{
cout<<"---------------------------------\n";
cout<<"1. Enqueue element\n";
cout<<"2. Dequeue element\n";
cout<<"3. Display queue\n";
cout<<"4. Exit\n";
cout<<"---------------------------------\n";
}

int main()
{
	
Queue<int>* q = new Queue<int>();
q->front = q->rear = NULL;
int choice,val;

menu();


while(true)
{
do{
cout<<"Enter choice >=1 and <=4: ";
cin>>choice;
}
while(choice<1||choice>4);
cout<<"\n";
switch(choice)
{
	case 1:
		cout<<"enter integer to be enqueued: ";
		cin>>val;
		enqueue(q,val);
		break;
	case 2:
		cout<<"\nDeleted value = "<<dequeue(q)<<"\n";
		break;
	case 3:
		displayQueue(q);
		break;
	case 4:
		exit(0);		
}
}


	return 0;
}

