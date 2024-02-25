#include <iostream>
#include <stdexcept>

using namespace std;

class ArrayVector
{
private:
    int capacity;
    int n;
    int *A;

public:
    ArrayVector() : capacity(5), n(0), A(new int[n]) {}

    ArrayVector(ArrayVector &v2)
    {
        capacity = v2.capacity;
        n = v2.n;
        A = new int[capacity];
        for (int j = 0; j < v2.n; j++)
            A[j] = v2.A[j];
    }

    ~ArrayVector()
    {
        delete[] A;
    }

    void operator=(ArrayVector &v2)
    {
        A = v2.A;
        n = v2.n;
    }

    int size() const
    {
        return n;
    }

    bool empty() const
    {
        return (size() == 0);
    }

    int &operator[](int i)
    {
        return A[i];
    }

    int &at(int i)
    {
        if (i < 0 || i >= n)
            throw std::out_of_range("\nIllegal parameter !");

        return A[i];
    }

    void erase(int i)
    {
        for (int j = i + 1; j < n; j++)
            A[j - 1] = A[j];
        n--;
    }

    void push(int el)
    {
        insert(n + 1, el);
    }

    void insert(int i, const int &e)
    {
        if (n >= capacity)
            reserve(max(1, 2 * capacity));
        for (int j = n - 1; j >= i - 1; j--)
            A[j + 1] = A[j];
        A[i - 1] = e;
        n++;
    }

    void reserve(int N)
    {
        if (capacity >= N)
            return;
        int *B = new int[N];
        for (int j = 0; j < n; j++)
            B[j] = A[j];
        if (A != NULL)
            delete[] A;
        A = B;
        capacity = N;
    }

    void print()
    {
        cout << "\nThe contents of the vector are:\n";
        for (int i = 0; i < n; i++)
            cout << A[i] << " ";
    }
};

int main()
{
    int ch, pos, el;
    ArrayVector v1, v2;

    do
    {
        cout << "\n   *MENU*   ";
        cout << "\n1.SIZE ?";
        cout << "\n2.EMPTY ?";
        cout << "\n3.Use at()";
        cout << "\n4.Print value at index x Using [] operator";
        cout << "\n5.Print value at index x Using  = operator";
        cout << "\n6.Insert Element ";
        cout << "\n7.Insert Element at logical position";
        cout << "\n8.Erase Element from index position";
        cout << "\n9.Display";
        cout << "\n10.Exit";
        cout << "\nEnter Choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nSize is: " << v1.size();
            break;
        case 2:
            if (v1.empty())
                cout << "\nThe vector is empty !";
            else
                cout << "\nThe vector is NOT empty !";
            break;
        case 3:
            try
            {
                cout << "\nEnter the position: ";
                cin >> pos;
                cout << "Element at position " << pos << " is: " << v1.at(pos);
            }
            catch (std::exception &e)
            {
                cout << e.what() << endl;
            }
            break;
        case 4:
            cout << "\nEnter the position: ";
            cin >> pos;
            cout << "Element at position " << pos << " is: " << v1[pos];
            break;
        case 5:
            v2 = v1;
            v2.print();
            break;
        case 6:
            cout << "Enter the element to be inserted: ";
            cin >> el;
            v1.push(el);
            break;
        case 7:
            cout << "Enter the element to be inserted: ";
            cin >> el;
            cout << "Enter the position to be inserted at: ";
            cin >> pos;
            v1.insert(pos, el);
            break;
        case 8:
            cout << "Enter the index position to be erased: ";
            cin >> pos;
            v1.erase(pos);
            break;
        case 9:
            v1.print();
            break;
        case 10:
            cout << "\nExiting...";
            break;
        default:
            cout << "Invalid choice !";
        }

    } while (ch != 10);
    return 0;
}