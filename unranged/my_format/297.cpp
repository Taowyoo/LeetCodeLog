/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

// my solution
// use level order (BFS) to serialize and decode tree
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return string("[]");
        queue<TreeNode*> todo;
        string res = "[";
        todo.push(root);
        while(!todo.empty()){
            int num = todo.size();
            for(int i = 0; i < num; ++i) {
                TreeNode* node = todo.front();
                if(node){
                    res += to_string(node->val);
                    todo.push(node->left);
                    todo.push(node->right);
                }
                else
                    res += "null";
                res += ',';
                todo.pop();
            }
        }
        int extra = 0, len = res.size();
        while(res[len - 2 - extra] == 'l') extra += 5;
        res.resize(len - extra);
        res.back() = ']';
        // printf("%s\n",res.c_str());
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]") return nullptr;
        std::vector<std::string> strs;
        data.pop_back();
        data = data.substr(1);
        SplitString(data, strs, ",");
        if(strs[0] == "null" || strs.size() == 0) return nullptr;
        TreeNode* root = new TreeNode(stoi(strs[0]));
        queue<TreeNode*> todo;
        todo.push(root);
        int i = 1;
        while(!todo.empty()){
            // fill left right node for all node in queue
            int num = todo.size();
            
            for(int j = 0; j < num; ++j) {
                
                TreeNode* node = todo.front();
                if(i >= strs.size()) return root;
                if(strs[i] != "null"){
                    node->left = new TreeNode(stoi(strs[i]));
                    todo.push(node->left);
                }
                ++i;
                if(i >= strs.size()) return root;
                if(strs[i] != "null"){
                    node->right = new TreeNode(stoi(strs[i]));
                    todo.push(node->right);
                }
                ++i;
                todo.pop();
            }
        }
        
        return root;
    }
private:
    void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
    {
        std::string::size_type pos1, pos2;
        pos2 = s.find(c);
        pos1 = 0;
        while(std::string::npos != pos2)
        {
            v.push_back(s.substr(pos1, pos2-pos1));
            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if(pos1 != s.length())
        v.push_back(s.substr(pos1));
    }
};
//====================================================================================================
// Recursion Solution using stringstream
// both use preorder
class Codec {
public:

    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

private:

    void serialize(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }

    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};
//====================================================================================================
