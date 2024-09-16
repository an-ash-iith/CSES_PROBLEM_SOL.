class Trie {
public:
    class Node {
    public:
        Node* links[2] = {nullptr};
        bool flag = false;
        int pre = 0;
        int end = 0;

        void put(Node* node, int index) {
            links[index] = node;
        }

        Node* get(int index) {
            return links[index];
        }

        bool containsKey(int index) {
            return links[index] != nullptr;
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

    void insert(const string &word) {
        Node* node = root;
        for (char ch : word) {
            int index = ch - '0';
            if (!node->containsKey(index)) {
                node->put(new Node(), index);
            }
            node = node->get(index);
            node->pre++;
        }

        node->end++;
        node->setEnd();
    }

//    void findans(string &ans1, string &ans2) {
//         Node* node1 = root;
//         Node* node2 = root;

//         for (int i = 0; i < 32; i++) {
//             if (node1->get(1) != nullptr && node2->get(0) != nullptr) {
//                 ans1 += '1';
//                 ans2 += '0';
//                 node1 = node1->get(1);
//                 node2 = node2->get(0);
//             } else if (node1->get(0) != nullptr && node2->get(1) != nullptr) {
//                 ans1 += '0';
//                 ans2 += '1';
//                 node1 = node1->get(0);
//                 node2 = node2->get(1);
//             } else if (node1->get(0) != nullptr) {
//                 ans1 += '0';
//                 ans2 += '0';
//                 node1 = node1->get(0);
//                 node2 = node2->get(0);
//             } else if (node1->get(1) != nullptr) {
//                 ans1 += '1';
//                 ans2 += '1';
//                 node1 = node1->get(1);
//                 node2 = node2->get(1);
//             } else {
//                 return;
//             }
//         }
//    }

    int findMaximumXORWith(const string &word) {
        Node* node = root;
        string maxXor;
        for (char ch : word) {
            int index = ch - '0';
            int opposite = 1 - index;
            if (node->containsKey(opposite)) {
                maxXor += '1';
                node = node->get(opposite);
            } else {
                maxXor += '0';
                node = node->get(index);
            }
        }
        return stoi(maxXor, nullptr, 2);
    }
    

};

class Solution {
public:

    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for (int val : nums) {
            bitset<32> temp(val);
            string binary = temp.to_string(); // Convert bitset to binary string
            trie.insert(binary);
        }

        int maxXOR = 0;
        for (int val : nums) {
            bitset<32> temp(val);
            string binary = temp.to_string();
            int currentXOR = trie.findMaximumXORWith(binary);
            maxXOR = max(maxXOR, currentXOR);
        }

        return maxXOR;
    }

    // int findMaximumXOR(vector<int>& nums) {
    //     Trie trie;

    //     return solution.findMaximumXOR(nums);
    //     // for (int val : nums) {
        //     bitset<32> temp(val);
        //     string binary = temp.to_string(); // Convert bitset to binary string
        //     trie.insert(binary);
        // }

        // string ans1, ans2; // Initialize ans1 and ans2
        // trie.findans(ans1, ans2); // Call findans on trie object

        // cout << ans1 << endl;
        // cout << ans2 << endl;

        // return (stoi(ans1, nullptr, 2) ^ stoi(ans2, nullptr, 2)); // Convert binary string to integer using stoi
    // }
};