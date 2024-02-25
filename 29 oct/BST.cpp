#include <iostream>
using namespace std;

template < typename T>

	class BstNode
	{
		public:

			BstNode<T> *left;
		BstNode<T> *right;
		T val;

		BstNode(T el, BstNode<T> *ptr1 = NULL, BstNode<T> *ptr2 = NULL)
		{
			left = ptr1;
			right = ptr2;
			val = el;
		}
	};

template < typename T>

	class BST
	{
		BstNode<T> *root;

		protected:

			void deleteByMerging(BstNode<T> *& p)
			{
				BstNode<T> *temp = p;

				if (p != 0)
				{
					if (!p->right)
					{
						p = p->left;
					}
					else if (p->left == 0)
					{
						p = p->right;
					}
					else
					{
						temp = p->left;
						while (temp->right != NULL)
							temp = temp->right;

						temp->right = p->right;
						temp = p;
						p = p->left;

					}

					delete temp;

				}
			}

		void deleteByCopying(BstNode<T> *& p)
		{
			BstNode<T> *temp = p;
			BstNode<T> *prev = NULL;

			if (p != 0)
			{
				if (!p->right)
				{
					p = p->left;
				}
				else if (p->left == 0)
				{
					p = p->right;
				}
				else
				{
					temp = p->left;
					prev = p;
					while (temp->right != NULL)
					{
						prev = temp;
						temp = temp->right;
					}

					p->val = temp->val;

					if (prev == p)
						prev->left = temp->left;
					else
						prev->right = temp->left;

				}

				delete temp;

			}
		}

		void visit(BstNode<T> *p)
		{
			cout << p->val << "   ";
		}

		void preorder(BstNode<T> *p)
		{
			if (p != NULL)
			{
				visit(p);
				preorder(p->left);
				preorder(p->right);
			}
		}

		void postorder(BstNode<T> *p)
		{
			if (p != NULL)
			{
				postorder(p->left);
				postorder(p->right);
				visit(p);
			}
		}

		void Inorder(BstNode<T> *p)
		{
			if (p != NULL)
			{
				Inorder(p->left);
				visit(p);
				Inorder(p->right);
			}
		}

		void FindForDeleteByMerging(T el)
		{
			BstNode<T> *ptr = root;
			BstNode<T> *prev = NULL;

			while (ptr != 0)
			{
				if (ptr->val == el)
				{
					break;
				}

				prev = ptr;

				if (ptr->val < el)
					ptr = ptr->right;
				else
					ptr = ptr->left;

			}

			if (ptr != 0 && ptr->val == el)
			{
				if (ptr == root)
				{
					deleteByMerging(root);
				}
				else if (ptr == prev->right)
				{
					deleteByMerging(prev->right);
				}
				else if (ptr == prev->left)
				{
					deleteByMerging(prev->left);
				}
			}
			else if (ptr == 0)
				cout << "node not found" << endl;

		}

		void FindForDeleteByCopying(T el)
		{
			BstNode<T> *ptr = root;
			BstNode<T> *prev = NULL;

			while (ptr != 0)
			{
				if (ptr->val == el)
				{
					break;
				}

				prev = ptr;

				if (ptr->val < el)
					ptr = ptr->right;
				else
					ptr = ptr->left;

			}

			if (ptr != 0 && ptr->val == el)
			{
				if (ptr == root)
				{
					deleteByCopying(root);
				}
				else if (ptr == prev->right)
				{
					deleteByCopying(prev->right);
				}
				else if (ptr == prev->left)
				{
					deleteByCopying(prev->left);
				}
			}
			else if (ptr == 0)
				cout << "node not found" << endl;

		}

		public:

			BST()
			{
				root = NULL;
			}

		void insert(const T &el)
		{
			if (root == NULL)
				root = new BstNode<T> (el, NULL, NULL);

			else
			{
				BstNode<T> *ptr = root;
				BstNode<T> *prev = NULL;

				while (ptr != NULL)
				{
					prev = ptr;
					if (el > ptr->val)
						ptr = ptr->right;
					else if (el < ptr->val)
						ptr = ptr->left;
				}

				if (prev->val < el)
				{
					prev->right = new BstNode<T> (el, NULL, NULL);
				}
				else
					prev->left = new BstNode<T> (el, NULL, NULL);

			}
		}

		void display()
		{
			if (root == NULL)
				cout << "Sorry can't display from empty tree" << endl;

			int choice;
			do {
				cout << "\n\n\n\t\tMENU: FOR DISPLAY\n";
				cout << "\nchoose 1. For Preorder\n";
				cout << "\nchoose 2. For Postorder\n";
				cout << "\nchoose 3. For Inorder\n";
				cout << "\nchoose 4.To return from function\n";

				cout << "\n\nEnter your choice : ";
				cin >> choice;

				switch (choice)
				{
					case 1:
						preorder(root);
						break;
					case 2:
						postorder(root);
						break;
					case 3:
						Inorder(root);
						break;
					case 4:
						break;

					default:
						cout << "\nINVALID CHOICE\n";
				}

				if (choice == 4)
					break;
			} while (choice >= 0);

		}

		void Search_Replace(T el, T replaceWith)
		{
			if (root == NULL)
				cout << "Sorry can't search from empty tree" << endl;

			BstNode<T> *ptr = root;
			BstNode<T> *prev = NULL;

			while (ptr != 0)
			{
				if (ptr->val == el)
				{
					break;
				}

				prev = ptr;

				if (ptr->val < el)
					ptr = ptr->right;
				else
					ptr = ptr->left;

			}

			if (ptr != 0 && ptr->val == el)
			{
				if (ptr == root)
				{
					deleteByMerging(root);
				}
				else if (ptr == prev->right)
				{
					deleteByMerging(prev->right);
				}
				else if (ptr == prev->left)
				{
					deleteByMerging(prev->left);
				}

				insert(replaceWith);
			}
			else if (ptr == 0)
				cout << "node not found" << endl;

		}

		void deletion()
		{
			if (root == NULL)
				cout << "Sorry can't delete from empty tree" << endl;

			int choice;
			T el;
			do {
				cout << "\n\n\n\t\tMENU: FOR DELETION\n";
				cout << "\nchoose 1. For Delete By copying\n";
				cout << "\nchoose 2. For Delete By Merging\n";
				cout << "\nchoose 3.To return from function\n";

				cout << "\n\nEnter your choice : ";
				cin >> choice;

				switch (choice)
				{
					case 1:
						cout << "\nEnter the node you want to delete: ";
						cin >> el;
						FindForDeleteByCopying(el);
						break;

					case 2:
						cout << "\nEnter the node you want to delete: ";
						cin >> el;
						FindForDeleteByMerging(el);
						break;
					case 3:
						break;

					default:
						cout << "\nINVALID CHOICE\n";
				}

				if (choice == 3)
					break;
			} while (choice >= 0);

		}
	};

int main()
{
	BST<int> obj;
	int choice;
	int el, val;
	do {
		cout << "\n\t\tMAIN MENU\n";
		cout << "\nchoose 1. For INSERT\n";
		cout << "\nchoose 2. For DELETE\n";
		cout << "\nchoose 3.For SEARCH AND REPLACE\n";
		cout << "\nchoose 4. For DISPLAY\n";
		cout << "\nchoose 5. For exit\n";

		cout << "\n\nEnter your choice : ";
		cin >> choice;

		switch (choice)
		{
			case 1:
				cout << "\n\nEnter the node you want to Insert: ";
				cin >> el;
				obj.insert(el);
				break;

			case 2:
				obj.deletion();
				break;

			case 3:
				cout << "\n\nEnter the node you want to search: ";
				cin >> el;
				cout << "\n\nEnter the node you want to replace with: ";
				cin >> val;
				obj.Search_Replace(el, val);
				break;

			case 4:
				obj.display();
				break;

			case 5:
				exit(1);
				break;

			default:
				cout << "\nINVALID CHOICE\n";
		}
	} while (choice >= 0);

	return 0;
}
