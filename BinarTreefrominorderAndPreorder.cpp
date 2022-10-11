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
int preIndex=0;
Node* TreeConstruction(int in[],int pre[],int inS,int inE)
{
	if(inS>inE)
	return NULL;
	
	Node* root= new Node(pre[preIndex++]);
	
	int inIndex;
	for(int i=inS;i<=inE;i++)
	{
		if(in[i]==root->data)
		{
			inIndex=i;
			break;
		}
	}
	 root->left=TreeConstruction(in,pre,inS,inIndex-1);
	root->right=TreeConstruction(in,pre,inIndex+1,inE);
	return root;
}
void preOrderTraversal(Node* root)
{
	if(root==NULL)
	return;
	cout<<root->data<<" ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}
int main()
{
	int in[]={20,10,40,30,50};
	int pre[]={10,20,30,40,50};
	Node* Root=TreeConstruction(in,pre,0,4);
	cout<<"Preorder of the constructed tree is"<<endl;
	preOrderTraversal(Root);
}
