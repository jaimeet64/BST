#include <iostream>
#include <cstdlib>
#include "BST.h"

using namespace std; 

BST::BST()
{
	root = NULL;
}
BST::node* BST::CreateLeaf(int key)
{
	node* n = new node;
	n->key = key;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void BST::AddLeaf(int key)
{
	AddLeafPrivate(key, root);
}

void BST::AddLeafPrivate(int key, node* Ptr)
{
	if(root == NULL)
	{
		root = CreateLeaf(key);
	}

	else if(key < Ptr->key)
	{
		if(Ptr->left == NULL)
		{
			Ptr->left = CreateLeaf(key);
		}
		else
		{
			AddLeafPrivate(key, Ptr->left);
		}
	}

	else if(key > Ptr->key)
	{
		if(Ptr->right == NULL)
		{
			Ptr->right = CreateLeaf(key);
		}
		else
		{
			AddLeafPrivate(key, Ptr->right);
		}
	}
	else
	{
		cout << "The Key" << key << " has already been addedto the tree \n";
	}

}

