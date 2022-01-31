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
	
***********************************************************/
BinaryTreeNode<int>* minimum(BinaryTreeNode<int>* root){
    if(root->left==NULL){
        return root;
    }else{
        return minimum(root->left);
    }
}

class BST {
    // Define the data members
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
    bool search(BinaryTreeNode<int>* root,int data){
        if(root==NULL){
            return false;
        }if(root->data==data){
            return true;
        }else if(root->data>data){
            search(root->left,data);
        }else{
            search(root->right,data);
        }
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
        // Implement the Constructor
        root=NULL;
    }

	/*----------------- Public Functions of BST -----------------*/

    void remove(int data) { 
        // Implement the remove() function
        this->root=deleteData(data,this->root);
        return;
    }

    void print() { 
        // Implement the print() function
		return print(root);
    }

    void insert(int data) { 
        // Implement the insert() function 
        this->root=insert(data,this->root);
        return;
    }

    bool search(int data) {
		// Implement the search() function 
        return search(this->root,data); 
    }
};