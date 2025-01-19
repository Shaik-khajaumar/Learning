
//
//  avl.hpp
//  DataStructures
//
//  Created by Shaik on 18/01/25.
//

#ifndef avl_h
#define avl_h

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
    
    TreeNode* add(int key) {
        root = insert(root, key);
        return root;
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

        int balance_factor = get_balance_factor(root);

        if (balance_factor < -1 || balance_factor > 1) {
            if (balance_factor > 0) {
                //left tree is big
                int sub_root_balance_factor = get_balance_factor(root->left);
                if (sub_root_balance_factor < 0) {
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
                int sub_root_balance_factor = get_balance_factor(root->right);
                if (sub_root_balance_factor > 0) {
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

    TreeNode* get_pre (TreeNode* root) {
        //pre means go to left subtree and find right most node and return
        root = root->left;
        while (root && root->right != nullptr) {
            root = root->right;
        }
        return root;
    }

    TreeNode* get_suc (TreeNode* root) {
        //sucessor means go to right subtree and find left most node and return
        root = root->right;
        while (root && root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    int get_balance_factor(TreeNode* root) {
        // checking balance factor now

        int left_ht = 0, right_ht = 0;
        if (root->left != nullptr) {
            left_ht = mp[root->left] + 1;
        }
        if (root->right != nullptr) {
            right_ht = mp[root->right] + 1;
        }

        int balance_factor = left_ht - right_ht;
        return balance_factor;
    }
    
    TreeNode* remove (int key)  {
        root = remove_node (root, key);
        return root;
    }

    TreeNode* remove_node (TreeNode* root, int key) {
            
            if (root == nullptr) {
                return nullptr;
            }

            if (root->data == key) {
                //get inorder predessor or successor from that node only not from actual root
                if (root->left == nullptr && root->right == nullptr) {
                    //its a leaf node
                    mp.erase(root);
                    delete root;
                    //no need to check balance factor as we are removing the leaf node
                    root = nullptr;
                    return root;
                    
                }
                else if (root->left != nullptr && root->right == nullptr) {
                    mp.erase(root);
                    TreeNode* left_node = root->left;
                    delete root;
                    return left_node;
                }
                else if (root->right != nullptr && root->left == nullptr) {
                    mp.erase(root);
                    TreeNode* right_node = root->right;
                    delete root;
                    return right_node;
                }
                else {
                    TreeNode* pre = get_pre(root);
                    int new_value = pre->data;
                    root->left = remove_node(root->left, pre->data);
                    mp[root] = 0;
                    root->data = new_value;
                }
            }
            else if (key < root->data) {
                root->left = remove_node (root->left, key);
            }
            else {
                root->right = remove_node (root->right, key);
            }
            
            //important step, for examples if a node now becomes leaf then its height in update heights wont change as both conditions evaluate to false so doing this is important
            mp[root] = 0;

            //update heights
            if (root->left != nullptr) {
                mp[root] = std::max(mp[root->left] + 1, mp[root]);
            }
            if (root->right != nullptr) {
                mp[root] = std::max(mp[root->right] + 1, mp[root]);
            }

            // checking balance factor now

        int balance_factor = get_balance_factor(root);
            if (balance_factor < -1 || balance_factor > 1) {
                if (balance_factor < 0) {
                    //right tree is big and causing imbalance
                    int sub_root_balance_factor = get_balance_factor(root->right);
                    if (sub_root_balance_factor < 0) {
                        //right sub tree is big and causing imbalance, RR means total left
                        root = rr_rotation(root);
                    }
                    else {
                        //left sub tree is big, this is RL
                        root->right = ll_rotation(root->right);
                        root = rr_rotation(root);
                    }
                }
                else {
                    //left tree is big and causing imbalance
                    int sub_root_balance_factor = get_balance_factor(root->left);
                    if (sub_root_balance_factor > 0) {
                        //left sub tree is big, this is LL means total right
                        root = ll_rotation(root);
        
                    }
                    else {
                        //right sub tree is big, this is LR
                        root->left = rr_rotation(root->left);
                        root = ll_rotation(root);
                    }
                }
            }
            return root;
        }

    int height (TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return std::max(height(root->left), height(root->right)) + 1;
    }

    TreeNode* rr_rotation (TreeNode* root) {
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
    
    void levelOrder (TreeNode * root)
    {
      if (!root)
        return;

      std::queue < TreeNode * >q;
      q.push (root);

      while (!q.empty ())
        {
          int size = q.size ();
          for (int i = 0; i < size; i++)
        {
          TreeNode *node = q.front ();
          q.pop ();
          std::cout << node->data << " ";

          if (node->left)
            q.push (node->left);
          if (node->right)
            q.push (node->right);
        }
          std::cout << "\n";
        }
    }

    
    TreeNode* getRoot() const { return root; }


};


#endif /* avl_h */
