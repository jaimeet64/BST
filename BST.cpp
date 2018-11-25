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
		cout << "The Key" << key << " has already been added to the tree \n";
	}

}

void BST::PrintInOrder()
{
	PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(node* Ptr)
{
	if(root !=  NULL)
	{
		if(Ptr->left!= NULL)
		{
			PrintInOrderPrivate(Ptr->left);
			cout << "Going LEFT \n" << endl;
		}
		cout << Ptr->key << "  " << endl;;
		if(Ptr->right != NULL)
		{
			PrintInOrderPrivate(Ptr->right);
			cout << "Going RIGHT \n" << endl;
		}
	}
	else
	{
		cout << "The tree is empty \n" << endl;
	}
}

BST::node* BST::ReturnNode(int key)
{
	ReturnNodePrivate(key,root);
}

BST::node* BST::ReturnNodePrivate(int key, node* Ptr)
{
	if (Ptr != NULL)
	{
		if (Ptr-> key == key)
		{
			return Ptr;
		}

		else
			if (key < Ptr->key)
			{
				return ReturnNodePrivate(key,  Ptr->left);
			}
			else if(key > Ptr->key)
			{
				return ReturnNodePrivate(key,  Ptr->right);
			}
	}
	else
		return NULL;
}


int BST::ReturnRootKey()
{
	if(root!= NULL)
	{
		return root->key;
	}
	else
		return -1000;
}
