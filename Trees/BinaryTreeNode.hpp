#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>

class BinaryTreeNode {
    public:
    int data;
    BinaryTreeNode * left;
    BinaryTreeNode * right;

    BinaryTreeNode (int d) : data(d), left(nullptr), right (nullptr) {}
};

std::vector<int> preorder_traversal (BinaryTreeNode* temp) {
    if (temp == nullptr) {
        return std::vector<int> {};
    }
    std::vector<int> values; 
    values.push_back(temp->data);
    std::vector<int> t = preorder_traversal(temp->left);
    if (t.size() > 0) {
        values.insert(values.end(), t.begin(), t.end());
    }
    t = preorder_traversal(temp->right);
    if (t.size() > 0) {
        values.insert(values.end(), t.begin(), t.end());
    }
    return values;
}

std::vector<int> inorder_traversal (BinaryTreeNode* temp) {
    if (temp == nullptr) {
        return std::vector<int> {};
    }
    std::vector<int> values;
    std::vector<int> t = inorder_traversal(temp->left);
    if (t.size() > 0) {
        values.insert(values.end(), t.begin(), t.end());
    }
    values.push_back(temp->data);
    t = inorder_traversal(temp->right);
    if (t.size() > 0) {
        values.insert(values.end(), t.begin(), t.end());
    }
    return values;
}

std::vector<int> postorder_traversal (BinaryTreeNode* temp) {
    if (temp == nullptr) {
        return std::vector<int> {};
    }
    std::vector<int> values;
    std::vector<int> t = postorder_traversal(temp->left);
    if (t.size() > 0) {
        values.insert(values.end(), t.begin(), t.end());
    }
    t = postorder_traversal(temp->right);
    if (t.size() > 0) {
        values.insert(values.end(), t.begin(), t.end());
    }
    values.push_back(temp->data);
    return values;
}

std::vector<int> levelorder_traversal (BinaryTreeNode* root) {
    if (root == nullptr) {
        return std::vector<int> {};
    }
    std::vector<int> values;
    values.push_back(root->data);
    std::queue<BinaryTreeNode*> q;
    q.push(root);

    while (!q.empty ()) {
        BinaryTreeNode * temp = q.front();
        q.pop();

        if (temp->left != nullptr) {
            values.push_back(temp->left->data);
            q.push(temp->left);
        }

        if (temp->right != nullptr) {
            values.push_back(temp->right->data);
            q.push(temp->right);
        }
    }
    return values;
}

void delete_nodes_from (BinaryTreeNode* temp) {
    if (temp == nullptr) {
        return;
    }
    delete_nodes_from (temp->left);
    delete_nodes_from (temp->right);
}

int height (BinaryTreeNode* temp) {
    int x = 0, y = 0;
    if (temp == nullptr) {
        return 0;
    }
    x = height(temp->left);
    y = height(temp->right);
    if (x > y) {
        return x + 1;
    }
    else {
        return y + 1;
    }
}

int size (BinaryTreeNode* temp) {
    int x = 0, y = 0;
    if (temp == nullptr) {
        return 0;
    }
    else {
        x = size(temp->left);
        y = size(temp->right);
        return x + y + 1; 
    }

}

// BinaryTreeNode* insert (BinaryTreeNode* temp, int val) {
//     BinaryTreeNode * newNode = new BinaryTreeNode (val);

//     if (temp == nullptr) {
//         temp = newNode;
//         return temp;
//     }

//     std::queue<BinaryTreeNode*> q;
//     q.push(temp);

//     while (!q.empty ()) {
//         BinaryTreeNode * cur = q.front();
//         q.pop();

//         if (cur->left == nullptr) {
//             cur->left = newNode;
//             return cur->left;
//         }
//         q.push(cur->left);

//         if (cur->right == nullptr) {
//             cur->right = newNode;
//             return cur->right;
//         }
//         q.push(cur->right);
//     }
// }

std::vector<int> preorder_traversal_iterative (BinaryTreeNode* root) {
    std::stack <BinaryTreeNode*> st;
    if (root == nullptr) {
        return std::vector<int> {};
    }

    st.push(root);
    BinaryTreeNode * temp = st.top();
    std::vector<int> ans;
    while (!st.empty()) {
        if (temp != nullptr) {
            ans.push_back(temp->data);
            st.push(temp);
            temp = temp->left;
        }
        else {
            temp = st.top();
            temp = temp->right;
            st.pop();
        }
    }
    return ans;
}

std::vector<int> inorder_traversal_iterative (BinaryTreeNode* root) {
    std::stack <BinaryTreeNode*> st;
    if (root == nullptr) {
        return std::vector<int> {};
    }

    std::vector<int> values;
    st.push(root);
    BinaryTreeNode * temp = st.top();
    temp = temp->left;
    while (temp != nullptr || !st.empty()) {
    if (temp != nullptr) {
        st.push(temp);
        temp = temp->left;
    }
    else {
        temp = st.top();
        st.pop();
        values.push_back(temp->data);
        temp = temp->right;
    }
    }
    return values;
}

