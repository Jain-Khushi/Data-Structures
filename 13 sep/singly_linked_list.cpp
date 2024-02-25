#include <iostream>
using namespace std;

template <class T>
class node
{
public:
    T info;
    node<T> *next;
    node(T el, node<T> *ptr = NULL)
    {
        info = el;
        next = ptr;
    }
};

template <class T>
class Slist
{
private:
    node<T> *head;

public:
    Slist()
    {
        head = NULL;
    }
    ~Slist();
    bool isempty();
    void InsertAtHead(T el);
    void InsertionAtPoint(T el, int pos);
    void InsertAtTail(T el);
    void delete_head();
    void delete_pos(int pos);
    void delete_tail();
    node<T> *search(T el);
    void concat(Slist<T> &s2);
    void delete_val(T el);
    void display();
    void reverse();
    int count();
};

template <class T>
bool Slist<T>::isempty()
{
    return (head == NULL);
}

template <class T>
Slist<T>::~Slist()
{
    cout << "Destructor destructs everything !!!";
    node<T> *p;
    while (!isempty())
    {
        p = head->next;
        delete head;
        head = p;
    }
}

template <class T>
void Slist<T>::InsertAtHead(T el)
{
    head = new node<T>(el, head);
}

template <class T>
void Slist<T>::InsertionAtPoint(T el, int pos)
{
    if (pos > count() || pos < 0)
    {
        cout << "Invalid position" << endl;
    }
    else if (count())
    {
        if (pos == 0)
        {
            InsertAtHead(el);
        }
        else if(pos==count())
        {
            InsertAtTail(el);
        }
        else
        {
            node<T> *temp = head;
            node<T> *n = new node<T>(el);

            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            n->next = temp->next;
            temp->next = n;
        }
    }
}

template <class T>
void Slist<T>::InsertAtTail(T el)
{
    if (head == NULL)
    {
        InsertAtHead(el);
    }
    else
    {
        node<T> *temp = head;
        node<T> *n = new node<T>(el);
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->next = NULL;
    }
}

template <class T>
void Slist<T>::delete_head()
{
    if (count())
    {
        node<T> *temp = head;
        head = temp->next;
        delete temp;
    }
    else
    {
        cout << "The list is already empty !!! " << endl;
    }
}

template <class T>
void Slist<T>::delete_pos(int pos)
{
    node<T> *todelete = NULL;
    node<T> *temp = head;
    if (count())
    {
        if (pos >= count())
        {
            cout << "The position is greater than the size of the list !!!" << endl;
        }
        else if (pos < 0)
        {
            cout << "Position is less than 0 !!!" << endl;
        }
        else
        {
            node<T> *p = head;
            node<T> *q = p->next;
            int i = 0;
            while (i != pos - 1)
            {
                p = p->next;
                q = q->next;
                i++;
            }
            p->next = q->next;
            delete q;
            return;
        }
    }
    delete todelete;
}

template <class T>
void Slist<T>::delete_tail()
{
    if (count() == 1)
    {
        delete_head();
    }
    else if (count())
    {
        node<T> *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        node<T> *todelete = temp->next;
        temp->next = NULL;
        delete todelete;
    }
    else
    {
        cout << "The list is already empty !!! " << endl;
    }
}

template <class T>
node<T> *Slist<T>::search(T el)
{
    node<T> *temp = head;
    while (temp != NULL)
    {
        if (temp->info == el)
        {
            return temp;
        }
        temp = temp->next;
    }
    temp = NULL;
    cout << "The element is not present in this list !!!" << endl;
    return temp;
}

template <class T>
void Slist<T>::concat(Slist<T> &s2)
{
    if (count() && s2.count())
    {
        node<T> *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        node<T> *temp2 = s2.head;
        temp->next = s2.head;
    }
    else
    {
        cout << "The list is empty !!!";
    }
}

