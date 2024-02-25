#include <iostream>
using namespace std;
#define SIZE 10
int A[SIZE];
int front = -1;
int rear = -1;


bool isempty()
{
 if(front == -1 && rear == -1)
 {
 return true;
 }
 else
 {
 return false;
 }
}


void enqueue ( int value )
{
 
 if ((rear + 1)%SIZE == front)
{
 cout<<"Queue is full \n";
 }
 else
 {
  
  if( front == -1)
     front = 0;
 
 rear = (rear+1)%SIZE;
   A[rear] = value;
 }
}


void dequeue ( )
{
 if(isempty())
  {
  cout<<"Queue is empty\n";
  }
 else

 if( front == rear )
 {
  front = rear = -1;
 }
 else
 {
 front = (front + 1)%SIZE;
 }
}


void showfront( )
{
 if( isempty())
 {
 cout<<"Queue is empty\n";
 }
 else
 {
 cout<<"element at front is:"<<A[front];
 }
}


void displayQueue()
{
 if(isempty())
  cout<<"Queue is empty\n";
 else
 {
  int i;
  if( front <= rear )
  {
   for( i=front ; i<= rear ; i++)
   cout<<A[i]<<" ";
  }
  else
  {
   i=front;
   while( i < SIZE)
   {
   cout<<A[i]<<" ";
   ++i;
   }
   i=0;
   while( i <= rear)
   {
   cout<<A[i]<<" ";
   ++i;
   }
  }
 }
}


int main()
{
 int choice, value;
 while(true)
 {
  cout<<"-------------------------\n";
  cout<<"1.Add element\n";
  cout<<"2.Remove element\n";
  cout<<"3.Show front of queue\n";
  cout<<"4.Display Queue\n";
  cout<<"5.Exit\n";
  cout<<"-------------------------\n";
  
  
  cout<<"Enter choice >=1 and <=5: ";
  cin>>choice;
  cout<<"\n";
  switch (choice)
  {
  case 1: 
  cout<<"Enter Value:\n";
  cin>>value;
  enqueue(value);
  break;
  case 2: 
  dequeue();
  break;
  case 3: 
  showfront();
  break;
  case 4: 
  displayQueue();
  break;
  case 5: 
  cout<<"Exiting program";
  exit(0);
          
  }
 }

 return 0;
}