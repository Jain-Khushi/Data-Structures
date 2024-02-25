#include <iostream>
#include <exception>
using namespace std;
template <class T>
class node
{
public:
	T data;		   // Data
	node<T> *prev; // A reference to the previous node
	node<T> *next; // A reference to the next node
};
template <class T>
class Doubly_Linked_List
{
	node<T> *front, *front2; // points to first node of list
	node<T> *end;			 // points to  last node of list
public:
	Doubly_Linked_List()
	{
		front = NULL;
		front2 = NULL;
		end = NULL;
	}
	void add_front(T);
	void add_ith(int, T);
	void add_end(T);
	void remove_front();
	void remove_end();
	void remove_ith(T);
	void remove_x(T);
	bool isempty();
	int size();
	node<T> *search(T);
	void display();
	void split2();
	void deleteAlt(Doubly_Linked_List<T> d1, Doubly_Linked_List<T> d2);

	void reverse();
	void concate(Doubly_Linked_List<T> d);
};

template <class T>
void Doubly_Linked_List<T>::deleteAlt(Doubly_Linked_List<T> d1, Doubly_Linked_List<T> d2)
{
	node<T> *temp = front;
	node<T> *temp1 = d1.front;
	node<T> *temp2 = d2.front;
	int i = 1;
	while (temp != NULL)
	{
		T d = temp->data;
		if (i % 2 == 0)
		{
			temp1 = new node<T>();
			temp1->data = d;
			temp1->prev = NULL;
			temp1->next = front;
			temp1 = temp1->next;
		}
		else
		{
			temp2 = new node<T>();
			temp2->data = d;
			temp2->prev = NULL;
			temp2->next = front;
			temp2 = temp2->next;
		}
		i++;
		temp = temp->next;
	}
}

template <class T>
void Doubly_Linked_List<T>::split2()
{
	int n = 0, p, q;
	node<T> *temp = front;

	// Find the length of the list
	while (temp != NULL)
	{
		n += 1;
		temp = temp->next;
	}
	p = n / 2;
	q = n - p;
	temp = front;
	while (p > 1)
	{
		temp = temp->next;
		p -= 1;
	}

	// second head node after splitting
	node<T> *front2 = temp->next;
	temp->next = NULL;

	node<T> *trav;
	trav = front;
	cout << endl;
	while (trav != NULL)
	{

		cout << trav->data << " ";
		trav = trav->next;
	}

	node<T> *trav2;
	trav2 = front2;
	cout << endl;
	while (trav2 != NULL)
	{

		cout << trav2->data << " ";
		trav2 = trav2->next;
	}
}

template <class T>
int Doubly_Linked_List<T>::size()
{
	node<T> *temp = front;
	T size = 0;
	while (temp != NULL)
	{

		temp = temp->next;
		size++;
	}
	return size;
}
template <class T>
bool Doubly_Linked_List<T>::isempty()
{
	return (front == end);
}

template <class T>
void Doubly_Linked_List<T>::add_front(T d)
{
	// Creating new node
	node<T> *temp;
	temp = new node<T>();
	temp->data = d;
	temp->prev = NULL;
	temp->next = front;

	// List is empty
	if (front == NULL)
		end = temp;

	else
		front->prev = temp;

	front = temp;
}
template <class T>
void Doubly_Linked_List<T>::add_ith(int i, T d)
{
	try
	{
		if (i > size() || i < 0)
		{
			throw 3;
		}
		if (i == 0)
			add_front(d);
		else if (i == size())
			add_end(d);
		else
		{
			node<T> *curr = front;
			int c = 0;
			while (c != i)
			{
				c++;
				curr = curr->next;
			}
			node<T> *temp;
			temp = new node<T>();
			temp->data = d;
			temp->next = curr;
			curr->prev->next = temp;
			temp->prev = curr->prev;
			curr->prev = temp;

			if (curr->prev == NULL)
				curr = temp;
		}
	}
	catch (int x)
	{
		cout << "\nInvalid input";
		cout << "\n-----------------";
	}
}
template <class T>
void Doubly_Linked_List<T>::add_end(T d)
{
	// create new node
	node<T> *temp;
	temp = new node<T>();
	temp->data = d;
	temp->prev = end;
	temp->next = NULL;

	// if list is empty
	if (end == NULL)
		front = temp;
	else
		end->next = temp;
	end = temp;
}
template <class T>
void Doubly_Linked_List<T>::remove_front()
{
	try
	{
		if (isempty())
		{
			throw 1;
		}
		else
		{
			node<T> *temp = front;
			front = front->next;
			front->prev = NULL;
			delete (temp);
		}
	}
	catch (int x)
	{
		cout << "\n--------------------";
		cout << "\nThe list is empty";
		cout << "\n--------------------";
	}
}
template <class T>
void Doubly_Linked_List<T>::remove_end()
{

	try
	{
		if (isempty())
		{
			throw 1;
		}
		else
		{
			node<T> *temp = end;
			end = end->prev;
			end->next = NULL;
			delete (temp);
		}
	}
	catch (int x)
	{
		cout << "\n--------------------";
		cout << "\nThe list is empty";
		cout << "\n--------------------";
	}
}
template <class T>
void Doubly_Linked_List<T>::remove_ith(T i)
{
	try
	{
		if (i > size() || i < 0)
		{
			throw 3;
		}
		if (i == 0)
		{
			remove_front();
		}
		else if (i == size() - 1)
		{
			remove_end();
		}
		else
		{
			int count = 0;
			node<T> *curr = front;
			while (curr != NULL && count < i)
			{
				curr = curr->next;
				count++;
			}
			if (curr->next == NULL)
			{
				curr->prev->next = NULL;
			}
			else
			{
				curr->prev->next = curr->next;
				curr->next->prev = curr->prev;
			}
			delete curr;
		}
	}
	catch (int x)
	{
		cout << "\nInvalid Input";
	}
}
template <class T>
void Doubly_Linked_List<T>::remove_x(T x)
{

	node<T> *trav;
	trav = front;
	if (front != NULL)
	{

		if (trav->data == x)
		{
			remove_front();
			return;
		}
		else
		{
			while (trav != NULL)
			{
				if (trav->data == x)
				{

					trav->prev->next = trav->next;
					if (trav->next != NULL)
						trav->next->prev = trav->prev;
					delete trav;
					return;
				}
				else
				{
					trav = trav->next;
				}
			}
		}
	}
	else
	{
		cout << "\nElement not present";
		return;
	}
}
template <class T>
node<T> *Doubly_Linked_List<T>::search(T x)
{
	node<T> *trav;
	trav = front;
	while (trav != end->next)
	{
		if (trav->data == x)
		{
			cout << "\nElement is present in the list. Pointer: ";
			return trav;
		}
		trav = trav->next;
	}
	trav = NULL;
	cout << "\nThe element is not present in the list.";
	return trav;
}
template <class T>
void Doubly_Linked_List<T>::display()
{
	node<T> *trav;
	trav = front;
	cout << endl;
	while (trav != NULL)
	{

		cout << trav->data << " ";
		trav = trav->next;
	}
}
template <class T>
void Doubly_Linked_List<T>::reverse()
{
	node<T> *current = front;
	node<T> *temp = NULL;
	while (current != NULL)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}
	if (temp != NULL)
		front = temp->prev;

	node<T> *p = front;
	while (p->next != NULL)
		p = p->next;
	end = p;
}
template <class T>
void Doubly_Linked_List<T>::concate(Doubly_Linked_List d)
{
	node<T> *p = d.front;
	end->next = p;
	p->prev = end;
	node<T> *s = p;
	while (s->next != NULL)
		s = s->next;
	end = s;
}

