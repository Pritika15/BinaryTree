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
bool ChildrenSumProp(Node* root)
{
	if(root==NULL)
	return true;
	if(root->left==NULL && root->right==NULL)
	return true;
	
	int sum=0;
	if(root->left!=NULL)
	sum+=root->left->data;
	if(root->right!=NULL)
	sum+=root->right->data;
	
	return(root->data==sum && ChildrenSumProp(root->left) && ChildrenSumProp(root->right));
    
    
	
}
int main()
{
	Node* root=new Node(20);
	 root->left= new Node(8);
	 root->right=new Node(12);
	 root->left->left= new Node(3);
	 root->left->right= new Node(5);
	 
	 //test case:2
//	 Node* root=new Node(3);
//	 root->left= new Node(1);
//	 root->right=new Node(2);
//	 root->right->left= new Node(1);
//	 root->right->right= new Node(2);

	 cout<<"Preorder Traversal"<<endl;
	 preOrderTraversal(root);
	 cout<<endl;
	 bool DoesFollow=ChildrenSumProp(root);
	 cout<<DoesFollow<<endl;
}
