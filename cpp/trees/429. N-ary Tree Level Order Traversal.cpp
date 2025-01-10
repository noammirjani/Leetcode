   
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
   
   
   
   void insertChildren(Node*root, int level, vector<vector<int>>& data){
        if (!root) return; 
        if (data.size() < level+1) data.push_back({});
        data[level].push_back(root->val);
        for (auto& child : root->children){
            insertChildren(child, level+1, data); 
        } 
    }
    vector<vector<int>> levelOrder2(Node* root) {
        if (!root) return {}; 
        vector<vector<int>> data; 
        int level = 0; 
        insertChildren(root, level, data);
        return data;
    }