int main()
{
	Doubly_Linked_List<int> D1;
	int n, i = 0, choice = 0, s = 0, z = 0, y = 0;
	do
	{
		Doubly_Linked_List<int> D2;
		Doubly_Linked_List<int> D3;

		cout << "\n\n------Menu------" << endl;
		cout << "1.Insert an element x at the beginning of the doubly linked list" << endl;
		cout << "2.Insert an element x at position ith in the doubly linked list" << endl;
		cout << "3.Insert an element x at the end of the doubly linked list" << endl;
		cout << "4.Remove an element from the beginning of the doubly linked list" << endl;
		cout << "5.Remove an element from ith position in thedoubly  linked list." << endl;
		cout << "6.Remove an element from the end of the doubly linked list" << endl;
		cout << "7.Search for an element x in the doubly linked list and return its pointer" << endl;
		cout << "8.Concatenate two doubly linked lists " << endl;
		cout << "9.Remove an element with a specific value. " << endl;
		cout << "10.Display the doubly linked list. " << endl;
		cout << "11.Reverse the list. " << endl;
		cout << "12. Split the list alternatively" << endl;
		cout << "12.Exit." << endl;
		cout << "Enter your choice  : ";
		cin >> choice;
		cout << endl
			 << endl;
		switch (choice)
		{
		case 1:
			cout << "\n Enter the element to be inserted: ";
			cin >> n;
			D1.add_front(n);
			cout << "\n--------------------";
			cout << "\nElement added.";
			cout << "\n--------------------";
			break;

		case 2:
			cout << "\n Enter the element to be inserted at ith position: ";
			cin >> n;
			cout << "\n Enter the position:";
			cin >> i;
			D1.add_ith(i, n);

			break;
		case 3:
			cout << "\n Enter the element to be inserted:";
			cin >> n;
			D1.add_end(n);
			break;
		case 4:
			D1.remove_front();
			break;
		case 5:
			cout << "\nEnter the position:";
			cin >> i;
			D1.remove_ith(i);
			break;
		case 6:
			D1.remove_end();
			break;
		case 7:
			cout << "\nEnter the number to be searched.";
			cin >> n;
			cout << D1.search(n);
			break;
		case 8:

			if (D1.isempty())
			{
				cout << "\nEnter the size of 1st doubly linked list : ";
				cin >> s;
				cout << "\nEnter your elements of 1st doubly linked list :  ";
				do
				{

					cin >> n;
					D1.add_front(n);
					y++;
				} while (y < s);
			}

			cout << "\nEnter the size of 2nd doubly linked list : ";
			cin >> s;
			cout << "\nEnter your elements of 2nd doubly linked list:";

			do
			{

				cin >> n;
				D2.add_front(n);
				z++;

			} while (z < s);
			z = 0;
			D1.concate(D2);

			break;
		case 9:
			cout << "\nEnter the element to be deleted  : ";
			cin >> n;
			D1.remove_x(n);
			break;
		case 10:
			cout << "\nThe elements are  : " << endl;
			D1.display();
			break;
		case 11:
			D1.reverse();
			cout << "\nThe reversed doubly linked list is  : ";
			D1.display();
			break;
		case 12:
			D1.deleteAlt(D2, D3);
			D2.display();
			D3.display();
			break;

		case 13:
			exit(0);

		default:
			cout << "\n Invalid input.";
			break;
		}
	} while (choice != 13);

	return 0;
}