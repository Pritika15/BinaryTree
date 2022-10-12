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
int height(Node* root)
{
	if(root==NULL)
	return 0;
	if(root->left==NULL && root->right==NULL)
	return 1;
	 
	 return 1+max(height(root->left),height(root->right));
}
int diamtere(Node* root)
{
	if(root==NULL)
	return 0;
	if(root->left==NULL && root->right==NULL)
	return 1;
	int D1=height(root->left)+height(root->right)+1;
	int D2=diamtere(root->left);
	int D3=diamtere(root->right);
	int ans=max(D1,max(D2,D3));
	return ans;
	
}
int main()
{
	Node* root= new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	root->right->left->left=new Node(60);
	int DiameterofTree=diamtere(root);
	cout<<DiameterofTree;
}
