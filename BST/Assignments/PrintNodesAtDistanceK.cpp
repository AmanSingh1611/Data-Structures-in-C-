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
	You are given a Binary Tree of type integer, a target node, and an integer value K.
	Print the data of all nodes that have a distance K from the target node. 
	The order in which they would be printed will not matter.
***********************************************************/
void depth(BinaryTreeNode<int> *root, int k) { 
    if(root == NULL) {
        return;
    }
    if(k == 0) { 
        cout << root -> data << endl; 
        return;
    }
    depth(root -> left, k - 1);
    depth(root -> right, k - 1);
}
int nodesAtDistanceKHelper(BinaryTreeNode<int> *root, int target, int k) {
    if (root == NULL) 
        return -1;
    
    if (root -> data == target) {
        depth(root, k);
        return 0;
    }
    
    int leftD = nodesAtDistanceKHelper(root -> left, target, k);
    
    if (leftD != -1) { 
        if (leftD + 1 == k) {
            cout << root -> data << endl;
        }
        else
            depth(root -> right, k - leftD - 2);
        return 1 + leftD;
    }
    int rightD = nodesAtDistanceKHelper(root -> right, target, k);
    if (rightD != -1) {
        if (rightD + 1 == k) {
            cout << root -> data << endl;
        } 
        else
            depth(root -> left, k - rightD - 2);
        return 1 + rightD;
    }
    return -1;
}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code here
    nodesAtDistanceKHelper(root, node, k);
}