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

int getHeight(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL){
        return 0;
    }
    int Max=1;
    for(int i=0;i<root->children.size();i++){
        int ans=getHeight(root->children[i])+1;
        if(ans>Max){
            Max=ans;
        }
    }return Max;
}