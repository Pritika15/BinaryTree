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
int height(Node* root)
{
	if(root==NULL)
	return 0;
	if(root->left==NULL && root->right==NULL)
	return 1;
	
	return 1+max(height(root->left),height(root->right));
}
bool isBalanced(Node* root)
{
	if(root==NULL)
	return true;
	if(root->left==NULL && root->right==NULL)
	return true;
	int leftTree=height(root->left);
	int rightTree=height(root->right);
	if(abs(leftTree-rightTree)<=1 && isBalanced(root->left)&& isBalanced(root->right) )
	return true;
	else
	return false;
	
}
int main()
{
//	Node* root=new Node(18);
//	 root->left= new Node(4);
//	 root->right=new Node(20);
//	 root->right->left=new Node(13);
//	 root->right->right=new Node(70);
	 Node* root=new Node(3);
	 root->left= new Node(4);
	 root->right=new Node(8);
	 root->left->left=new Node(5);
	 root->left->right=new Node(9);
	 
	 root->right->right=new Node(7);
	 root->right->right->left=new Node(6);
	 preOrderTraversal(root);
	 cout<<endl;
	 bool  BinaryTreebalanced=isBalanced(root);
	 cout<<BinaryTreebalanced<<endl;
}
