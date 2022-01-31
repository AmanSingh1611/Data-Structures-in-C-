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
void printLevelWise(TreeNode<int>* root) {
    // Write your code here
    queue<TreeNode<int>*> nodes;
    nodes.push(root);
    while(!nodes.empty()){
        TreeNode<int>* x=nodes.front();
        nodes.pop();
        cout<<x->data<<":";
        for(int i=0;i<x->children.size();i++){
            if(i==x->children.size()-1){
                cout<<x->children[i]->data;
            }else{
                cout<<x->children[i]->data<<",";
            }nodes.push(x->children[i]);
        }cout<<endl;
    }
}