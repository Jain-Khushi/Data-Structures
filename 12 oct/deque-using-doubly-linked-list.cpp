
#include <bits/stdc++.h>

using namespace std;


class Node{
public:
int key,data;
Node *prev, *next;

Node()
{
data = 0;
next=NULL;
}

Node(int d)
{
data = d;
next = NULL;
}
};



class Deque
{
	Node* front;
	Node* rear;
	int Size;

public:
	Deque()
	{
		front = rear = NULL;
		Size = 0;
	}

	
	void insertFront(int data);
	void insertRear(int data);
	void deleteFront();
	void deleteRear();
	int getFront();
	int getRear();
	int getsize();
	bool isEmpty();
	void erase();
};


bool Deque::isEmpty()
{
	return (front == NULL);
}


int Deque::getsize()
{
	return Size;
}


void Deque::insertFront(int data)
{
	Node* newNode = new Node(data);

	if (newNode == NULL)
		cout << "Can't add elements to full queue\n";
	else
	{
	
		if (front == NULL)
			rear = front = newNode;

		
		else
		{
			newNode->next = front;
			front->prev = newNode;
			front = newNode;
		}

		
		++Size;
	}
}


void Deque::insertRear(int data)
{
	Node* newNode =  new Node(data);
	if (newNode == NULL)
		cout << "Can't add elements to full queue\n";
	else
	{
		
		if (rear == NULL)
			front = rear = newNode;

	
		else
		{
			newNode->prev = rear;
			rear->next = newNode;
			rear = newNode;
		}

		Size++;
	}
}


void Deque::deleteFront()
{

	if (isEmpty())
		cout << "Can't delete elements from empty queue'\n";


	else
	{
		Node* temp = front;
		front = front->next;

		
		if (front == NULL)
			rear = NULL;
		else
			front->prev = NULL;
		free(temp);

		
		Size--;
		cout<<"Front element deleted\n";
	}
}


void Deque::deleteRear()
{
	
	if (isEmpty())
		cout << "Can't delete elements from empty queue\n";

	
	else
	{
		Node* temp = rear;
		rear = rear->prev;

		
		if (rear == NULL)
			front = NULL;
		else
			rear->next = NULL;
		free(temp);

		
		Size--;
		cout<<"Rear element deleted\n";
	}
}


int Deque::getFront()
{
	
	if (isEmpty())
		return -1;
	return front->data;
}


int Deque::getRear()
{
	
	if (isEmpty())
		return -1;
	return rear->data;
}


void Deque::erase()
{
	rear = NULL;
	while (front != NULL)
	{
		Node* temp = front;
		front = front->next;
		free(temp);
	}
	Size = 0;
}


int main()
{
	Deque d;
	int choice,ele;
	
	
do
{

cout<<"-----------------------------------------\n";
cout << "1)Add an item at the front of Deque.\n";
cout << "2)Adds an item at the rear of Deque.\n";
cout << "3)Deletes an item from front of Deque.\n";
cout << "4)Deletes an item from rear of Deque.\n";
cout << "5)Get the front item from queue.\n";
cout << "6)Get the last item from queue.\n";
cout << "7)Check whether Deque is empty or not.\n";
cout << "8)Get size of  Deque.\n";
cout << "9)Delete all the elements from Deque.\n";
cout<< "10)Exit program\n";
cout<<"-----------------------------------------\n";

do{

cout<<"Enter choice >=1 and <=10: ";
  cin>>choice;
  cout<<"\n";
}
while(choice <1 || choice>10);

  
  switch (choice)
  {
  case 1: 
  cout<<"Enter Value:";
  cin>>ele;
  d.insertFront(ele);
  cout<<"\nElement "<<ele<<"inserted to front of deque\n";
  break;
  
  case 2: 
  cout<<"Enter Value:";
  cin>>ele;
  d.insertRear(ele);
  cout<<"\nElement "<<ele<<"inserted to rear of deque\n";
  break;
  
  case 3: 
  d.deleteFront();
  break;
  
  case 4: 
  d.deleteRear();
  break;
  
  case 5:
  cout<<"Front element is:"<<d.getFront()<<"\n";
  break;
  
  case 6:
  cout<<"Rear element is:"<<d.getRear()<<"\n";
  break;
  
  case 7:
  if(d.isEmpty())
  {
  cout<<"Deque is empty.\n";
  
  }
  else
  {
   cout<<"Deque is not empty.\n";
  }
  break;
  case 8:
  cout<<"Size of queue is:"<<d.getsize()<<"\n";
  break;
  case 9: 
  d.erase();
  cout<<"Deque erased\n";
  break;
  case 10:
  cout<<"Exiting program";
  exit(0);
          
  }
 }
while(true);

return 0;
}





