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
BinaryTreeNode<int>* good(int *input,int si,int ei,int n){
    if(si>ei){
        return NULL;
    }
    if(si==ei){
        BinaryTreeNode<int>* ans=new BinaryTreeNode<int>(input[si]);
        return ans;
    }else{
        BinaryTreeNode<int>* leftAns=good(input,si,(si+ei)/2-1,n);
        BinaryTreeNode<int>* rightAns=good(input,(si+ei)/2+1,ei,n);
        BinaryTreeNode<int>* root=new BinaryTreeNode<int>(input[(si+ei)/2]);
        root->left=leftAns;
        root->right=rightAns;
        return root;
    }
}
BinaryTreeNode<int>* constructTree(int *input, int n) {
	// Write your code here
    if(n==0){
        return NULL;
    }
    return good(input,0,n-1,n);
}