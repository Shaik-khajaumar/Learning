#include <iostream>
class TreeNode {
    public:
    int data;
    TreeNode * left;
    TreeNode * right;

    TreeNode (int d) : data(d), left(nullptr), right (nullptr) {}

    int getData() const { return data; }
};

class BinarySearchTree{

    TreeNode* root;
    int size;

    public:
    BinarySearchTree() : root (nullptr), size(0) {}
    void deleteNode (TreeNode* node) {
        if (node) {
            deleteNode (node->left);
            deleteNode (node->right);
            delete node;
        }
    }
    ~BinarySearchTree () {
        deleteNode(root);
    }

    void insert (int data) {
        if (root == nullptr) {
            root = new TreeNode(data);
            return;
        }

        TreeNode* cur = root;
        TreeNode* temp = cur;
        while (cur != nullptr) {
            temp = cur;

            if (cur->data == data) {
                return;
            }
            else if (cur->data < data) {
                cur = cur->right;
            }
            else {
                cur = cur->left;
            }
        }
        if (data < temp->data) {
            temp->left = new TreeNode (data);
        }
        else {
            temp->right = new TreeNode(data);
        }
    }

    TreeNode* insertRecursive (TreeNode* node, int data) {

        if (node == nullptr) {
            node = new TreeNode(data);
            return node;
        }
        
        if (data < node->data) {
            node->left =  insertRecursive(node->left, data);
        }
        else {
            node->right = insertRecursive(node->right, data);
        }
        return node;
    }

    void Inorder (TreeNode* p) {
    if (p){
        Inorder(p->left);
        std::cout << p->data << " ";
        Inorder(p->right);
    }
    }

TreeNode* Search(int key) {
    TreeNode* t = root;
    while (t != nullptr){
        if (key == t->data){
            return t;
        } else if (key < t->data){
            t = t->left;
        } else {
            t = t->right;
        }
    }
    return nullptr;
}

TreeNode* getRoot() const { return root; }

TreeNode* getPreNode (TreeNode* node) {
        if (node == nullptr) {
            return nullptr;
        }
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
}

TreeNode* getSusNode (TreeNode* node) {
        if (node == nullptr) {
            return nullptr;
        }
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
}

TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->data == key) {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }

            TreeNode* pre = getPreNode (root->left);
            TreeNode* sus = getSusNode (root->right);

            if (pre != nullptr) {
                int new_value = pre->data;
                deleteNode(root, pre->data);
                root->data = new_value;
            }
            else {
                int new_value = sus->data;
                deleteNode(root, sus->data);
                root->data = new_value;
            } 
        }
        else if (key < root->data) {
            root->left = deleteNode(root->left, key);
        }
        else {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }

};