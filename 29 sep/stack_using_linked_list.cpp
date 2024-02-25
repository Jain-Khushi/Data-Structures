#include <iostream>
using namespace std;

template <class T>
class node
{
public:
    node<T> *next;
    T data;

    node(T el, node<T> *ptr = NULL)
    {
        next = ptr;
        data = el;
    }
};

template <class T>
class stack
{
private:
    node<T> *head;

public:
    stack()
    {
        head = NULL;
    }
    void push(T el);
    void pop();
    T top();
    void display();
    bool isEmpty();
    void clear();
    ~stack();
};

template <class T>
stack<T>::~stack()
{
    cout << "Destructor destructs everything !!!";
    node<T> *p;
    while (!isEmpty())
    {
        p = head->next;
        delete head;
        head = p;
    }
}

template <class T>
void stack<T>::push(T el)
{
    head = new node<T>(el, head);
}

template <class T>
void stack<T>::pop()
{
    if (head == NULL)
    {
        cout << "Stack underflow !!!" << endl;
        return;
    }
    node<T> *temp = head;
    head = head->next;
    delete temp;
}

template <class T>
T stack<T>::top()
{
    if (head == NULL)
    {
        cout << "The stack is empty !!!" << endl;
        return (T)-1;
    }
    else
        return head->data;
}

template <class T>
bool stack<T>::isEmpty()
{
    if (head == NULL)
        return true;
    return false;
}

template <class T>
void stack<T>::display()
{
    if (head == NULL)
    {
        cout << "The stack is empty !!!" << endl;
        return;
    }
    node<T> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl
         << endl;
}

template<class T>
void stack<T>::clear()
{
    if(head==NULL)
    {
        cout<<"The stack is already empty !!!"<<endl;
        return;
    }
    node<T>* temp=head;
    while (temp!=NULL)
    {
        head=head->next;
        delete temp;
        temp=head;
    }
}


int main()
{
    stack<int> st;
    int choice = 0;
    do
    {
        int ele;
        cout << "\n--------------------------MENU---------------------------\n" << endl;
        cout << "1. Push into the stack" << endl;
        cout << "2. Pop out from the stack " << endl;
        cout << "3. Top of the stack" << endl;
        cout << "4. Display the stack " << endl;
        cout << "5. Check whether the stack is empty or not " << endl;
        cout << "6. Clear the stack" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element : ";
            cin >> ele;
            st.push(ele);
            break;
        case 2:
            st.pop();
            break;
        case 3:
            if (st.top() != -1)
                cout << "The top element is : " << st.top() << endl;
            break;

        case 4:
            st.display();
            break;

        case 5:
            if(st.isEmpty())
               cout<<"The stack is empty";
            else
               cout<<"The stack is not empty";
            break;
        
        case 6: 
            st.clear();
            break;

        case 7:
            exit(0);

        default:
            break;
        }
    } while (choice != 7);
}