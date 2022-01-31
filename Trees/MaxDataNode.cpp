/************************************************************
 
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/
#include <queue>
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
    queue<TreeNode<int>*> nodes;
    nodes.push(root);
    int temp=root->data;
    TreeNode<int> *maxNode=root;
    while(!nodes.empty()){
        TreeNode<int> *x=nodes.front();
        nodes.pop();
        for(int i=0;i<x->children.size();i++){
            if(x->children[i]->data>temp){
                temp=x->children[i]->data;
                maxNode=x->children[i];    
            }nodes.push(x->children[i]);
        }
    }return maxNode;
}