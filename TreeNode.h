#ifndef TREENODE_H
#define TREENODE_H

template <claee T>
struct TreeNode{
    TreeNode<T>* l;
    TreeNode<T>* r;
    T data;
};

#endif