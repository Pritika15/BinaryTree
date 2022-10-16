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
int maxWidth(Node* root)
{
	if(root==NULL)
	return 0;
//	if(root->left==NULL && root->right==NULL)
//	return 1;
//	int maxi=(maxWidth(root->left)+maxWidth(root->right));
//	return maxi;
queue<Node*>q;
q.push(root);
int result=0;
while(q.empty()==false)
{
	int count=q.size();
	result=max(result,count);
	for(int i=0;i<count;i++)
	{
		Node* temp=q.front();
	    q.pop();
	    if(temp->left!=NULL)
	    q.push(temp->left);
	    if(temp->right!=NULL)
	    q.push(temp->right);
	}
	
}
return result;
}
int main()
{
//	Node* root=new Node(10);
//	 root->left= new Node(20);
//	 root->right=new Node(30);
//	 root->left->left= new Node(40);
//	 root->left->left->left= new Node(80);
//	 root->right->left=new Node(50);
//	 root->right->right=new Node(60);
	 
//	 Node* root=new Node(10);
//	 root->left= new Node(80);
//	 root->left->right= new Node(70);

	Node* root=new Node(8);
	 root->left= new Node(30);
	 root->right=new Node(20);
	 root->left->left= new Node(90);
	 root->left->right= new Node(100);
	 
	 root->right->left=new Node(70);
	 root->right->right=new Node(300);
	 preOrderTraversal(root);
	 int MaxWidthBinary=maxWidth(root);
	 cout<<endl;
	 cout<<"maxWidth "<<MaxWidthBinary;
}
