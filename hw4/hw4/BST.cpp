#include "BST.h"
#include "Queue.h"
#include "Queue.cpp"

template <typename K, typename D>
TreeNode<K,D>::~TreeNode() {
    key.~K();
    data.~D();
    delete left;
    delete right;
}

template <typename K, typename D>
TreeNode<K,D>::TreeNode(K k, D d) : key(k), data(d) {
    left = right = NULL;
    height = 0;
}

template <typename K, typename D>
void TreeNode<K,D>::Print() {
    std::cout << "<" << key << " - " << data << "> ";
}

template <typename K, typename D>
BST<K,D>::~BST() {
    delete root;
}

template <typename K, typename D>
BST<K, D>::BST() {
    size = 0;
    root = NULL;
}

template <typename K, typename D>
void BST<K, D>::Inorder() {
    Inorder(root);
}

template <typename K, typename D>
void BST<K, D>::Preorder() {
    Preorder(root);
}

template <typename K, typename D>
void BST<K, D>::Postorder() {
    Postorder(root);
}

template <typename K, typename D>
void BST<K, D>::Levelorder() {
    Levelorder(root);
}

template <typename K, typename D>
void BST<K, D>::Remove(const K& key) {
    Remove(root, key);
}

template <typename K, typename D>
void BST<K, D>::Insert(const K& k, const D& d) {
    Insert(root, k, d);
}

template <typename K, typename D>
void BST<K,D>::Inorder(TreeNode<K, D> *curr_node) {
    
    if( !curr_node ) return;
    
    Inorder(curr_node->left);
    curr_node->Print();
    Inorder(curr_node->right);
    
}

template <typename K, typename D>
void BST<K,D>::Preorder(TreeNode<K, D> *curr_node) {
    
    if( !curr_node ) return;
    
    curr_node->Print();
    Preorder(curr_node->left);
    Preorder(curr_node->right);
    
}

template <typename K, typename D>
void BST<K,D>::Postorder(TreeNode<K, D> *curr_node) {
    
    if( !curr_node ) return;
    
    Postorder(curr_node->left);
    Postorder(curr_node->right);
    curr_node->Print();
    
}

template <typename K, typename D>
void BST<K,D>::Levelorder(TreeNode<K, D> *curr_node) {
    
    if( !curr_node ) return;
    
    Queue< TreeNode<K,D>* > queue( size*2 );
    
    queue.Push( curr_node );
    while( !queue.IsEmpty() ) {
        TreeNode<K,D>* curr = queue.Front();
        queue.Pop();
        
        curr->Print();
        
        if( curr->left ) {
            queue.Push(curr->left);
        }
        if( curr->right ) {
            queue.Push(curr->right);
        }
    }
    
}

template <typename K, typename D>
int BST<K,D>::GetHeight() {
    
    Queue< pair<TreeNode<K,D>*,int> > queue( size*2 );
    pair<TreeNode<K,D>*,int> curr;
    
    int height = -1;
    
    queue.Push( make_pair(root,0) );
    
    while( !queue.IsEmpty() ) {
        curr = queue.Front();
        queue.Pop();
        
        if( height < curr.second ) {
            height = curr.second;
        }
        
        curr.first->Print();
        
        if( curr.first->left ) {
            queue.Push( make_pair(curr.first->left,curr.second+1) );
        }
        if( curr.first->right ) {
            queue.Push( make_pair(curr.first->right,curr.second+1) );
        }
    }
    return height;

}

template <typename K, typename D>
TreeNode<K,D>* BST<K,D>::Find(TreeNode<K,D>* &curr_node, const K& key) {
    
    if( !curr_node ) return NULL;
    
    if( key == curr_node->key ) {
        return curr_node;
    }
    else if( key > curr_node->key ) {
        return Find(curr_node->right, key);
    }
    else {
        return Find(curr_node->right, key);
    }
}

template <typename K, typename D>
void BST<K,D>::Insert(TreeNode<K,D>* &curr_node, const K& key, const D& data) {
    
    if( !curr_node ) {
        size++;
        curr_node = new TreeNode<K,D>(key,data);
        return;
    }
    
    if( curr_node->key == key ) {
        curr_node->data.~D();
        curr_node->data = data;
    }
    else if( curr_node->key > key ) {
        return Insert(curr_node->left, key, data);
    }
    else if( curr_node->key < key ) {
        return Insert(curr_node->right, key, data);
    }
    
}

template <typename K, typename D>
TreeNode<K, D>*& BST<K,D>::RightMostChild(TreeNode<K, D> *&curr_node) {
    
    if( !curr_node->right ) {
        return curr_node;
    }
    
    return RightMostChild(curr_node->right);
}


template <typename K, typename D>
void BST<K,D>::Remove(TreeNode<K, D> *&curr_node, const K& key) {
    
    if( !curr_node ) {
        return;
    }
    
    if( curr_node->key == key ) {
        DoRemoval(curr_node);
    }
    else if( curr_node->key > key ) {
        return Remove(curr_node->left, key);
    }
    else if( curr_node->key < key ) {
        return Remove(curr_node->right, key);
    }
    
}

template <typename K, typename D>
void BST<K,D>::DoRemoval(TreeNode<K,D> *&curr_node) {
    
    if( !curr_node ) {
        return ;
    }
    
    size--;
    
    if( !curr_node->left ) {
        if( !curr_node->right ) {
            return NoChildRemove(curr_node);
        }
        OneChildRemove(curr_node);
    }
    else {
        if( !curr_node->right ) {
            return OneChildRemove(curr_node);
        }
        TwoChildRemove(curr_node);
    }
    
}

template <typename K, typename D>
void BST<K,D>::NoChildRemove(TreeNode<K, D> *&curr_node) {
    delete curr_node;
    curr_node = NULL;
}

template <typename K, typename D>
void BST<K,D>::OneChildRemove(TreeNode<K, D> *&curr_node) {
    
    TreeNode<K,D>* tmp;
    
    if( curr_node->left ) {
        tmp = curr_node->left;
    }
    else {
        tmp = curr_node->right;
    }
    
    curr_node->left = NULL;
    curr_node->right = NULL;
    delete curr_node;
    
    curr_node = tmp;
}

template <typename K, typename D>
void BST<K,D>::TwoChildRemove(TreeNode<K, D> *&curr_node) {

    TreeNode<K,D>*& tmp = RightMostChild(curr_node->left);
    curr_node->key = tmp->key;
    curr_node->data = tmp->data;

    DoRemoval(tmp);
}

template <typename K, typename D>
bool BST<K,D>::IsEmpty() {
    if( root ) return false;
    return true;
}
