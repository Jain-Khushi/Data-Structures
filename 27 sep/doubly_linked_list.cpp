#include <iostream>
using namespace std;

template<class T>
class node
{
public:
    node<T> *next;
    node<T> *prev;
    int data;

    node(int info)
    {
        next = NULL;
        prev = NULL;
        data = info;
    }
};

template<class T>
class doublyList
{
    node<T> *head;

public:
    doublyList()
    {
        head = NULL;
    }
    void InsertAtHead(T val);
    void InsertAtPos(T val, T pos);
    void InsertAtTail(T val);
    void DeleteHead();
    void DeleteAtPoint(T pos);
    void DeleteTail();
    void DeleteWithValue(T value);
    node<T>* search(T val);
    void concat(doublyList<T> &st);
    void Display();
    void reverse();
    int count_();
};

template<class T>
void doublyList<T>::InsertAtHead(T val)
{
    node<T> *n = new node<T>(val);
    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }
    head = n;
}

template<class T>
void doublyList<T>::InsertAtPos(T val, T pos)
{
    if (pos > count_() || pos < 0)
    {
        cout << "You entered an invalid position " << endl;
        return;
    }
    if (pos == 0)
    {
        InsertAtHead(val);
        return;
    }
    if(pos==count_())
    {
        InsertAtTail(val);
    }
    else
    {
        int count = 0;
        node<T> *temp = head;
        node<T> *n = new node<T>(val);
        while (temp!=NULL && count < pos)
        {
            temp = temp->next;
            count++;
        }

        n->next = temp;
        if (temp->next != NULL)
        {
            temp->prev->next=n;
            n->prev=temp->prev;
        }
        temp->prev = n;
    }
}

template<class T>
void doublyList<T>::InsertAtTail(T val)
{
    if (head == NULL)
    {
        InsertAtHead(val);
    }
    else
    {
    node<T> *temp = head;
    node<T> *n = new node<T>(val);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
    }
}

template<class T>
void doublyList<T>::DeleteHead()
{
    if (head == NULL)
    {
        cout<<"List is already empty !!!"<<endl;
    }
    else
    {
        node<T> *todelete = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        delete todelete;
    }
}

template<class T>
void doublyList<T>::DeleteAtPoint(T pos)
{
    if (pos >= count_() || pos < 0)
    {
        cout << "You entered an invalid position " << endl;
        return;
    }
    if (pos == 0)
    {
        DeleteHead();
        return;
    }
    if(pos==count_()-1)
    {
        DeleteTail();
    }
    else
    {
        int count = 0;
        node<T> *temp = head;
        while (temp!=NULL && count < pos)
        {
            temp = temp->next;
            count++;
        }

        if(temp->next==NULL)
        {
            temp->prev->next=NULL;
        }
        else
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
        }
        delete temp;
    }
}

template<class T>
void doublyList<T>::DeleteTail()
{
    if (head == NULL || count_() == 1)
    {
        DeleteHead();
        return;
    }
    node<T> *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next=NULL;
    delete temp;
}

template<class T>
void doublyList<T>::DeleteWithValue(T val)
{
    node<T> *temp = head;
    node<T> *todelete = NULL;
    if (head != NULL)
    {
        if (temp->data == val)
        {
            DeleteHead();
        }
        else
        {
            while (temp != NULL)
            {
                if (temp->data == val)
                {
                    todelete = temp;
                    temp->prev->next = temp->next;
                    if (temp->next != NULL)
                        temp->next->prev = temp->prev;
                    delete todelete;
                    return;
                }
                temp = temp->next;
            }
        }
    }
    cout << "The element is not present in the list !!!" << endl;
    return;
}

template<class T>
node<T>* doublyList<T>::search(T val)
{
    node<T> *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return temp;
        }
        temp = temp->next;
    }
    temp=NULL;
    return temp;
}

template<class T>
int doublyList<T>::count_()
{
    node<T> *temp = head;
    int counts = 0;
    while (temp != NULL)
    {
        counts = counts + 1;
        temp = temp->next;
    }
    return counts;
}

template<class T>
void doublyList<T>::concat(doublyList<T> &st1)
{
    if (count_() && st1.count_())
    {
        node<T> *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = st1.head;
        st1.head->prev=temp;
    }
    else
    {
        cout << "The list is empty !!!";
    }
}

template<class T>
void doublyList<T>::reverse()
{
    node<T> *temp = head;
    node<T> *t;
    while (temp != NULL)
    {
        t = temp->prev;
        temp->prev = temp->next;
        temp->next = t;
        temp = temp->prev;
    }
    if (t != NULL)
    {
        head = t->prev;
    }
}

template<class T>
void doublyList<T>::Display()
{
    node<T> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

//Main function
int main()
{
    doublyList<int> li;
    int choice;
    do
    {
        node<int>* search_;
        doublyList<int> li2;
        int ele, pos;
        cout << "\n---------------------MENU--------------------\n" << endl;
        cout << "1) Add element to the head" << endl;
        cout << "2) Add element at position " << endl;
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
        cout << "\nEnter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Element : ";
            cin >> ele;
            li.InsertAtHead(ele);
            break;
        case 2:
            cout << "Enter position : ";
            cin >> pos;
            cout << "Enter Element : ";
            cin >> ele;
            li.InsertAtPos(ele, pos);
            break;
        case 3:
            cout << "Enter Element : ";
            cin >> ele;
            li.InsertAtTail(ele);
            break;
        case 4:
            li.DeleteHead();
            break;
        case 5:
            cout << "Enter position : ";
            cin >> pos;
            li.DeleteAtPoint(pos);
            break;
        case 6:
            li.DeleteTail();
            break;
        case 7:
            cout << "Enter element to be searched for : ";
            cin >> ele;
            search_=li.search(ele);
            if(search_==NULL)
            {
                cout<<"The element is not present!!!"<<endl;
            }
            else
            cout << search_->data <<" is present "<< endl;
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
            li.Display();
            cout << "Your second list is : ";
            li2.Display();
            li.concat(li2);
            cout << "Your concated list is : ";
            li.Display();
            break;
        case 9:
            cout << "Enter element : ";
            cin >> ele;
            li.DeleteWithValue(ele);
            li.Display();
            break;
        case 10:
            li.Display();
            break;
        case 11:
            li.reverse();
            li.Display();
            break;
        case 12:
            cout << li.count_() << endl;
            break;
        case 13:
            exit(0);
        default:
            break;
        }
    } while (choice != 13);
    return 0;
}