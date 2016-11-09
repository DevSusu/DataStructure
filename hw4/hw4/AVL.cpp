#include "AVL.h"

template <class K, class D>
AVL<K, D>::AVL() {
    BST<K,D>();
}

template <class K, class D>
void AVL<K, D>::Insert(const K& key, const D& data) {
    BST<K, D>::size++;
    Insert(BST<K,D>::root, key, data);
}

template <class K, class D>
void AVL<K, D>::Remove(const K& key) {
    Remove(BST<K,D>::root, key);
}

template <class K, class D>
int AVL<K, D>::GetHeight(TreeNode<K, D>* curr_node) {
    if( curr_node ) {
        return curr_node->height;
    }
    else
        return -1;
}

template <class K, class D>
int AVL<K, D>::BF(TreeNode<K, D>* curr_node) {
    if( curr_node )
        return GetHeight(curr_node->left) - GetHeight(curr_node->right);
    else
        return 0;
}

template <class K, class D>
void AVL<K, D>::Insert(TreeNode<K, D>*& curr_node, const K& key, const D& data) {
	if (curr_node == NULL) {
        // Create a new node
        curr_node = new TreeNode<K,D>(key,data);
	}
	else if (key < curr_node->key) {
		// Insert the node in left sub-tree with rotation process
        Insert( curr_node->left, key, data);
	}
	else if (key > curr_node->key) {
		// Insert the node in left sub-tree with rotation process
        Insert( curr_node->right, key, data);
	}
	else if (key == curr_node->key) {
        curr_node->data.~D();
        curr_node->data = data;
	}
    
    Rotate(curr_node);
    
	// Update a height
    curr_node->height = max( GetHeight(curr_node->left) , GetHeight(curr_node->right) ) + 1;
}

template <class K, class D>
void AVL<K, D>::Rotate(TreeNode<K, D>*& curr_node) {
    int bf = BF(curr_node);
    if( abs(bf) <= 1 )
        return;
    
    // left > right
    if( bf >= 2 ) {
        if( BF(curr_node->left) > 0 )
            RotateSingle(curr_node);
        else
            RotateDouble(curr_node);
    }
    else {
        if( BF(curr_node->right) > 0 )
            RotateDouble(curr_node);
        else
            RotateSingle(curr_node);
    }
    
}

template <class K, class D>
void AVL<K, D>::RotateSingle(TreeNode<K, D>*& curr_node) {
	// Implement a RotateSingle Function
    
    TreeNode<K, D>* tmp;
    if( BF(curr_node) > 0 ) {
        tmp = curr_node->left;
        curr_node->left = tmp->right;
        tmp->right = curr_node;
        curr_node = tmp;
    }
    else {
        tmp = curr_node->right;
        curr_node->right = tmp->left;
        tmp->left = curr_node;
        curr_node = tmp;
    }
}

template <class K, class D>
void AVL<K, D>::RotateDouble(TreeNode<K, D>*& curr_node) {
	// Implement a RotateDouble Function
    
    if( BF(curr_node) > 0 ) {
        TreeNode<K, D>* tmp = curr_node->left;
        TreeNode<K, D>* new_root = tmp->right;
        
        curr_node->left = new_root->right;
        new_root->right = curr_node;
        tmp->right = new_root->left;
        new_root->left = tmp;
        curr_node = new_root;
    }
    else {
        TreeNode<K, D>* tmp = curr_node->right;
        TreeNode<K, D>* new_root = tmp->left;
        
        curr_node->right = new_root->left;
        new_root->left = curr_node;
        tmp->left = new_root->right;
        new_root->right = tmp;
        curr_node = new_root;
    }
}

template <class K, class D>
void AVL<K, D>::Remove(TreeNode<K, D>*& curr_node, const K& key) {
	// TODO : Implement a Remove Function with propagated rotation process
}
