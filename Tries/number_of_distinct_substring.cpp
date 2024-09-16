int total=0;

class Trie {
public:
    class Node {
    public:
        Node* links[26] = {nullptr};
        bool flag = false;
        int pre=0;
        int end=0;

        void put(Node* node, char ch) {
            links[ch - 'a'] = node;
        }

        Node* get(char ch) {
            return links[ch - 'a'];
        }

        bool containsKey(char ch) {
            return links[ch - 'a'] != nullptr;
        }

        void setEnd() {
            flag = true;
        }

        bool isEnd() {
            return flag;
        }
    };

    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string& word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(new Node(), word[i]);
                total++;
            }
            node = node->get(word[i]);
            node->pre++;
        }

        node->end++;
        node->setEnd();
    }

    int countWordsEqualTo(string& word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->isEnd() ? node->end : 0;
    }

    int countWordsStartingWith(string& word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->pre;
    }

    void erase(string& word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {

            if (!node->containsKey(word[i])) {
                return;
            }
            node = node->get(word[i]);
            node->pre--;
        }

        node->end--;
        node->flag = false;
    }

    bool checkpre(string &word)
    {
             Node* node = root;
        for (int i = 0; i < word.size(); i++) {
           
            node = node->get(word[i]);

            if(node->flag==false)
            return false;
            
        }

        return true;

    }

    

};

int countDistinctSubstrings(string &s)
{
    //    Write your code here.
      total=1;
        Trie trie;
       
            int n = s.size();
             
             string temp;
            for(int i =0;i<n;i++)
            {

                temp=s.substr(i,n-i);
                trie.insert(temp);
            }
    
    
    return total;
}