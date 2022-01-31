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
	Given a binary search tree and an integer S, 
	find pair of nodes in the BST which sum to S. 
	You can use extra space of the order of O(log n).
	
***********************************************************/
#include <stack>
void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    // Write your code here
    if(root==NULL)
        return;
    
    stack<BinaryTreeNode<int>*> s1, s2;
    BinaryTreeNode<int>* p = root;
    BinaryTreeNode<int>* q = root;
    
    while(!s1.empty() || !s2.empty() || p || q){
        if(p || q){
            if(p){
                s1.push(p);
                p = p->left;
            }
            if(q){
                s2.push(q);
                q = q->right;
            }
        }
        else{
            int a = s1.top()->data;
            int b = s2.top()->data;
            
            if(s1.top() == s2.top()) break;
            
            if(a + b == s){
                cout<<min(a, b)<<' '<<max(a, b)<<endl;
            }
            
            if(a + b > s){
                q = s2.top();
                s2.pop();
                q = q->left;
            }
            else{
                p = s1.top();
                s1.pop();
                p = p->right;
            }
        }
    }
}