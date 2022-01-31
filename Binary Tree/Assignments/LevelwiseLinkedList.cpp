/**********************************************************

	Following are the Binary Tree Node class structure and
	the Node class structure

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

	template <typename T>
	class Node {
		public:
    	T data;
    	Node<T> *next;
    	Node(T data) {
        	this->data=data;
        	this->next=NULL;
    	}
	};

***********************************************************/
#include <queue>
#include <vector>
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
    vector<Node<int>*> ans;
    queue<BinaryTreeNode<int>*> list;
    list.push(root);
    list.push(NULL);
    Node<int>* head=NULL;
    Node<int>* tail=NULL;
    if(root==NULL){
        ans.push_back(NULL);
        return ans;
    }
    while(!list.empty()){
        BinaryTreeNode<int> *front = list.front();
        list.pop();
        if(front==NULL){
            tail->next=NULL;
            if(list.empty()){
                break;
            }else{
                list.push(NULL);
            }
            head=NULL;
            tail=NULL;
        }else{
            Node<int>* n=new Node<int>(front->data);
            if(head==NULL){
                head=n;
                tail=n;
                ans.push_back(head);
            }else{
                tail->next=n;
                tail=tail->next;
            }if(front->left!=NULL){
                list.push(front->left);
            }if(front->right!=NULL){
                list.push(front->right);
            }
        }
        
    }return ans;
}