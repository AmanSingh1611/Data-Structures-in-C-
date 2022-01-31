/**********************************************************
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
#include <climits>
bool good(BinaryTreeNode<int> *root,int min,int max){
    if(root==NULL){
        return true;
    }if(root->data>max || root->data<min){
        return false;
    }
    bool leftAns=good(root->left,min,root->data-1);
    bool rightAns=good(root->right,root->data,max);
    return leftAns && rightAns;
}
bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
    return good(root,INT_MIN,INT_MAX);
}