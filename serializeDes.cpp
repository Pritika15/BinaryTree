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
void Serialize(Node* root, vector<int>&v)
{
	if(root==NULL)
	{
			v.push_back(-1);
			return;
	}

	v.push_back(root->data);
	Serialize(root->left,v);
	Serialize(root->right,v);
	
}
int index=0;
Node* Deserialize(vector<int>&v)
{
	if(v.size()==0)
	return NULL;
	
	int val=v[i];
	i++;
	if(val== -1)
	return NULL;
	
	Node* root=new Node(v[0]);
	root->left=Deserialize(v);
	root->right=Deserialize(v);
//	for(int i=1;i<v.size();i++)
//	{
//		if(i== -1)
//		continue;
//		else if(i%2!=0)
//		{
//			root->left=new Node(v[i]);
//			root=root->left;
//		}
//		else
//		{
//			root->right=new Node(v[i]);
//			root=root->right;
//		}
//	}
	return root;
}
int main()
{
	Node* root= new Node(10);
	root->left=new Node(20);
	root->left->left=new Node(30);
	root->left->left->right=new Node(40);
	vector<int>v;
	Serialize(root,v);
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	Node* deserialized=Deserialize(v);
	
}

