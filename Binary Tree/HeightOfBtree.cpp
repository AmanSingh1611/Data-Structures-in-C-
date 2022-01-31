/***********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/
#include <cmath>
int height(BinaryTreeNode<int>* root) {
    // Write our code here
    if(root==NULL){
        return 0;
    }
    int lans=1+height(root->left);
    int rans=1+height(root->right);
    return max(lans,rans);
}