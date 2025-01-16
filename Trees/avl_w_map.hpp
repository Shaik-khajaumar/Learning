#include <iostream>
#include <vector>
#include <map>

class TreeNode {
    public:
    int data;
    TreeNode * left;
    TreeNode * right;

    TreeNode (int d) : data(d), left(nullptr), right (nullptr) {}

    int getData() const { return data; }
};

class avl {
    std::map<TreeNode*, int> mp;
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
            mp[root] = 0;
            return new TreeNode(key);
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

        //update heights
        if (root->left != nullptr) {
            mp[root] = std::max(mp[root->left] + 1, mp[root]);
        }
        if (root->right != nullptr) {
            mp[root] = std::max(mp[root->right] + 1, mp[root]);
        }

        // checking balance factor now

        int left_ht = 0, right_ht = 0;
        if (root->left != nullptr) {
            left_ht = mp[root->left] + 1;
        }
        if (root->right != nullptr) {
            right_ht = mp[root->right] + 1;
        }

        int balance_factor = left_ht - right_ht;

        if (balance_factor < -1 || balance_factor > 1) {
            if (key < root->data) {
                //left tree is big
                if (key > root->left->data) {
                    //right tree is big, this is LR
                    //lr means sub_root is rotated to left and root is rotated to right
                    //sub_root is root->left
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
        mp[root] = 0;
        if (root->left != nullptr) {
            mp[root] = std::max(mp[root->left] + 1, mp[root]);
        }
        if (root->right != nullptr) {
            mp[root] = std::max(mp[root->right] + 1, mp[root]);
        }

        mp[root_right] = 0;
        if (root_right->left != nullptr) {
            mp[root_right] = std::max(mp[root_right->left] + 1, mp[root_right]);
        }
        if (root_right->right != nullptr) {
            mp[root_right] = std::max(mp[root_right->right] + 1, mp[root_right]);
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
        mp[root] = 0;
        if (root->left != nullptr) {
            mp[root] = std::max(mp[root->left] + 1, mp[root]);
        }
        if (root->right != nullptr) {
            mp[root] = std::max(mp[root->right] + 1, mp[root]);
        }

        mp[root_left] = 0;
        if (root_left->left != nullptr) {
            mp[root_left] = std::max(mp[root_left->left] + 1, mp[root_left]);
        }
        if (root_left->right != nullptr) {
            mp[root_left] = std::max(mp[root_left->right] + 1, mp[root_left]);
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

