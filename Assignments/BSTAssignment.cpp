#include <iostream>
using namespace std;
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
//Creating Binary Search Tree Class
class BST {
    private:
    BinaryTreeNode<int>* root;
    private:
    BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int>* node) {
		if (node == NULL) {
			BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
			return newNode;
		}

		if (data <= node->data) {
			node->left = insert(data, node->left);
		} else {
			node->right = insert(data, node->right);
		}
		return node;
	}
    void print(BinaryTreeNode<int>* root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<":";
        if(root->left!=NULL){
            cout<<"L"<<":"<<root->left->data<<",";
        }if(root->right!=NULL){
            cout<<"R"<<":"<<root->right->data;
        }cout<<endl;
        print(root->left);
        print(root->right);
    }
    BinaryTreeNode<int>* deleteData(int data, BinaryTreeNode<int>* node) {
		if (node == NULL) {
			return NULL;
		}

		if (data > node->data) {
			node->right = deleteData(data, node->right);
			return node;
		} else if (data < node->data) {
			node->left = deleteData(data, node->left);
			return node;
		} else {
			if (node->left == NULL && node->right == NULL) {
				delete node;
				return NULL;
			} else if (node->left == NULL) {
				BinaryTreeNode<int>* temp = node->right;
				node->right = NULL;
				delete node;
				return temp;
			} else if (node->right == NULL) {
				BinaryTreeNode<int>* temp = node->left;
				node->left = NULL;
				delete node;
				return temp; 
			} else {
				BinaryTreeNode<int>* minNode = node->right;
				while (minNode->left != NULL) {
					minNode = minNode->left;
				}
				int rightMin = minNode->data;
				node->data = rightMin;
				node->right = deleteData(rightMin, node->right);
				return node;
			}
		}
	}
    public:
    BST() { 
        root=NULL;
    }
    /*----------------- Public Functions of BST -----------------*/

    void remove(int data) {
        cout<<"Deleted Data "<<data<<" from BST"<<endl;
        this->root=deleteData(data,this->root);
        return;
    }

    void print() { 
		return print(root);
    }

    void insert(int data) {  
        cout<<"Inserted Data "<<data<<" into BST"<<endl;
        this->root=insert(data,this->root);
        return;
    }
};
int main(){
    BST tree;
    //Inserting data in BST
    tree.insert(6);
    tree.insert(4);
    tree.insert(5);
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    tree.insert(8);
    tree.insert(10);
    tree.insert(7);
    /* ------FORMED TREE-------
                 6
                /\
               4  8
              /\  /\
             2  5 7 10
            /\
           1  3
    */
    tree.print();
    //Deleted Data 6 
    tree.remove(6);
    tree.print();

}