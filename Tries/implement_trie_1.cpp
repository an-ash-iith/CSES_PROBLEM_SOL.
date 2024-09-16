struct Node
{
    Node *links[26]; //it is similar to the array -- like there are 26 consecutive link pointing
    //to the node 
    bool flag= false;
    bool containsKey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }

    void put(char ch, Node* node)
{
       links[ch-'a']=node;  //node is the reference node for this character
}


Node* get(char ch)
{
    return links[ch-'a'];
}

void setEnd()
{
    flag=true;
    
}

bool isEnd()
{
    return flag;
}

};

class Trie {
private:
 Node *root; //every trie have root

public:
    Trie() {
        
        root = new Node(); //initnitally it does not have any thiong it will call default constructor
        
    }

    //complexity with 0(n)
    void insert(string word) {

                
        Node* node = root;

        for(int i =0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                //if this key is not contained then you are passing new node()  that will create new node --
              node->put(word[i],new Node());
            }
            //move to the reference trie ---

          node = node->get(word[i]);
        }
      node->setEnd();
        
    }

    //complexity will be 0(n)
    
    bool search(string word) {
        Node * node = root;

        for(int i =0;i<word.size();i++)
        {
             if(!node->containsKey(word[i]))
             {
                return false;
             }

             node = node->get(word[i]);
        }

        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        
        Node * node = root;

        for(int i =0;i<prefix.size();i++)
        {
             if(!node->containsKey(prefix[i]))
             {
                return false;
             }

             node = node->get(prefix[i]);
        }

        return true;
       
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */