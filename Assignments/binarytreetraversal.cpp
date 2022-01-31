#include <queue>
#include <iostream>
using namespace std;
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
BinaryTreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter left child of " << front->data << endl;
		int leftChildData;
		cin >> leftChildData;
		if (leftChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
			front->left = child;
			pendingNodes.push(child);
		}
		cout << "Enter right child of " << front->data << endl;
		int rightChildData;
		cin >> rightChildData;
		if (rightChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
			front->right = child;
			pendingNodes.push(child);
		}
	}
	return root;
}
void printLevelWise(BinaryTreeNode<int> *root) {
    if(root == NULL)
         return;
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    
    while(q.size()!=0){
    
        BinaryTreeNode<int>*p=q.front();
        cout<<p->data<<":";
        q.pop();
        
        if(root->left!=NULL){
            cout<<"L:"<<root->left->data<<",";
            q.push(root->left);
        }
        
        else{
             cout<<"L:"<<"-1"<<",";
        }
        if(root->right!=NULL){
            cout<<"R:"<<root->right->data;
            q.push(root->right);
        }
        
        else{
            cout<<"R:"<<"-1";
        }
        
        cout<<endl;
        root=q.front();
    }
}
int main(){
    BinaryTreeNode<int> *head=takeInputLevelWise();
    cout<<"The Breadth For Search Traversal Of Tree Is:"<<endl;
    printLevelWise(head);
    
    //Tree
    /*    1
         / \
        2   3
       / \  / \
      4  5  6  7
      */

}