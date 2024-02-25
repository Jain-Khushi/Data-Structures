#include <iostream>
using namespace std;

template <class T>
class node
{
public:
    T data;
    node<T> *next;
    node(T el, node<T> *ptr = NULL)
    {
        data = el;
        next = ptr;
    }
};

template <class T>
class orderList
{
private:
    node<T> *head;

public:
    orderList()
    {
        head = NULL;
    }
    ~orderList();
    bool isempty();
    void insert(T el);
    void delete_node(T el);
    void display();
    void search(T el);
    void merge(const orderList<T> &l1,const orderList<T> &l2);
};

template <class T>
bool orderList<T>::isempty()
{
    if(head==NULL)
        return true;
    return false;
}

template <class T>
void orderList<T>::insert(T el)
{
    node<T> *temp = head;
    node<T> *n = new node<T>(el);

    if (head == NULL || head->data > el)
    {
        head = n;
        head->next = temp;
    }
    else
    {
        while (temp->next != NULL)
        {
            if (temp->data <= el && temp->next->data > el)
            {
                n->next = temp->next;
                temp->next = n;
                return;
            }
            temp = temp->next;
        }

        temp->next = n;
        n->next = NULL;
    }
}

template <class T>
void orderList<T>::delete_node(T val)
{
    node<T> *temp = head;
    node<T> *todelete = NULL;
    if (head != NULL)
    {
        if (temp->data == val)
        {
            if(head!=NULL)
                head=head->next;
            delete temp;
        }
        else
        {
            while (temp->next != NULL)
            {
                if (temp->next->data == val)
                {
                    todelete = temp->next;
                    temp->next = temp->next->next;
                    return;
                }   
                temp = temp->next;
            }
            cout<<"The element is not present !!! "<<endl;
        }
    }
    else
    {
        cout << "The list is already empty !!! " << endl;
    }
    delete todelete;
}

template <class T>
void orderList<T>::display()
{
    node<T> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl<<endl;
}

template <class T>
void orderList<T>::search(T el)
{
    node<T> *temp = head;
    while (temp != NULL)
    {
        if (temp->data == el)
        {
            cout << "The element is present in the list " << endl;
            return;
        }
        temp = temp->next;
    }
    temp = NULL;
    cout << "The element is not present in this list !!!" << endl;
}

template<class T>
void orderList<T>::merge( const orderList<T> &l1, const orderList<T> &l2)
{
    node<T>* temp1=l1.head;
    node<T>* temp2=l2.head;

    while (temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data==temp2->data)
        {
            insert(temp1->data);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1->data > temp2->data)
        {
            insert(temp2->data);
            temp2=temp2->next;
        }
        else
        {
            insert(temp1->data);
            temp1=temp1->next;
        }
    }
    while (temp1!=NULL)
    {
        insert(temp1->data);
        temp1=temp1->next;
    }
    while (temp2!=NULL)
    {
        insert(temp2->data);
        temp2=temp2->next;
    }
}

template <class T>
orderList<T>::~orderList()
{
    node<T> *p;
    while (!isempty())
    {
        p = head->next;
        delete head;
        head = p;
    }
}

int main()
{
    orderList<int> li;
    orderList<int> li2;
    int choice;
    do
    {
        orderList<int> li3;
        int ele, pos;
        cout << "\n---------------------MENU--------------------\n" << endl;
        cout << "1) Add element " << endl;
        cout << "2) Delete element " << endl;
        cout << "3) Search for an element" << endl;
        cout << "4) Concat two lists" << endl;
        cout << "5) Display the list" << endl;
        cout << "6) Is empty?" << endl;
        cout << "7) Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Element : ";
            cin >> ele;
            li.insert(ele);
            break;

        case 2:
            cout << "Enter element : ";
            cin >> ele;
            li.delete_node(ele);
            li.display();
            break;

        case 3:
            cout << "Enter element to be searched for : ";
            cin >> ele;
            li.search(ele);
            break;

        case 4:
            int n;
            cout << "Enter the number of elements in list 2 : ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                int el;
                cout << "Enter " << i + 1 << " element : ";
                cin >> el;
                li2.insert(el);
            }
            cout << "Your First list is : ";
            li.display();
            cout << "Your second list is : ";
            li2.display();
            li3.merge(li,li2);
            cout << "Your concated list is : ";
            li3.display();
            break;


        case 5:
            li.display();
            break;

        case 6:
            if(li.isempty())
               cout<<"The list is empty";
            else
               cout<<"The list is not empty";
            
            break;

        case 7:
            exit(0);
        default:
            break;
        }
    } while (choice !=7);
    return 0;
}