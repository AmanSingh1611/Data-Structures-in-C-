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

/*
	The first value of the pair must be the minimum value in the tree and 
	the second value of the pair must be the maximum value in the tree
*/
#include <climits>
#include <queue>

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
    pair<int,int> p;
    
    p.second = INT_MIN;
    p.first = INT_MAX;
    
    if(root == NULL)
        return p;
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty()){
        
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        
        if(front -> data > p.second){
            p.second = front -> data;
        }
        
        if(front -> data < p.first){
            p.first = front -> data;
        }
        
        if(front -> right){
            q.push(front -> right);
        }
        
        if(front -> left){
            q.push(front -> left);
        }
    }
    
    return p;
    
}