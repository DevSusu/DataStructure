#ifndef BST_H
#define BST_H
#include<iostream>

template <typename K, typename D>
class TreeNode {
public:
    
    TreeNode(K k, D d);
    ~TreeNode();
    void Print();
    
    K key; D data;
    TreeNode<K,D>* left;
    TreeNode<K,D>* right;
};


template <typename K, typename D>
class BST {
public:
    BST();
    ~BST();
    bool IsEmpty();
    int GetHeight();
    void Inorder();
    void Preorder();
    void Postorder();
    void Levelorder();
    void Insert(const K& key, const D& data);
    void Remove(const K& key);
    D Find(const K& key);
    
private:
    void Inorder(TreeNode<K,D>* curr_node);
    
    void Preorder(TreeNode<K,D>* curr_node);
    
    void Postorder(TreeNode<K,D>* curr_node);
    
    void Levelorder(TreeNode<K,D>* curr_node);
    
    TreeNode<K,D>* Find(TreeNode<K,D>* &curr_node, const K& key);
    
    void Insert(TreeNode<K,D>* &curr_node, const K& key, const D& data);
    
    TreeNode<K, D>*& RightMostChild(TreeNode<K, D> *&curr_node);

    void Remove(TreeNode<K, D> *&curr_node, const K& key);
    
    void DoRemoval(TreeNode<K, D> *&curr_node);
    
    void NoChildRemove(TreeNode<K, D> *&curr_node);
    
    void OneChildRemove(TreeNode<K, D> *&curr_node);
    
    void TwoChildRemove(TreeNode<K, D> *&curr_node);
    
    TreeNode<K,D>* root;
    int size;
};

#endif
