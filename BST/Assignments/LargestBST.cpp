/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
	Given a Binary tree, find the largest BST subtree. That is, 
	you need to find the BST with maximum height in the given binary tree. 
	You have to return the height of largest BST.
***********************************************************/
#include<climits>
#include<cmath>

int height(BinaryTreeNode<int> *root){
    if(root == NULL){
        return 0;
    }
    int ans1 = 0; int ans2 = 0;
    
    ans1 = height(root -> left);
    ans2 = height(root -> right);
    
    if(ans1 > ans2){
        return ans1 + 1;
    }
    else{
        return ans2 + 1;
    }
}
bool isBST(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX){
    if(root == NULL){
        return true;
    }
    if(root -> data < min || root -> data > max){
        return false;
    }
    
    bool isLeftOK = isBST(root -> left, min, root -> data -1);
    bool isRightOK = isBST(root -> right, root -> data + 1, max);
    
    return isLeftOK && isRightOK;
}
int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
    if(isBST(root)){
        return height(root);
    }
    else{
        int ans1 = largestBSTSubtree(root -> left);
        int ans2 = largestBSTSubtree(root -> right);
        
        return max(ans1, ans2);
    }
}