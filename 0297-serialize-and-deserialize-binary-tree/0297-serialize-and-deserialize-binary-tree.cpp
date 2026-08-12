class Codec {
public:

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if(root==nullptr) return "";

    queue<TreeNode*> q;
    q.push(root);

    string ans = "";

    while(!q.empty()){
        TreeNode* node =q.front();
        q.pop();

        if(node == nullptr){
            ans+="#,";
        }
        else{
            ans+=to_string(node->val) + ","; //cuz ans is string and node val is int , so we convert int to stirng 
            q.push(node->left);
            q.push(node->right);
        }
    }
    return ans;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if(data == "" ) return nullptr;

    stringstream ss(data);
    string val;

    getline(ss,val,',');

    TreeNode* root = new TreeNode(stoi(val));

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        //left child
        getline(ss, val, ',');

        if (val != "#") {
            node->left = new TreeNode(stoi(val));
            q.push(node->left);
        }

        //right child 

        getline(ss, val, ',');

        if (val != "#") {
            node->right = new TreeNode(stoi(val));
            q.push(node->right);
        }
    }
    return root;
}

};