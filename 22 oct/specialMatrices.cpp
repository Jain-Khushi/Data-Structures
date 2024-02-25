#include<iostream>
#include "diagonalMatrix.cpp"
#include "tridiagonalMatrix.cpp"
#include "upperTriMatrix.cpp"
#include "lowerTriMatrix.cpp"
#include "symmetricMatrix.cpp"
using namespace std;


int main()
{
    diagonalMatrix<int> dM;
    tridiagonalMatrix<int> tdM;
    upperTriMatrix<int> utM;
    lowerTriMatrix<int> ltM;
    symmetricMatrix<int> sM;


    int choice;
    do
    {
    cout<<"-=-=-=-=-=-=-=-=-SPECIAL MATRICES-=-=-=-=-=-=-=-"<<endl;
    cout<<"1. Diagonal Matrix"<<endl;
    cout<<"2. Tridiagonal Matrix"<<endl;
    cout<<"3. Upper Triangular Matrix"<<endl;
    cout<<"4. Lower Triangular Matrix"<<endl;
    cout<<"5. Symmetric Matrix"<<endl;
    cout<<"6. Exit"<<endl;
    cout<<"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice){
        case 1: 
            dM.input();
            cout<<endl;
            dM.display();
            cout<<endl;
            break;
            
        case 2:
            tdM.input();
            cout<<endl;
            tdM.display();
            cout<<endl;
            break;
            
        case 3:
            utM.input();
            cout<<endl;
            utM.display();
            cout<<endl;
            break;

        case 4:
            ltM.input();
            cout<<endl;
            ltM.display();
            cout<<endl;
            break;

         case 5:
            sM.input();
            cout<<endl;
            sM.display();
            cout<<endl;
            break; 

        case 6:
            cout<<"Exiting..."<<endl;
            exit(0); 

        } 
    } while(choice != 6);
    
return 0;
}

