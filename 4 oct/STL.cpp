

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>

using namespace std;

void menu()
{
    cout<<"\n------MENU------"<<endl;
    cout<<"1. Vector"<<endl;
    cout<<"2. List"<<endl;
    cout<<"3. Queue"<<endl;
    cout<<"4. Dqueue"<<endl;
    cout<<"5. Stack"<<endl;
    cout<<"6. Exit"<<endl;
}

void menu_1()
{
    cout<<"\n----MENU (VECTOR)-----"<<endl;
    cout<<"1. Create a vector with space for 'n' elements"<<endl;
    cout<<"2. Print size"<<endl;
    cout<<"3. Check whether vector is empty or not"<<endl;
    cout<<"4. Resize"<<endl;
    cout<<"5. Reserve"<<endl;
    cout<<"6. Return reference of ith element (using [i])"<<endl;
    cout<<"7. Return reference to ith element (using at(i))"<<endl;
    cout<<"8. Return first element"<<endl;
    cout<<"9. Return last element"<<endl;
    cout<<"10. Push an element to last"<<endl;
    cout<<"11. Pop an element from last"<<endl;
    cout<<"12. Display all elements"<<endl;
    cout<<"13. Return to previous menu"<<endl;
}

void menu_2()
{
    cout<<"\n----MENU (LIST)-----"<<endl;
    cout<<"1. Create a list with space for 'n' elements"<<endl;
    cout<<"2. Print size"<<endl;
    cout<<"3. Check whether list is empty or not"<<endl;
    cout<<"4. Print first element"<<endl;
    cout<<"5. Print last element"<<endl;
    cout<<"6. Insert element at front"<<endl;
    cout<<"7. Insert element at back"<<endl;
    cout<<"8. Remove first element"<<endl;
    cout<<"9. Remove last element"<<endl;
    cout<<"10. Display all element"<<endl;
    cout<<"11. Return to previous menu"<<endl;
}

void menu_3()
{
    cout<<"\n----MENU (QUEUE)-----"<<endl;
    cout<<"1. Print size"<<endl;
    cout<<"2. Check if queue is empty or not"<<endl;
    cout<<"3. Enqueue"<<endl;
    cout<<"4. Dequeue"<<endl;
    cout<<"5. Print front element"<<endl;
    cout<<"6. Print rear element"<<endl;
    cout<<"7. Display all elements"<<endl;
    cout<<"8. Return to previous menu"<<endl;
}

void menu_4()
{
    cout<<"\n----MENU (DEQUE)-----"<<endl;
    cout<<"1. Print size"<<endl;
    cout<<"2. Check if empty or not"<<endl;
    cout<<"3. Push front"<<endl;
    cout<<"4. Push back"<<endl;
    cout<<"5. Pop front"<<endl;
    cout<<"6. Pop back"<<endl;
    cout<<"7. Print front element"<<endl;
    cout<<"8. Print rear element"<<endl;
    cout<<"9. Display all elements"<<endl;
    cout<<"10. Return to previous menu"<<endl;
}

void menu_5()
{
    cout<<"\n----MENU (STACK)----"<<endl;
    cout<<"1. Get size of stack"<<endl;
    cout<<"2. Check if stack is empty"<<endl;
    cout<<"3. Push an element "<<endl;
    cout<<"4. Pop an element"<<endl;
    cout<<"5. Print top of stack"<<endl;
    cout<<"6. Display stack"<<endl;
    cout<<"7. Return to previous menu"<<endl;

}
 
void stack_choice()
{
    int choice;
    stack<int> stck, temp;
    do
    {
        cout<<"Enter your choice: ";
        cin>>choice;
        
        switch(choice) {
            case 1:
            cout<<stck.size()<<endl;
            break;
            
            case 2:
            if(stck.empty()== true)
            {
                cout<<"Stack is empty"<<endl;
                break;
            }
            else
            {
               cout<<"Stack is not empty"<<endl;
               break;
            }
            
            case 3:
            int el;
            cout<<"Enter the element to be pushed: ";
            cin>>el;
            stck.push(el);
            break;
            
            case 4:
            cout<<"Element popped out is: ";
            cout<<stck.top()<<endl;
            stck.pop();
            break;
            
            case 5:
            if(stck.empty())
                cout<<"Stack is empty"<<endl;
            else
                cout<<"Top of stack: "<<stck.top()<<endl;
            break;
            
            case 6:
                temp = stck;
                while(!temp.empty())
                {
                    cout<<temp.top()<<" ";
                    temp.pop();
                }
            cout<<endl;
            break;
            
            case 7:
                menu();
        }
    }while(true);
}

void queue_choice()
{
    int choice;
    queue<int> q, temp;
    do
    {
        cout<<"Enter your choice: ";
        cin>>choice;
        
        switch(choice) {
            case 1:
            cout<<q.size()<<endl;
            break;
            
            case 2:
            if(q.empty()== true)
            {
                cout<<"Queue is empty"<<endl;
                break;
            }
            else
            {
               cout<<"Queue is not empty"<<endl;
               break;
            }
            
            case 3:
            int el;
            cout<<"Enter the element to be pushed: ";
            cin>>el;
            q.push(el);
            break;
            
            case 4:
            cout<<"Element popped out is: ";
            cout<<q.front()<<endl;
            q.pop();
            break;
            
            case 5:
            if(q.empty())
                cout<<"Queue is empty"<<endl;
            else
                cout<<"Front of queue: "<<q.front()<<endl;
            break;
            
            case 6:
                if(q.empty())
                    cout<<"Queue is empty"<<endl;
                else
                    cout<<"Rear of queue: "<<q.back()<<endl;
                break;
            
            case 7:
                temp = q;
                while(!temp.empty())
                {
                    cout<<temp.front()<<" ";
                    temp.pop();
                }
            cout<<endl;
            break;
                
            case 8:
                menu();
        }
    }while(true);
}

