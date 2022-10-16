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
//Method 1
//bool findPath(Node* root,vector<Node*> &path,int n)
//{
//	if(root==NULL)
//	return false;
//	path.push_back(root);
//	if(root->data==n)
//	return true;
//	if(findPath(root->left,path,n)||findPath(root->right,path,n))
//	return true;
//	path.pop_back();
//	return false;
//}
//Node* LCA(Node* root,int n1,int n2)
//{
//	
//	vector<Node*>path1,path2;
//	if(findPath(root,path1,n1)== false||findPath(root,path2,n2) == false)
//	return NULL;
//	for(int i=0;i<path1.size()-1&& i<path2.size()-1;i++)
//	{
//		if(path1[i+1]!=path2[i+1])
//		return path1[i];
//	}
//	return NULL;
//}

//Method 2 (efficient)
Node* LCA(Node* root,int n1,int n2)
{
	if(root==NULL)
	return NULL;
	if(root->data==n1 || root->data==n2)
	return root;
	Node* LCA1=LCA(root->left,n1,n2);
	Node* LCA2=LCA(root->right,n1,n2);
	
	if(LCA1!=NULL && LCA2!=NULL)
	return root;
	
	if(LCA1!=NULL)
	return LCA1;
	
	if(LCA2!=NULL)
	return LCA2;
	
}
int main()
{
	Node* root= new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	root->right->left->left=new Node(60);
	root->right->right->left=new Node(70);
	root->right->right->right=new Node(80);
	Node* ans=LCA(root,60,80);
	
}
