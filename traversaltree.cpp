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
void levelOrderTraversal(Node* root)
{
	if(root==NULL)
	return;
	cout<<root->data<<" ";
	levelOrderTraversal(root->left);
	levelOrderTraversal(root->right);
}
void inorderTraversal(Node* root)
{
	if(root==NULL)
	return;
	inorderTraversal(root->left);
	cout<<root->data<<" ";
	inorderTraversal(root->right);
}
void preorderTraversal(Node* root)
{
	if(root==NULL)
	return;
	cout<<root->data<<" ";
	levelOrderTraversal(root->left);
	levelOrderTraversal(root->right);
}
void postorderTraversal(Node* root)
{
	if(root==NULL)
	return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	cout<<root->data<<" ";
}

int main()
{
	Node* root=new Node(10);
	 root->left= new Node(20);
	 root->right=new Node(30);
     root->right->left=new Node(40);
     root->right->right=new Node(50);
     root->right->left->left=new Node(60);
      root->right->left->left->left=new Node(60);
    cout<<"level order traversal:"<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    cout<<"inorder traversal:"<<endl;
    inorderTraversal(root);
    cout<<endl;
    cout<<"preorder traversal:"<<endl;
    preorderTraversal(root);
    cout<<endl;
    cout<<"postorder traversal:"<<endl;
    postorderTraversal(root);
    
}
