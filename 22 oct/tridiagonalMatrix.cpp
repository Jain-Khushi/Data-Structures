#include<iostream>
using namespace std;

class illegaltriDiagonalParameterValue : public exception
{
    public:
        const char *what() const throw()
        {
            return "Matrix size must be > 0";
        }
};

class triDmatrixIndexOutOfBounds : public exception
{
    public:
        const char *what() const throw()
        {
            return "Index out of bounds!";
        }
};


template<class T>
class tridiagonalMatrix
{
    public:
        tridiagonalMatrix(int n1 = 4);
        ~tridiagonalMatrix()
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
tridiagonalMatrix<T> :: tridiagonalMatrix(int n1)
{
    if(n1 < 1)
    {
        throw illegaltriDiagonalParameterValue();
    }
    n2 = n1;
    element = new T[n2];
}

template<class T>
T tridiagonalMatrix<T> :: get(int i, int j) const
{
    if(i < 1 || j < 1 || i > n2 || j > n2)
    {
        throw triDmatrixIndexOutOfBounds();
    }
    switch(i - j)
    {
        case 1: 
            return element[i - 2];

        case 0:
            return element[n2 + i - 2];
        
        case -1:
            return element[2 * n2 + i - 2];

        default: 
            return 0;
    }
}

template<class T>
void tridiagonalMatrix<T> :: set(int i, int j, const T& newValue)
{
    if(i < 1 || j < 1 || i > n2 || j > n2)
    {
        throw triDmatrixIndexOutOfBounds();
    }
    
    switch(i - j)
    {
        case 1: 
            element[i - 2] = newValue;

        case 0:
            element[n2 + i - 2] = newValue;
        
        case -1:
            element[2 * n2 + i - 2] = newValue;
    }
}

template<class T>
void tridiagonalMatrix<T> :: input()
{
    T val;
    cout<<"Enter the elements of the TriDiagonal Matrix: ";
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
void tridiagonalMatrix<T> :: display()
{
    cout<<"Elements of TriDiagonal Matrix: "<<endl;
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


