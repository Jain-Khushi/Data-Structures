#include<iostream>
using namespace std;

class illegaldiagonalParameterValue : public exception
{
    public:
        const char *what() const throw()
        {
            return "Matrix size must be > 0";
        }
};

class illegalDMatrix : public exception
{
    public:
        const char *what() const throw()
        {
            return "Non Diagonal Elements must be zero";
        }
};

class diagonalmatrixIndexOutOfBounds : public exception
{
    public:
        const char *what() const throw()
        {
            return "Index out of bounds!";
        }
};


template<class T>
class diagonalMatrix
{
    public:
        diagonalMatrix(int n1 = 4);
        ~diagonalMatrix()
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
diagonalMatrix<T> :: diagonalMatrix(int n1)
{
    if(n1 < 1)
    {
        throw illegaldiagonalParameterValue();
    }
    n2 = n1;
    element = new T[n2];
}

template<class T>
T diagonalMatrix<T> :: get(int i, int j) const
{
    if(i < 1 || j < 1 || i > n2 || j > n2)
    {
        throw diagonalmatrixIndexOutOfBounds();
    }
    if(i == j)
    {
        return element[i - 1];
    }
    else
    {
        return 0;
    }
}

template<class T>
void diagonalMatrix<T> :: set(int i, int j, const T& newValue)
{
    if(i < 1 || j < 1 || i > n2 || j > n2)
    {
        throw diagonalmatrixIndexOutOfBounds();
    }
    if(i == j)
    {
        element[i - 1] = newValue;
    }
    else
    {
        if(newValue != 0)
        {
            throw illegalDMatrix();
        }
    }
}

template<class T>
void diagonalMatrix<T> :: input()
{
    T val;
    cout<<"Enter the elements of the Diagonal Matrix: ";
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
void diagonalMatrix<T> :: display()
{
    cout<<"Elements of Diagonal Matrix: "<<endl;
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



