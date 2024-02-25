#include <iostream>

using namespace std;

class StackEmpty : public runtime_error
{
public:
    StackEmpty(const string &err) : runtime_error(err){};
};

class StackFull : public runtime_error
{
public:
    StackFull(const string &err) : runtime_error(err){};
};

template <typename typ>
class ArrayStack
{
    enum
    {
        DEF_CAPACITY = 100
    };

private:
    typ *Stack;
    int capacity;
    int t;

public:
    ArrayStack(int cap = DEF_CAPACITY);
    ArrayStack(const ArrayStack &);
    ~ArrayStack();
    int size() const;
    bool isEmpty() const;
    const typ &top() const;
    void push(const typ &);
    void pop();
    ArrayStack operator=(const ArrayStack &);
    void clear();
    void display() const;
};

template <typename typ>
ArrayStack<typ>::ArrayStack(int cap)
{
    capacity = cap;
    Stack = new typ[cap];
    t = -1;
}

template <typename typ>
ArrayStack<typ>::ArrayStack(const ArrayStack &obj)
{
    capacity = obj.capacity;
    t = obj.t;
    Stack = new typ[capacity];
    for (int i = 0; i <= t; i++)
    {
        Stack[i] = obj.Stack[i];
    }
}

template <typename typ>
ArrayStack<typ>::~ArrayStack()
{
    delete[] Stack;
}

template <typename typ>
int ArrayStack<typ>::size() const
{
    return t + 1;
}

template <typename typ>
bool ArrayStack<typ>::isEmpty() const
{
    return t < 0;
}

template <typename typ>
const typ &ArrayStack<typ>::top() const
{
    if (isEmpty())
        throw StackEmpty("Top of Empty Stack");
    return Stack[t];
}

template <typename typ>
void ArrayStack<typ>::push(const typ &el)
{
    if ((t + 1) == capacity)
        throw StackFull("Push in Full Stack");
    Stack[++t] = el;
}

template <typename typ>
void ArrayStack<typ>::pop()
{
    if (isEmpty())
        throw StackEmpty("Pop from Empty Stack");
    t--;
}

template <typename typ>
ArrayStack<typ> ArrayStack<typ>::operator=(const ArrayStack &obj)
{
    capacity = obj.capacity;
    t = obj.t;
    for (int i = 0; i <= t; i++)
    {
        Stack[i] = obj.Stack[i];
    }
    return *this;
}

template <typename typ>
void ArrayStack<typ>::clear()
{
    t = -1;
}

template <typename typ>
void ArrayStack<typ>::display() const
{
    if (isEmpty())
        throw StackEmpty("Displaying Empty Stack");
    for (int i = t; i >= 0; i--)
    {
        cout << Stack[i] << endl;
    }
}

int main()
{
    int choice;
    int cap;
    int num = 0;
    bool flag;
    cout << "\nEnter the maximum capacity of Stack: ";
    cin >> cap;

    ArrayStack<int> Stk1(cap);

    do
    {
        cout << "\n\t\tChoose an option:" << endl;
        cout << "\t\t1.)Push" << endl;
        cout << "\t\t2.)Pop" << endl;
        cout << "\t\t3.)Clear" << endl;
        cout << "\t\t4.)Size" << endl;
        cout << "\t\t5.)isEmpty" << endl;
        cout << "\t\t6.)Top" << endl;
        cout << "\t\t7.)Display" << endl;
        cout << "\t\t8.)Exit\n"
             << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter the number to be pushed: ";
            cin >> num;

            try
            {
                Stk1.push(num);
            }
            catch (StackFull &err)
            {
                cout << "\nOverflow: Stack Is Full" << endl;
                flag = true;
                break;
            }

            cout << "Element Pushed" << endl;
            flag = true;
            break;

        case 2:
            try
            {
                Stk1.pop();
            }
            catch (StackEmpty &err)
            {
                cout << "\nUnderflow: Stack Is Empty" << endl;
                flag = true;
                break;
            }

            cout << "\nTop Element Poped." << endl;

            flag = true;
            break;

        case 3:
            cout << "\nStack Cleared." << endl;
            Stk1.clear();
            flag = true;
            break;

        case 4:
            cout << "\nCurrent size of Stack: " << Stk1.size() << endl;
            flag = true;
            break;

        case 5:
            if (Stk1.isEmpty())
                cout << "\nStack is empty." << endl;
            else
                cout << "\nStack is not empty" << endl;

            flag = true;
            break;

        case 6:
            try
            {
                num = Stk1.top();
            }
            catch (StackEmpty &err)
            {
                cout << "\nError: No elements in Stack" << endl;
                flag = true;
                break;
            }

            cout << "Element at the top of Stack: " << num << endl;

            flag = true;
            break;

        case 7:
            cout << "\nCurrent Stack: " << endl;

            try
            {
                Stk1.display();
            }
            catch (StackEmpty &err)
            {
                cout << "\nError: Stack Is Empty" << endl;
                flag = true;
                break;
            }

            flag = true;
            break;

        case 8:
            flag = false;
            break;

        default:
            cout << "\nWrong Input Try Again";
            flag = true;
            break;
        }
    } while (flag);
}