std::vector<int> postorder_traversal_iterative (BinaryTreeNode* root) {
    std::stack<std::pair<BinaryTreeNode*, bool>> st;
    if (root == nullptr) {
        return std::vector<int> {};
    }

    std::vector<int> values;
    st.push({root, true});
    BinaryTreeNode * temp = root->left;
    while (!st.empty()) {
        if (temp != nullptr) {
            st.push({temp, true});
            temp = temp->left;
        }
        else {
            auto t = st.top();
            BinaryTreeNode * tn = t.first;
            if (t.second == true) {
                temp = tn->right;
                st.pop();
                st.push({tn, false});
            }
            else {
                values.push_back(tn->data);
                st.pop();
                temp = nullptr;
            }
        }
    }
    return values;
}

std::vector<int> left_view (BinaryTreeNode* node) {
    if (node == nullptr) {  
        return std::vector<int> {};
    }

    std::queue<std::pair<int, BinaryTreeNode*>> q;
    q.push({0, node});
    
    std::vector<int> values;
    int req_level = 0;
    
    while (!q.empty()) {
        int level = q.front().first;
        BinaryTreeNode* temp = q.front().second;
        if (level == req_level) {
            values.push_back(temp->data);
            req_level++;
        }
        q.pop();
        if (temp->left != nullptr) {
            q.push({req_level, temp->left});
        }
        if (temp->right != nullptr) {
            q.push({req_level, temp->right});
        }
    }
    return values;
}

std::vector<int> right_view (BinaryTreeNode* node) {
    if (node == nullptr) {  
        return std::vector<int> {};
    }

    std::queue<std::pair<int, BinaryTreeNode*>> q;
    q.push({0, node});
    std::vector<int> values;
    int req_level = 0;
    while (!q.empty()) {
        int level = q.front().first;
        BinaryTreeNode* temp = q.front().second;
        if (level == req_level) {
            values.push_back(temp->data);
            req_level++;
        }
        q.pop();
        if (temp->right != nullptr) {
            q.push({req_level, temp->right});
        }
        if (temp->left != nullptr) {
            q.push({req_level, temp->left});
        }
    }
    return values;
}

/*
    Do Recursively also
*/
std::vector<int> bottom_view (BinaryTreeNode* node) {
    if (node == nullptr) {
        return std::vector<int> {};
    }
    std::vector<int> values;
    std::map<int, int> mp;
    std::queue<std::pair<int, BinaryTreeNode*>> q;  

    q.push({0, node});

    while (!q.empty()) {
        std::pair<int, BinaryTreeNode*> t = q.front();
        q.pop();

        int level = t.first;
        BinaryTreeNode* temp = t.second;

        if (mp.find(level) == mp.end()) {
            mp[level] = temp->data;
        }

        if (temp->left != nullptr) {
            q.push({level - 1, temp->left});
        }
        if (temp->right != nullptr) {
            q.push({level + 1, temp->right});
        }
    }

    for (std::pair<int, int> p : mp) {
        values.push_back(p.second);
    }

    return values;
}
//REVERSE BOTH TOPview AND BOTTOM view
std::vector<int> top_view(BinaryTreeNode* node) {
    if (node == nullptr) {
        return std::vector<int> {};
    }
    std::vector<int> values;
    std::map<int, int> mp;
    std::queue<std::pair<int, BinaryTreeNode*>> q;  

    q.push({0, node});

    while (!q.empty()) {
        std::pair<int, BinaryTreeNode*> t = q.front();
        q.pop();

        int level = t.first;
        BinaryTreeNode* temp = t.second;

        mp[level] = temp->data;

        if (temp->left != nullptr) {
            q.push({level - 1, temp->left});
        }
        if (temp->right != nullptr) {
            q.push({level + 1, temp->right});
        }
    }

    for (std::pair<int, int> p : mp) {
        values.push_back(p.second);
    }

    return values;
}

std::vector<int> morris_inorder (BinaryTreeNode* cur) {

    if (cur == nullptr) {
        return std::vector<int> {};
    }

    std::vector<int> values;
    while (cur != nullptr) {
        if (cur->left == nullptr) {
            values.push_back(cur->data);
            cur = cur->right;
        }
        else {
            BinaryTreeNode* temp = cur->left;
            
            while (temp->right != nullptr && temp->right != cur) {
                temp = temp->right;
            }

            if (temp->right == nullptr) {
                temp->right = cur;
                cur = cur->left;
            }
            else {
                temp->right = nullptr;
                values.push_back(cur->data);
                cur = cur->right; 
            }
        }
    }

    return values;

}

std::vector<int> morris_preorder (BinaryTreeNode* cur) {

    if (cur == nullptr) {
        return std::vector<int> {};
    }

    std::vector<int> values;
    while (cur != nullptr) {
        if (cur->left == nullptr) {
            values.push_back(cur->data);
            cur = cur->right;
        }
        else {
            BinaryTreeNode* temp = cur->left;
            
            while (temp->right != nullptr && temp->right != cur) {
                temp = temp->right;
            }

            if (temp->right == nullptr) {
                temp->right = cur;
                values.push_back(cur->data);
                cur = cur->left;
            }
            else {
                temp->right = nullptr;
                cur = cur->right; 
            }
        }
    }

    return values;

}