class Codec {
public:

    string serialize(TreeNode* root) {
        if (root == NULL)
            return "#";

        return to_string(root->val) + " " +
               serialize(root->left) + " " +
               serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return build(ss);
    }

    TreeNode* build(stringstream &ss) {
        string x;
        ss >> x;

        if (x == "#")
            return NULL;

        TreeNode* root = new TreeNode(stoi(x));

        root->left = build(ss);
        root->right = build(ss);

        return root;
    }
};