#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node *left, *right;
	bool rightThread = false;
};

Node *newNode(int value)
{
	Node *temp = new Node;
    	temp->left = temp->right = NULL;
    	temp->data = value;
    	return temp;
}

Node *leftmost(Node *root)
{
   	while (root != NULL && root->left != NULL)
        {
		root = root->left;
	}
    	return root;
}

void reverseInorder(Node *root, Node *prev)
{
	if(root==NULL)
		return;
	else
	{
		reverseInorder(root->right, prev);
		if(root->right == NULL && prev != NULL)
		{
			root->right = prev;
			root->rightThread = true;
		}
		reverseInorder(root->left, root);
	}
}

void convert(Node *root)
{
	reverseInorder(root, NULL);
}

void print(Node *root)
{
    	if (root == NULL) 
 		return;
 
    	Node *current = leftmost(root);
 	while (current != NULL)
    	{
        	cout << current->data << " ";
 
       		// If this Node is threaded Node, then go to inorder successor
        	if (current -> rightThread)
         		current = current -> right;
 
       		// Or go to the leftmost child in right subtree
        	else 
            		current = leftmost(current->right);
    	}
}
int main()
{
   	Node* root = newNode(5); 
	root->left = newNode(2); 
	root->right = newNode(7); 
	root->left->left = newNode(1); 
	root->left->right = newNode(4); 
	root->right->left = newNode(6); 
	root->right->right = newNode(9);
 
    	convert(root);
 
    	cout << "Inorder traversal of created threaded binary tree is \n";
    	print(root);
    	return 0;
}