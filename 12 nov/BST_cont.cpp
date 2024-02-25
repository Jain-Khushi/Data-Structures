#include<iostream>
#include<stack>
#include<queue>
using namespace std;

template<class T>
class BSTNode
{
    public:
        T key;
        BSTNode *left, *right;

        BSTNode()
        {
            left = right = 0;
        }

        BSTNode(const T &el, BSTNode *l = 0, BSTNode *r = 0)
        {
            key = el;
            left = l;
            right = r;
        }
};

template<class T>
class BST
{
    BSTNode<T> *root;
    T search(BSTNode<T>*, const T&, const T&)const;
    void preorder(BSTNode<T>*);
    void inorder(BSTNode<T>*);
    void postorder(BSTNode<T>*);
    void clear(BSTNode<T>*);
    void visit(BSTNode<T>* p)
    {
        cout<<p -> key<<" ";
    }
    public:
        BST()
        {
            root = 0;
        }
        ~BST()
        {
            clear();
        }
        void clear()
        {
            clear(root);
            root = 0;
        }
        bool isEmpty() const
        {
            return (root == 0);
        }
        void preorder()
        {
            preorder(root);
        }
        void inorder()
        {
            inorder(root);
        }
        void postorder()
        {
            postorder(root);
        }
        T search(const T& el1, const T& el2) const
        {
            return search(root, el1, el2);
        }
        void insert(const T&);
        void del_copy(BSTNode<T>* &n);
        int del_merge(BSTNode<T>* &n);
        void find_del_copy(const T& el);
        void find_del_merge(const T& el);    
        void breadthFirst();
        void iterativePreorder();
        void iterativePostorder();
        void iterativeInorder();
};

template<class T>
void BST<T> :: clear(BSTNode<T> *p)
{
    if(p != 0)
    {
        clear(p -> left);
        clear(p -> right);
        delete p;
    }
}

template<class T>
T BST<T> :: search(BSTNode<T> *p, const T& el1, const T& el2) const
{
    while(p != 0)
    {
        if(el1 == p -> key)
        {
            return p -> key;
        }
        else if(el1 < p -> key)
        {
            p = p -> left;
        }
        else
        {
            p = p -> right;
        }
    }
    return 0;
}

template<class T>
void BST<T> :: inorder(BSTNode<T> *p)
{
    if(p != 0)
    {
        inorder(p -> left);
        visit(p);
        inorder(p -> right);
    }
}

template<class T>
void BST<T> :: preorder(BSTNode<T> *p)
{
    if(p != 0)
    {
        visit(p);
        preorder(p -> left);
        preorder(p -> right);
    }
}

template<class T>
void BST<T> :: postorder(BSTNode<T> *p)
{
    if(p != 0)
    {
        postorder(p -> left);
        postorder(p -> right);
        visit(p);
    }
}

template<class T>
void BST<T> :: insert(const T& el)
{
    BSTNode<T> *p = root, *temp = 0;
    while(p != 0)
    {
        temp = p;
        if(el > p -> key )
        {
            p = p -> right;
        }
        else
        {
            p = p -> left;
        }
    }
    if(root == 0)
    {
        root = new BSTNode<T>(el);
    }
    else if(el > temp -> key)
    {
        temp -> right = new BSTNode<T>(el);
    }
    else
    {
        temp -> left = new BSTNode<T>(el);
    }
}

template<class T>
void BST<T> :: find_del_merge(const T& el)
{
    BSTNode<T> *node = root, *prev = 0;
    while(node != 0)
    {
        if(node -> key == el)
        {
            break;
        }
        prev = node;
        if(el < node -> key)
        {
            node = node -> left;
        }
        else
        {
            node = node -> right;
        }
    }
    if(node != 0 && node -> key == el)
    {
        if(node == root)
        {
            del_merge(root);
        }
        else if(prev -> left == node)
        {
            del_merge(prev -> left);
        }
        else
        {
            del_merge(prev -> right);
        }
    }
    else if(root != 0)
    {
        cout<<"Element "<< el <<"not found in the tree!";
    }
    else
    {
        cout<<"Oops! The tree is Empty.";
    }
}

template<class T>
int BST<T> :: del_merge(BSTNode<T> *& node)
{
    BSTNode<T> *temp = node;
    int element;
    if(node != 0)
    {
        if(!node -> right)
        {
            node = node -> left;
        }
        else if(!node -> left)
        {
            node = node -> right;
        }
        else
        {
            temp = node -> left;
            while(temp -> right != 0) 
            {
                temp = temp -> right;
            }
            temp -> right = node -> right;
            temp = node;
            element = temp -> key;
            node = node -> left;
        }
        delete temp;
        cout<<"Element "<< element <<" "<<"is deleted."<<endl;
    } 
}

template<class T>
void BST<T> :: find_del_copy(const T& el)
{
    BSTNode<T> *node = root, *prev = 0;
    while(node != 0)
    {
        if(node -> key == el)
        {
            break;
        }
        prev = node;
        if(el < node -> key)
        {
            node = node -> left;
        }
        else
        {
            node = node -> right;
        }
    }
    if(node != 0 && node -> key == el)
    {
        if(node == root)
        {
            del_copy(root);
        }
        else if(prev -> left == node)
        {
            del_copy(prev -> left);
        }
        else
        {
            del_copy(prev -> right);
        }
    }
    else if(root != 0)
    {
        cout<<"Element "<< el <<"not found in the tree!";
    }
    else
    {
        cout<<"Oops! The tree is Empty.";
    }
}

