#include <iostream>
#include <exception>

using namespace std;

class StackEmpty : public runtime_error
{
public:
    StackEmpty(const string &err) : runtime_error(err)
    {
    }
};
class StackFull : public runtime_error
{
public:
    StackFull(const string &err) : runtime_error(err)
    {
    }
};

template <typename T>
class TwoStack
{
    enum
    {
        DEF_CAPACITY = 100
    };

    T *arr;
    int capacity;
    int top1;
    int top2;
    T temp;

public:
    TwoStack(int cap = DEF_CAPACITY);
    void push1(T el);
    void push2(T el);
    T &pop1();
    T &pop2();
    void display1();
    void display2();
    void display();
};

template <class T>
TwoStack<T>::TwoStack(int cap)
    : arr(new T[cap]), capacity(cap), top1(-1), top2(capacity) {}

template <class T>
void TwoStack<T>::push1(T el)
{
    try
    {
        if (!(top1 < top2 - 1))
            throw StackFull("Stack Overflow");
        top1++;
        arr[top1] = el;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what()<<'\n';
    }
}

template <class T>
void TwoStack<T>::push2(T el)
{
    try
    {
        if (!(top1 < top2 - 1))
            throw StackFull("Stack Overflow");
        top2--;
        arr[top2] = el;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() <<'\n';
    }
}


template <class T>
T &TwoStack<T>::pop1()
{
    try
    {
        if (top1<0)
        {
            throw StackEmpty("Stack Underflow ");
        }
        temp = arr[top1];
        top1--;
        return temp;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}


template <class T>
T &TwoStack<T>::pop2()
{
    try
    {
        if (top2 >= capacity)
        {
            throw StackEmpty("Stack Underflow!!!");
        }
        temp = arr[top2];
        top2++;
        return temp;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what()<<'\n';
    }
}

template <class T>
void TwoStack<T>::display1()
{
    try
    {
        if (top1 < 0)
            throw StackEmpty("Stack Is empty!!!");
        for (int i = top1; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what()<<'\n';
    }
}

template <class T>
void TwoStack<T>::display2()
{
    try
    {
        if (top2 >= capacity)
            throw StackEmpty("Stack Is empty!!!");
        for (int i = top2; i < capacity; i++)
        {
            cout << arr[i] << " ";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what()<<'\n';
    }
}

int main()
{
    int choice;
    int n;
    cout << "Enter the size : " << endl;
    cin >> n;
    TwoStack<int> st(n);
    do
    {
        int ele;
        cout << "---------------------MENU--------------------" << endl;
        cout << "1) Push in stack 1 " << endl;
        cout << "2) Push in stack 2" << endl;
        cout << "3) Pop in stack 1" << endl;
        cout << "4) Pop in stack 2" << endl;
        cout << "5) Display stack 1" << endl;
        cout << "6) Display stack 2" << endl;
        cout << "7) Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Element : ";
            cin >> ele;
            st.push1(ele);
            cout << endl;
            break;
        case 2:
            cout << "Enter Element : ";
            cin >> ele;
            st.push2(ele);
            cout << endl;
            break;
        case 3:
            cout<<st.pop1()<<" is deleted"<<endl;
            break;
        case 4:
            cout<<st.pop2()<<" is deleted"<<endl;
            break;
        case 5:
            st.display1();
            cout << endl;
            break;
        case 6:
            st.display2();
            cout << endl;
            break;
        case 7:
            exit(0);
            break;
        default:
            break;
        }
    } while (choice != 7);
    return 0;
}