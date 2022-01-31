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
    };

************************************************************/

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here
    TreeNode<int>* ans=root;
    int child=root->data;
    for(int i=0;i<root->children.size();i++){
        child+=root->children[i]->data;
    }for(int i=0;i<root->children.size();i++){
        TreeNode<int>* temp=maxSumNode(root->children[i]);
        int sum=temp->data;
        for(int i=0;i<temp->children.size();i++){
        	sum+=temp->children[i]->data;
        }if(sum>child){
            ans=temp;
            child=sum;
        }
    }return ans;
}