template <class T>
void Slist<T>::delete_val(T val)
{
    node<T> *slow = head;
    node<T> *todelete = NULL;
    if (head != NULL)
    {
        if (slow->info == val)
        {
            delete_head();
        }
        else
        {
            while (slow->next != NULL)
            {
                if (slow->next->info == val)
                {
                    todelete = slow->next;
                    slow->next = slow->next->next;
                    break;
                }
                slow = slow->next;
            }
        }
    }
    else
    {
        cout << "The list is already empty !!! " << endl;
    }
    delete todelete;
}

template <class T>
void Slist<T>::display()
{
    if (head == NULL)
    {
        cout << "NULL" << endl;
    }
    else
    {
        node<T> *temp = head;
        while (temp != NULL)
        {
            cout << temp->info << " -> ";
            temp = temp->next;
        }
        cout << " NULL" << endl;
    }
}

template <class T>
void Slist<T>::reverse()
{
    if (isempty())
    {
        cout << "The list is empty!!! " << endl;
    }
    else
    {
        node<T> *q = head;
        node<T> *r = NULL;
        node<T> *s;

        while (q != NULL)
        {
            s = r;
            r = q;
            q = q->next;
            r->next = s;
        }

        head = r;
        //for reassigning tail
        node<T> *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
    }
}

template <class T>
int Slist<T>::count()
{
    int c = 0;
    node<T> *temp;
    temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        c++;
    }
    return c;
}

//Main function
int main()
{
    Slist<int> li;
    Slist<int> li2;
    int choice;
    do
    {
        int ele, pos;
        cout << "\n.....Operations on singly linked list.....\n"<< endl;
        cout << "1) Add element to the head" << endl;
        cout << "2) Add element at the position" << endl;
        cout << "3) Add element to the tail" << endl;
        cout << "4) Delete element from head" << endl;
        cout << "5) Delete an element from ith position" << endl;
        cout << "6) Delete element from tail" << endl;
        cout << "7) Search for a node" << endl;
        cout << "8) Concat two lists" << endl;
        cout << "9) Delete element of specific value" << endl;
        cout << "10) Display the list" << endl;
        cout << "11) Reverse the list" << endl;
        cout << "12) Count number of nodes" << endl;
        cout << "13) Exit" << endl;
        cout<<"Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Element : ";
            cin >> ele;
            li.InsertAtHead(ele);
            break;

        case 2:
            cout << "Enter Element : ";
            cin >> ele;
            cout << endl
                 << "Enter the position : ";
            cin >> pos;
            li.InsertionAtPoint(ele, pos);
            break;

        case 3:
            cout << "Enter Element : ";
            cin >> ele;
            li.InsertAtTail(ele);
            break;

        case 4:
            li.delete_head();
            break;

        case 5:
            cout << "Enter position : ";
            cin >> pos;
            li.delete_pos(pos);
            break;

        case 6:
            li.delete_tail();
            break;

        case 7:
            cout << "Enter element to be searched for : ";
            cin >> ele;
            cout << li.search(ele)<<endl;
            break;

        case 8:
            int n;
            cout << "Enter the number of elements in list 2 : ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                int el;
                cout << "Enter " << i + 1 << " element : ";
                cin >> el;
                li2.InsertAtTail(el);
            }
            cout << "Your First list is : ";
            li.display();
            cout << "Your second list is : ";
            li2.display();
            li.concat(li2);
            cout << "Your concated list is : ";
            li.display();
            break;

        case 9:
            cout << "Enter element : ";
            cin >> ele;
            li.delete_val(ele);
            li.display();
            break;

        case 10:
            li.display();
            break;

        case 11:
            cout << "Original list : ";
            li.display();
            li.reverse();
            cout << "List after reversing : ";
            li.display();
            break;

        case 12:
            cout << "Number of elements are : " << li.count()<<endl;
            break;

        case 13:
            exit(0);

        default:
            break;
        }
    } while (choice != 13);
    return 0;
}