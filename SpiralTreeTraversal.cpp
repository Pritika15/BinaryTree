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
void SpiralTraversal(Node* root)
{
	if(root==NULL)
	return;
	stack<Node*>s1;
	stack<Node*>s2;
	s1.push(root);
	while(s1.empty()==false || s2.empty() ==false )
	{
		while(s1.empty()==false)
		{
			Node* temp=s1.top();
			s1.pop();
			cout<<temp->data<<" ";
			if(temp->left!=NULL)
			s2.push(temp->left);
			if(temp->right!=NULL)
			s2.push(temp->right);
		}
		while(s2.empty()==false)
		{
			Node* temp=s2.top();
			s2.pop();
			cout<<temp->data<<" ";
			if(temp->right!=NULL)
			s1.push(temp->right);
			if(temp->left!=NULL)
			s1.push(temp->left);
			
		}
	}
}
int main()
{
	Node* root= new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->left->left=new Node(8);
	root->left->left->right=new Node(9);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	root->right->left->left=new Node(10);
	SpiralTraversal(root);
}
