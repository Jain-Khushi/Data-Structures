#include<iostream>
using namespace std;

class illegalupperParameterValue : public exception
{
    public:
        const char *what() const throw()
        {
            return "Matrix size must be > 0";
        }
};

class illegalupperMatrix : public exception
{
    public:
        const char *what() const throw()
        {
            return "Elements not in upper triangle must be zero";
        }
};

class uppermatrixIndexOutOfBounds : public exception
{
    public:
        const char *what() const throw()
        {
            return "Index out of bounds!";
        }
};


template<class T>
class upperTriMatrix
{
    public:
        upperTriMatrix(int n1 = 4);
        ~upperTriMatrix()
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
upperTriMatrix<T> :: upperTriMatrix(int n1)
{
    if(n1 < 1)
    {
        throw illegalupperParameterValue();
    }
    n2 = n1;
    element = new T[n2];
}

template<class T>
T upperTriMatrix<T> :: get(int i, int j) const
{
    if(i < 1 || j < 1 || i > n2 || j > n2)
    {
        throw uppermatrixIndexOutOfBounds();
    }
    if(j >= i)
    {
        return element[j * (j - 1) / 2 + i - 1];
    }
    else
    {
        return 0;
    }
}

template<class T>
void upperTriMatrix<T> :: set(int i, int j, const T& newValue)
{
    if(i < 1 || j < 1 || i > n2 || j > n2)
    {
        throw uppermatrixIndexOutOfBounds();
    }
    if(j >= i)
    {
        element[j * (j - 1) / 2 + i - 1] = newValue;
    }
    else
    {
        if(newValue != 0)
        {
            throw illegalupperMatrix();
        }
    }
}

template<class T>
void upperTriMatrix<T> :: input()
{
    T val;
    cout<<"Enter the elements of the Upper Triangular Matrix: ";
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
void upperTriMatrix<T> :: display()
{
    cout<<"Elements of Upper Triangular Matrix: "<<endl;
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



