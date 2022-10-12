#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
	int data;
	Node* left;
	Node* right;
	Node(int d)
	{
		this->data=d;
		this->left=NULL;
		this->right=NULL;
	}
};
void preOrderTraversal(Node* root)
{
	if(root==NULL)
	return;
	cout<<root->data<<" ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}
Node* prev=NULL;
Node* BinaryTreeToDLL(Node* root)
{
	if(root==NULL)
	return root;
	Node* head=BinaryTreeToDLL(root->left);
	if(prev==NULL)
	head=root;
	else
	{
		root->left=prev;
		prev->right=root;
	}
	prev=root;
	BinaryTreeToDLL(root->right);
	return head;
	
}
int main()
{
	Node* root=new Node(10);
	 root->left= new Node(5);
	 root->right=new Node(20);
	 root->right->left=new Node(30);
	 root->right->right=new Node(35);
	 cout<<"preorder traversal"<<endl;
	 preOrderTraversal(root);
	 cout<<endl;
	 Node* newRoot=BinaryTreeToDLL(root);
	 
}
