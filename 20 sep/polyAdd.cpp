#include <iostream>
using namespace std;

template<class T>
class polynode
{
    public:
        T coeff, power;
        polynode<T> *next;

        polynode(T c, T p, polynode<T> *s = NULL)
        {
            coeff = c;
            power = p;
            next = s;

        }
};

template<class T>
class polynomial
{
    public:
        polynode<T> *head;

        polynomial()
        {
            head = NULL;
        }
        ~polynomial();
        void get_poly();
        void show_poly();
        void add_poly(polynomial &p1, polynomial &p2, polynomial &p3);
        void add_tail(T c, T p);
};

//Destructor
template<class T>
polynomial<T> :: ~polynomial()
{
    polynode<T> *p;
    while(head != NULL)
    {
        p = head -> next;
        delete head;
        head = p;
    }
}

template<class T>
void polynomial<T> :: get_poly()
{
    int n1;
    cout << "Enter the number of terms in a polynomial: ";
    cin >> n1;

    for (int i = 0; i < n1; i++)
    {
        int coeff, exp;
        cout << "Enter " << i + 1 << " coefficient and exponent of a polynomial(separated by space): ";
        cin >> coeff >> exp;
        add_tail(coeff, exp);
    }
} 

template<class T>
void polynomial<T> :: add_tail(T c, T p)
{
    if(head == NULL)
    {
        head = new polynode<T>(c, p, head);
    }

    else
    {
        polynode<T> *temp = head;
        polynode<T> *n = new polynode<T>(c, p);
        while (temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = n;
        n -> next = NULL;
    } 
}

template<class T>
void polynomial<T> :: show_poly()
{
    polynode<T> *temp = head;
    int f = 0;
    while(temp != NULL)
    {
        if(f != 0)
        {
            if(temp -> coeff > 0)
            {
                cout<<" + ";
            }
            else
            {
                cout<<" ";
            }
        }
        if(temp -> power != 0)
        {
            cout<<temp -> coeff<< "x^"<<temp -> power;
        }
        else
        {
            cout<<temp -> coeff;
        }
        temp = temp -> next;
        f = 1;
    }
}

template <class T>
void polynomial<T> :: add_poly(polynomial &p1, polynomial &p2, polynomial &p3)
{
    if (p1.head == NULL && p2.head == NULL)
    {
        return;
    }
    polynode<T> *temp1 = p1.head;
    polynode<T> *temp2 = p2.head;
    polynode<T> *temp = p3.head;

    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1 -> power > temp2 -> power)
        {
            p3.add_tail(temp1 -> coeff, temp1 -> power);
            temp1 = temp1 -> next;
        }

        else if(temp1 -> power < temp2 -> power)
        {
            p3.add_tail(temp2 -> coeff, temp2 -> power);
            temp2 = temp2 -> next;
        }

        else
        {
            p3.add_tail((temp1 -> coeff + temp2 -> coeff), temp1 -> power);
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
    
        if(temp1 == NULL)
        {
            while(temp2 != NULL)
            {
                p3.add_tail(temp2 -> coeff, temp2 -> power);
                temp2 = temp2 -> next;
            }
        }
        if(temp2 == NULL)
        {
            while(temp1 != NULL)
            {
                p3.add_tail(temp1 -> coeff, temp1 -> power);
                temp1 = temp1 -> next;
            }
        }
    } 
}

int main()
{
    polynomial<int> S1;
    polynomial<int> S2;
    polynomial<int> S3;

    S1.get_poly();
    cout<<"First Polynomial: ";
    S1.show_poly();
    cout<<endl;

    S2.get_poly();
    cout<<"Second Polynomial: ";
    S2.show_poly();
    cout<<endl;

    cout<<"Resultant Polynomial: ";
    S3.add_poly(S1, S2, S3);
    S3.show_poly();

    return 0;
}
