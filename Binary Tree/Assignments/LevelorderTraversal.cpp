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

void printLevelWise(BinaryTreeNode<int> *root) {
    // Write your code here
    queue<BinaryTreeNode<int>*> pending;
    pending.push(root);
    pending.push(NULL);
    while(!pending.empty()){
        BinaryTreeNode<int> *front=pending.front();
        if(front==NULL){
            pending.pop();
            if(pending.empty()){
                break;
            }
            pending.push(NULL);
            cout<<endl;
            continue;
        }
        cout<<front->data<<" ";
        if(front->left!=NULL){
            pending.push(front->left);
        }if(front->right!=NULL){
            pending.push(front->right);
        }pending.pop();
    }
}