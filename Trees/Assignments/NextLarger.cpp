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
#include <climits>
TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    if(root==NULL)
        return NULL;		///edge case
  
    TreeNode<int>*max =NULL;
    
    if(root->data > x)
        max=root;
    
    for(int i=0;i<root->children.size();i++)
    {
        TreeNode<int>*childmax= getNextLargerElement(root->children[i], x);
        
        if(childmax==NULL)
        {continue;}
        
        else
        {
            if(max==NULL)
                max=childmax;
            else if(childmax->data > x  && childmax->data < max->data)
                max= childmax;
        }
    }
    
    return max;
}