void vector_choice()
{
    int choice, n, i;
    vector<int> vec, temp;
    do
    {
        cout<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        
        switch(choice) {
            case 1:
                cout<<"Enter size: ";
                cin>>n;
                vec.resize(n);
            break;
            
            case 2:
                cout<<vec.size();
                break;
                
            case 3:
            if(vec.empty()== true)
            {
                cout<<"Vector is empty"<<endl;
                break;
            }
            else
            {
               cout<<"Vector is not empty"<<endl;
               break;
            }
            
            case 4:
                cout<<"Enter new size: ";
                cin>>n;
                vec.resize(n);
                break;
            
            case 5:
                cout<<"Enter size to be reserved: ";
                cin>>n;
                vec.reserve(n);
                break;
            
            case 6:
                cout<<"Enter value of i: ";
                cin>>i;
                cout<<vec[i];
                break;
            
            case 7:
                cout<<"Enter value of i: ";
                cin>>i;
                cout<<vec.at(i);
                break;
            
            case 8:
                cout<<vec.front();
                cout<<endl;
                break;
                
            case 9:
                cout<<vec.back();
                cout<<endl;
                break;
                
            case 10:
                cout<<"Enter element to be pushed: ";
                cin>>i;
                vec.push_back(i);
                break;
                
            case 11:
                vec.pop_back();
                break;
                
            case 12:
                for(int i= 0; i< vec.size(); i++)
                    cout<<vec[i]<<" ";
                
            case 13:
                menu();
                break;
        }
    }while(true);
}

void list_choice()
{
    int choice, n, i;
    list<int> l, temp;
    do
    {
        cout<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        
        switch(choice) {
            case 1:
                cout<<"Enter size: ";
                cin>>n;
                l.resize(n);
            break;
            
            case 2:
                cout<<l.size();
                break;
                
            case 3:
            if(l.empty()== true)
            {
                cout<<"List is empty"<<endl;
                break;
            }
            else
            {
               cout<<"List is not empty"<<endl;
               break;
            }
            
            case 4:
                cout<<l.front()<<endl;
                break;
            
            case 5:
                cout<<l.back()<<endl;
                break;
            
            case 6:
                cout<<"Enter value of element: ";
                cin>>i;
                l.push_front(i);
                break;
            
            case 7:
                cout<<"Enter value of element: ";
                cin>>i;
                l.push_back(i);
                break;
            
            case 8:
                l.pop_front();
                break;
                
            case 9:
                l.pop_back();
                break;
                
            case 10:
                for (auto it = l.cbegin(); it != l.cend(); it++) {
                        cout << *it <<" ";
                    }
                
            case 11:
                menu();
                break;
        }
    }while(true);
}

void deque_choice()
{
    int choice;
    deque<int> dq, temp;
    
    do
    {
        cout<<"Enter your choice: ";
        cin>>choice;
        
        switch(choice) {
            case 1:
            cout<<dq.size()<<endl;
            break;
            
            case 2:
            if(dq.empty()== true)
            {
                cout<<"Deque is empty"<<endl;
                break;
            }
            else
            {
               cout<<"Deque is not empty"<<endl;
               break;
            }
            
            case 3:
            int el;
            cout<<"Enter the element to be pushed: ";
            cin>>el;
            dq.push_front(el);
            break;
            
            case 4:
            cout<<"Enter element to be pushed: ";
            cin>>el;
                dq.push_back(el);
            break;
            
            case 5:
            if(dq.empty())
                cout<<"Queue is empty"<<endl;
            else
                dq.pop_front();
            break;
            
            case 6:
                if(dq.empty())
                    cout<<"Queue is empty"<<endl;
                else
                    dq.pop_back();
                break;
            
            case 7:
                if(dq.empty())
                    cout<<"Queue is empty"<<endl;
                else
                    cout<<dq.front();
                break;
                
            case 8:
                if(dq.empty())
                    cout<<"Queue is empty"<<endl;
                else
                    cout<<dq.back();
                break;
                
            case 9:
                temp = dq;
                while(!temp.empty())
                {
                    cout<<temp.front()<<" ";
                    temp.pop_front();
                }
            cout<<endl;
            break;
                
            case 10:
                menu();
                
        }
    }while(true);
}

int main()
{
    int choice;
    menu();
    cout<<"Enter choice: ";
    cin>>choice;
    
    switch(choice)
    {
        case 1:
            menu_1();
            vector_choice();
            break;
            
        case 2:
            menu_2();
            list_choice();
            break;

        case 3:
            menu_3();
            queue_choice();
            break;
            
        case 4:
            menu_4();
            deque_choice();
            break;
            
        case 5:
            menu_5();
            stack_choice();
            break;
            
        case 6:
            exit(1);
            
    }

}
