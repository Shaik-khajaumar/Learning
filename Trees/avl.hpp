#include <iostream>
#include <vector>
#include <map>

class TreeNode {
    public:
    int data;
    int height;
    TreeNode * left;
    TreeNode * right;

    TreeNode (int d, int ht) : data(d), height(ht), left(nullptr), right (nullptr) {}
    TreeNode (int d) : data(d), height(0), left(nullptr), right (nullptr) {}

    int getData() const { return data; }
};

class avl {
    // std::map<TreeNode*, int> mp;
    TreeNode* root;

    public:
    avl () : root (nullptr) {};

    void deleteNode (TreeNode* node) {
        if (node) {
            deleteNode (node->left);
            deleteNode (node->right);
            delete node;
        }
    }
    ~avl () {
        deleteNode(root);
    }
    
    TreeNode* insert (TreeNode* root, int key)  {
        
        if (root == nullptr) {
            // mp[root] = 0;
            return new TreeNode(key, 0);
        }
        /*
            first insert at appropriate place

            if unbalanced perform rotation and update height

            if correct only then just update heights
            
            return
        */

        if (key < root->data) {
            root->left = insert (root->left, key);
        }
        else {
            root->right = insert (root->right, key);
        }

        //update height

        if (root->left != nullptr) {
                root->height = std::max(root->left->height + 1, root->height);
        }
        if (root->right != nullptr) {
                root->height = std::max(root->right->height + 1, root->height);
            }

        // checking balance factor now

        int left_ht = 0, right_ht = 0;
        if (root->left != nullptr) {
            left_ht = root->left->height + 1;
        }
        if (root->right != nullptr) {
            right_ht = root->right->height + 1;
        }

        int balance_factor = left_ht - right_ht;

        if (balance_factor < -1 || balance_factor > 1) {
            if (key < root->data) {
                //left tree is big
                if (key > root->left->data) {
                    /*  
                    right tree is big, this is LR
                    lr means sub_root is rotated to left and root is rotated to right
                    sub_root is root->left
                    */
                    root->left = rr_rotation(root->left); 
                    root = ll_rotation(root);
                }
                else {
                    //left tree is big, this is LL
                    root = ll_rotation(root);
                }
            }
            else {
                //right tree is big
                if (key < root->right->data) {
                    //left tree is big, this is RL
                    //rl means sub_root is roatated to right and root is rotated to left
                    root->right = ll_rotation(root->right);
                    root = rr_rotation(root);
                }
                else {
                    //right tree is big, this is RR
                    root = rr_rotation(root);
                }
            }
            return root;
        }

        return root;
    }

    TreeNode* deleteNode (TreeNode* root, int key)  {

    }

    int height (TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return std::max(height(root->left), height(root->right)) + 1;
    }

    TreeNode* rr_rotation (TreeNode* root) {
        std::cout<<"in rr\n";
        //total left from root

        TreeNode* root_right = root->right;
        TreeNode* root_right_left = root_right->left;
        root->right = root_right_left;  
        root_right->left = root;

        //update heights of root, then root_right
        root->height = 0;
        if (root->left != nullptr) {
            root->height = std::max(root->left->height + 1, root->height);
        }
        if (root->right != nullptr) {
            root->height = std::max(root->right->height + 1, root->height);
        }

        root_right->height = 0;
        if (root_right->left != nullptr) {
            root_right->height = std::max(root_right->left->height + 1, root_right->height);
        }
        if (root_right->right != nullptr) {
            root_right->height = std::max(root_right->right->height + 1, root_right->height);
        }

        return root_right;
    }

    TreeNode* ll_rotation (TreeNode* root) {
        std::cout<<"in ll\n";
        //total right from root

        TreeNode* root_left = root->left;
        TreeNode* root_left_right = root_left->right;
        root->left = root_left_right;  
        root_left->right = root;

        //update heights of root, then root_left
        root->height = 0;
        if (root->left != nullptr) {
            root->height = std::max(root->left->height + 1, root->height);
        }
        if (root->right != nullptr) {
            root->height = std::max(root->right->height + 1, root->height);
        }

        root_left->height = 0;
        if (root_left->left != nullptr) {
            root_left->height = std::max(root_left->left->height + 1, root_left->height);
        }
        if (root_left->right != nullptr) {
            root_left->height = std::max(root_left->right->height + 1, root_left->height);
        }

        return root_left;
    }

    void inorder_traversal (TreeNode* temp) {
    if (temp == nullptr) {
        return;
    }
    inorder_traversal(temp->left);
    std::cout<<"value: "<<temp->data<<"\n";
    inorder_traversal(temp->right);

    }

    TreeNode* getRoot() const { return root; }

};

