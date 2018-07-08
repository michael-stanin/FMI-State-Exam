#include "BinaryTree.h"
#include <iostream>

BinaryTree::BinaryTree()
{
	root = nullptr;
}

BinaryTree::~BinaryTree()
{
	destroy_tree();
}

void BinaryTree::destroy_tree(Node *leaf)
{
	if (leaf != nullptr) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
		leaf = nullptr;
	}
}

void BinaryTree::insert(int key, Node *leaf)
{
	if (key < leaf->value) {
		if (leaf->left != nullptr) {
			insert(key, leaf->left);
		}
		else {
			leaf->left = new Node;
			leaf->left->value = key;
			leaf->left->left = nullptr; //Sets the left child of the child node to null
			leaf->left->right = nullptr; //Sets the right child of the child node to null
		}
	}
	else if (key >= leaf->value) {
		if (leaf->right != nullptr) {
			insert(key, leaf->right);
		}
		else {
			leaf->right = new Node;
			leaf->right->value = key;
			leaf->right->left = nullptr; //Sets the left child of the child node to null
			leaf->right->right = nullptr; //Sets the right child of the child node to null
		}
	}

}

void BinaryTree::insert(int key)
{
	if (root != nullptr) {
		insert(key, root);
	}
	else {
		root = new Node;
		root->value = key;
		root->left = nullptr;
		root->right = nullptr;
	}
}

BinaryTree::Node* BinaryTree::search(int key, Node *leaf)
{
	if (leaf != nullptr) {
		if (key == leaf->value) {
			return leaf;
		}
		if (key < leaf->value) {
			return search(key, leaf->left);
		}
		else {
			return search(key, leaf->right);
		}
	}
	return nullptr;
}

BinaryTree::Node* BinaryTree::search(int key)
{
	return search(key, root);
}

void BinaryTree::destroy_tree()
{
	destroy_tree(root);
}

void BinaryTree::inorder_print()
{
	inorder_print(root);
	std::cout << "\n";
}

void BinaryTree::inorder_print(Node *leaf)
{
	if (leaf != nullptr) {
		inorder_print(leaf->left);
		std::cout << leaf->value << ",";
		inorder_print(leaf->right);
	}
}

void BinaryTree::postorder_print()
{
	postorder_print(root);
	std::cout << "\n";
}

void BinaryTree::postorder_print(Node *leaf)
{
	if (leaf != nullptr) {
		inorder_print(leaf->left);
		inorder_print(leaf->right);
		std::cout << leaf->value << ",";
	}
}

void BinaryTree::preorder_print()
{
	preorder_print(root);
	std::cout << "\n";
}

void BinaryTree::preorder_print(Node *leaf)
{
	if (leaf != nullptr) {
		std::cout << leaf->value << ",";
		inorder_print(leaf->left);
		inorder_print(leaf->right);
	}
}