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
	Given a binary search tree, you have to replace each node's data with the sum, 
	of all nodes which are greater or equal than it. 
	You need to include the current node's data also.
	That is, if in given BST there is a node with data 5, 
	you need to replace it with sum of its data (i.e. 5) and all nodes whose data is greater than or equal to 5.

***********************************************************/
int replaceWithLargerNodesSum(BinaryTreeNode<int> *root, int sum){
    
    if(root == NULL){
        return sum;
    }
    
    sum = replaceWithLargerNodesSum(root -> right, sum);
    
    sum += root -> data;
    root -> data = sum;
    
    sum = replaceWithLargerNodesSum(root -> left, sum);
    
    return sum;
}
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    // Write your code here
    int sum = 0;
    replaceWithLargerNodesSum(root, sum);
}