template<class T>
void BST<T> :: del_copy(BSTNode<T> *& node)
{
    BSTNode<T> *prev, *temp = node;
    if(node -> right == 0)
    {
        node = node -> left;
    }
    else if(node -> left == 0)
    {
        node = node -> right;
    }
    else
    {
        temp = node -> left;
        prev = node;
        while(temp -> right != 0)
        {
            prev = temp;
            temp = temp -> right;
        }
        node -> key = temp -> key;
        if(prev == node)
        {
            prev -> left = temp -> left;
        }
        else
        {
            prev -> right = temp -> left;
        }
    }
    delete temp;
}

template<class T>
void BST<T> :: breadthFirst()
{
    queue<BSTNode<T>*> que;
    BSTNode<T> *p = root;
    if(p != 0)
    {
        que.push(p);
        while(!que.empty())
        {
            p = que.front();
            que.pop();
            visit(p);
            if(p -> left != 0)
            {
                que.push(p -> left);
            }
            if(p -> right != 0)
            {
                que.push(p -> right);
            }
        }
    }
}

template<class T>
void BST<T> :: iterativePreorder()
{
    stack<BSTNode<T>*> pre;
    BSTNode<T> *p = root;
    if(p != 0)
    {
        pre.push(p);
        while(!pre.empty())
        {
            p = pre.top();
            pre.pop();
            visit(p);
            if(p -> right != 0)
            {
                pre.push(p -> right);
            }
            if(p -> left != 0)
            {
                pre.push(p -> left);
            }
        }
    }
}

template<class T>
void BST<T> :: iterativePostorder()
{
    stack<BSTNode<T>*> post;
    BSTNode<T> *p = root, *q;
    while(p != 0)
    {
        for(; p -> left != 0; p = p -> left)
        {
            post.push(p);
        }
        while(p -> right == 0 || p -> right == q)
        {
            visit(p);
            q = p;
            if(post.empty())
            {
                return;
            }
        }
        post.push(p);
        p  = p -> right;
    }
}

template<class T>
void BST<T> :: iterativeInorder()
{
    stack<BSTNode<T>*> in;
    BSTNode<T> *p = root;
    while(p != 0)
    {
        while(p != 0)
        {
            if(p -> right)
            {
                in.push(p -> right);
            }

            in.push(p);
            p = p -> left;
        }
    
        p = in.top();
        in.pop();
        while(!in.empty() && p -> right == 0)
        {
            visit(p);
            p = in.top();
            in.pop();
        }
        visit(p);
        if(!in.empty())
        {
            p = in.top();
            in.pop();
        }
        else
        {
            p = 0;
        }
    }
}

int main()
{
    BST<int> b;
    int i, choice, x, y;

    do 
    {
    cout<<"-=-=-=-=-=-=-=-=-BINARY SEARCH TREE-=-=-=-=-=-=-=-"<<endl;
    cout<<"1. Insert a new element x"<<endl;
    cout<<"2. Delete an element by merging"<<endl;
    cout<<"3. Delete an element by copying"<<endl;
    cout<<"4. Search for an element x and change its value to y"<<endl;
    cout<<"5. Display elements in inorder, preorder and postorder"<<endl;
    cout<<"6. Display elements in inorder, preorder and postorder (iterative) Depth First Traversal"<<endl;
    cout<<"7. Breadth First Traversal"<<endl;
    cout<<"8. Exit"<<endl;
    cout<<"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice){
        case 1: 
            cout<<"Enter an element x to insert: ";
            cin>>x;
            b.insert(x);
            cout<<"Element "<< x <<" is inserted."<<endl;
            cout<<endl;
            break;
            
        case 2:
            cout<<"Enter an element x to delete by merging: ";
            cin>>x;
            b.find_del_merge(x);
            cout<<endl;
            break;
            
        case 3:
            cout<<"Enter an element x to delete by copying: ";
            cin>>x;
            b.find_del_copy(x);
            cout<<endl;
            break;

        case 4:
            cout<<"Enter an element x to search in BST: ";
            cin>>x;
            if(b.search(x, y))
            {
                cout<<"Element "<< x <<" is found."<<endl;
                cout<<"Enter an element y to change value in BST: ";
                cin>>y;
                b.insert(y);
            }
            else
            {
                cout<<"Element "<< x <<" not found!"<<endl;
            }
            cout<<endl;
            break;


        case 5:
            cout<<"Elements in Inorder: ";
            b.inorder();
            cout<<endl;
            cout<<"Elements in Preorder: ";
            b.preorder();
            cout<<endl;
            cout<<"Elements in Postorder: ";
            b.postorder();
            cout<<endl;
            break;

        case 6:
            cout<<"Elements in Inorder: ";
            b.iterativeInorder();
            cout<<endl;
            cout<<"Elements in Preorder: ";
            b.iterativePreorder();
            cout<<endl;
            break;

        case 7:
            cout<<"Elements in Breadth First Traversal: ";
            b.breadthFirst();
            cout<<endl;
            break;

        case 8:
            cout<<"Exiting..."<<endl;
            exit(0); 

        } 
    } while(choice != 8);
    
return 0;
}


