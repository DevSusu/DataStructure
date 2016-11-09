#include "AVL.h"

template <class K, class D>
AVL<K, D>::AVL() {
	// TODO : Implement a constructor of AVL
}

template <class K, class D>
void AVL<K, D>::Insert(const K& key, const D& data) {
	// TODO : Implement an Insert Function of AVL Tree using private Insert Function
}

template <class K, class D>
void AVL<K, D>::Remove(const K& key) {
	// TODO : Implement a Remove Function of AVL Tree using private Remove Function
}

template <class K, class D>
int AVL<K, D>::GetHeight(TreeNode<K, D>* curr_node) {
	// TODO : Return the height of curr_node 
	// 	 Return -1 when curr_node is NULL
	//	 ¡Ø height : The height of AVL Tree - the level of curr_node
	//		   0 when curr_node is leaf node
}

template <class K, class D>
int AVL<K, D>::BF(TreeNode<K, D>* curr_node) {
	// TODO : Return the result of the equation below
	//	 The height of left child node of curr_node - The height of right child node of curr_node
}

template <class K, class D>
void AVL<K, D>::Insert(TreeNode<K, D>*& curr_node, const K& key, const D& data) {
	// TODO : Insert new node in AVL tree
	if (curr_node == NULL) {
		// TODO : Create a new node
	}
	else if (key < curr_node->key) {
		// TODO : Insert the node in left sub-tree with rotation process
	}
	else if (key > curr_node->key) {
		// TODO : Insert the node in left sub-tree with rotation process
	}
	else if (key == curr_node->key) {
		// TODO : Update when a node which has same key exists
	}
	// TODO : Update a height
}

template <class K, class D>
void AVL<K, D>::RotateSingle(TreeNode<K, D>*& curr_node) {
	// TODO : Implement a RotateSingle Function
}

template <class K, class D>
void AVL<K, D>::RotateDouble(TreeNode<K, D>*& curr_node) {
	// TODO : Implement a RotateDouble Function
}

template <class K, class D>
void AVL<K, D>::Remove(TreeNode<K, D>*& curr_node, const K& key) {
	// TODO : Implement a Remove Function with propagated rotation process
}