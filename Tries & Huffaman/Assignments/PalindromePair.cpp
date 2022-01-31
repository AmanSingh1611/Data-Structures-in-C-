class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
            this->count++;
        }
    }
    bool search(string word){
        return search(root,word);
    }
    bool search(TrieNode* root,string word){
       if(root==NULL)return false;
      	if(word.size()==1)return true;
      	
      	int index = word[0]-'a';
      	if(root->children[index]==NULL)return false;
      	else
        {
          return search(root->children[index],word.substr(1));
        }
    }

    /*..................... Palindrome Pair................... */

    bool isPalindromePair(vector<string> words) {
        // Write your code here
        for(int i=0;i<words.size();i++)
        {
          string temp = words[i];
          reverse(temp.begin(),temp.end());
          add(temp);
        }
      
      	bool ans = false;
      	for(int j=0;j<words.size();j++)
        {
          ans = search(root,words[j])||search(root,words[j].substr(1));
          if(ans)return ans;
        }
      	
      	return false;
	}
};