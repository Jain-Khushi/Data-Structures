#include<iostream>
using namespace std;

class illegalSymmetricParameterValue : public exception
{
    public:
        const char *what() const throw()
        {
            return "Matrix size must be > 0";
        }
};

class symmetricmatrixIndexOutOfBounds : public exception
{
    public:
        const char *what() const throw()
        {
            return "Index out of bounds!";
        }
};


template<class T>
class symmetricMatrix
{
    public:
        symmetricMatrix(int n1 = 4);
        ~symmetricMatrix()
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
symmetricMatrix<T> :: symmetricMatrix(int n1)
{
    if(n1 < 1)
    {
        throw illegalSymmetricParameterValue();
    }
    n2 = n1;
    element = new T[n2];
}

template<class T>
T symmetricMatrix<T> :: get(int i, int j) const
{
    if(i < 1 || j < 1 || i > n2 || j > n2)
    {
        throw symmetricmatrixIndexOutOfBounds();
    }
    if(i >= j)
    {
        return element[i * (i - 1) / 2 + j - 1];
    }
    else
    {
        return element[j * (j - 1) / 2 + i - 1];
    }
}

template<class T>
void symmetricMatrix<T> :: set(int i, int j, const T& newValue)
{
    if(i < 1 || j < 1 || i > n2 || j > n2)
    {
        throw symmetricmatrixIndexOutOfBounds();
    }
    if(i >= j)
    {
        element[i * (i - 1) / 2 + j - 1] = newValue;
    }
    else
    {
        element[j * (j - 1) / 2 + i - 1] = newValue;   
    }
}

template<class T>
void symmetricMatrix<T> :: input()
{
    T val;
    cout<<"Enter the elements of the Symmetric Matrix: ";
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
void symmetricMatrix<T> :: display()
{
    cout<<"Elements of Symmetric Matrix: "<<endl;
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


