#include <iostream>
#include "treenode.h"
using namespace std;

int main()
{
    // TreeNode<int> *root = new TreeNode<int>(10);
    // TreeNode<int> *c1 = new TreeNode<int>(20);
    // TreeNode<int> *c2 = new TreeNode<int>(30);
    // TreeNode<int> *c3 = new TreeNode<int>(40);
    // TreeNode<int> *c4 = new TreeNode<int>(50);
    // root->child.push_back(c1);
    // root->child.push_back(c2);
    // c2->child.push_back(c3);
    // c2->child.push_back(c4);
    // printTree(root);

    // TreeNode<int>*root=takeInput();
    // printTree(root);

    TreeNode<int>*root=takeInputLevelWise() ;
    printTree(root);
    cout<<"total nodes: "<<totalNodes(root)<<endl;
    cout<<"total height:"<<height(root)<<endl;
    printNodesAtDepth(root,1);cout<<endl;
    cout<<"total leaf nodes:"<<totalLeafNodes(root)<<endl;
    preorder(root);
    //to delete tree:
    //method 1:
    //delete root;
    // method 2:
    // deleteTree(root);
}
