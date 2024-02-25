#include<iostream>
using namespace std;

class illegallowerParameterValue : public exception
{
    public:
        const char *what() const throw()
        {
            return "Matrix size must be > 0";
        }
};

class illegallowerMatrix : public exception
{
    public:
        const char *what() const throw()
        {
            return "Elements not in lower triangle must be zero";
        }
};

class lowermatrixIndexOutOfBounds : public exception
{
    public:
        const char *what() const throw()
        {
            return "Index out of bounds!";
        }
};


template<class T>
class lowerTriMatrix
{
    public:
        lowerTriMatrix(int n1 = 4);
        ~lowerTriMatrix()
        {
            delete [] element;
        }
        T get(int, int) const;
        void set(int, int, const T&);
        void input();
        void display();

    private:
        int n2;
        T *element;
};

template<class T>
lowerTriMatrix<T> :: lowerTriMatrix(int n1)
{
    if(n1 < 1)
    {
        throw illegallowerParameterValue();
    }
    n2 = n1;
    element = new T[n2];
}

template<class T>
T lowerTriMatrix<T> :: get(int i, int j) const
{
    if(i < 1 || j < 1 || i > n2 || j > n2)
    {
        throw lowermatrixIndexOutOfBounds();
    }
    if(i >= j)
    {
        return element[i * (i - 1) / 2 + j - 1];
    }
    else
    {
        return 0;
    }
}

template<class T>
void lowerTriMatrix<T> :: set(int i, int j, const T& newValue)
{
    if(i < 1 || j < 1 || i > n2 || j > n2)
    {
        throw lowermatrixIndexOutOfBounds();
    }
    if(i >= j)
    {
        element[i * (i - 1) / 2 + j - 1] = newValue;
    }
    else
    {
        if(newValue != 0)
        {
            throw illegallowerMatrix();
        }
    }
}

template<class T>
void lowerTriMatrix<T> :: input()
{
    T val;
    cout<<"Enter the elements of the Lower Triangular Matrix: ";
    for(int i = 1; i <= n2; i++)
    {
        for(int j = 1; j <= n2; j++)
        {
            cin>>val;
            set(i, j, val);
        }
    }
}

template<class T>
void lowerTriMatrix<T> :: display()
{
    cout<<"Elements of Lower Triangular Matrix: "<<endl;
    for(int i = 1; i <= n2; i++)
    {
        for(int j = 1; j <= n2; j++)
        {
            T val = get(i, j);
            cout<<val<<"\t";
        }
        cout<<endl;
    }
}


