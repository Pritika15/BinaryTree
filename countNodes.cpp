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
// Method-1 TC=O(n)
//int countNodes(Node* root)
//{
//	if(root==NULL)
//	return 0;
//	if(root->left==NULL && root->right==NULL)
//	return 1;
//	
//	return 1+countNodes(root->left)+countNodes(root->right);
//}

//Method 2- Efficient Solution: Using the property of perfectly balanced Binary Tree
int countNodes(Node* root)
{
	if(root==NULL)
	return 0;
	Node* curr=root;
	int lh=0,rh=0;
	while(curr!=NULL)
	{
		lh++;
		curr=curr->left;
	}
	curr=root;
	while(curr!=NULL)
	{
		rh++;
		curr=curr->right;
	}
	if(lh==rh)
	return pow(2,lh)-1;
	else
	return 1+countNodes(root->left)+countNodes(root->right);
}
//TC= O(log n * log n)
int main()
{
//	Node* root= new Node(10);
//	root->left=new Node(20);
//	root->right=new Node(30);
//	root->left->left=new Node(40);
//	root->left->right=new Node(50);
	
	Node* root= new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->left=new Node(60);
	root->right->right=new Node(70);
	root->left->left->left=new Node(80);
	root->left->left->right=new Node(90);
	root->left->right->left=new Node(50);
	int nodes=countNodes(root);
	cout<<nodes<<endl;
}
