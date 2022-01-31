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
#include <stack>
#include <queue>
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    queue<TreeNode<int>*> q;
    
    TreeNode<int>* large = new TreeNode<int>(0);
    TreeNode<int>* secondLarge;
    
    if(root->children.size() < 1)
        return 0;
    
    q.push(root);
    
    while(!q.empty()){
        if(q.front() -> data > large->data){
            secondLarge = large;
            large = q.front();
        }
        else if(q.front()->data > secondLarge -> data){
            if(q.front() -> data != large->data)
                secondLarge = q.front();
            else
                return NULL;
        }
        
        for(int i=0;i<root->children.size();i++)
            q.push(root->children[i]);
        
        q.pop();
        root=q.front();
    }
    return secondLarge;
}