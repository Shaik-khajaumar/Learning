#include <iostream>
#include <queue>
#include <stack>

class Node {
    public:
    int data;
    Node * left;
    Node * right;

    Node (int d) : data(d), left(nullptr), right (nullptr) {}
};

class BinaryTree {
    Node *root {nullptr};

    void preorderTraversal (Node* temp) {
        if (temp == nullptr) {
            return;
        }
        std::cout<<"Node value: "<<temp->data<<"\n";
        preorderTraversal(temp->left);
        preorderTraversal(temp->right);
    }

    void inoderTraversal (Node* temp) {
        if (temp == nullptr) {
            return;
        }
        inoderTraversal(temp->left);
        std::cout<<"Node value: "<<temp->data<<"\n";
        inoderTraversal(temp->right);
    }
    void postorderTraversal (Node* temp) {
        if (temp == nullptr) {
            return;
        }
        postorderTraversal(temp->left);
        postorderTraversal(temp->right);
        std::cout<<"Node value: "<<temp->data<<"\n";
    }

    void deleteNodesRecursively (Node* temp) {
        if (temp == nullptr) {
            return;
        }
        // std::cout<<"deleting Node: "<<temp->data<<"\n";
        deleteNodesRecursively(temp->left);
        deleteNodesRecursively(temp->right);
    }

    int heightRecursively (Node* temp) {
        int x = 0, y = 0;
        if (temp == nullptr) {
            return 0;
        }
        x = heightRecursively(temp->left);
        y = heightRecursively(temp->right);
        if (x > y) {
            return x + 1;
        }
        else {
            return y + 1;
        }
    }

    int countRecursively (Node* temp) {
        int x = 0, y = 0;
        if (temp == nullptr) {
            return 0;
        }
        else {
            x = countRecursively(temp->left);
            y = countRecursively(temp->right);
            return x + y + 1; 
        }

    }


    public:

    BinaryTree () : root(nullptr) {
    }

    ~BinaryTree () {
        //delete all dynamically allocated nodes
        deleteNodesRecursively (root);
    }

    void insert (int val) {
        Node * newNode = new Node (val);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty ()) {
            Node * temp = q.front();
            q.pop();

            if (temp->left == nullptr) {
                temp->left = newNode;
                return;
            }
            q.push(temp->left);

            if (temp->right == nullptr) {
                temp->right = newNode;
                return;
            }
            q.push(temp->right);
        }

    }

    void preorder () {
        //root then preorder(left), preorder(right);
        preorderTraversal(root);
    }

    void inorder () {
        //Left, root, right
        inoderTraversal(root);
    }

    void postorder () {
        //left, right, root
        postorderTraversal(root);
    }

    void levelorder () {
        if (root == nullptr) {
            return;
        }
        std::cout<<"Node: "<<root->data<<"\n";
        std::queue<Node*> q;
        q.push(root);

        while (!q.empty ()) {
            Node * temp = q.front();
            q.pop();

            if (temp->left != nullptr) {
                std::cout<<"Node: "<<temp->left->data<<"\n";
                q.push(temp->left);
            }

            if (temp->right != nullptr) {
                std::cout<<"Node: "<<temp->right->data<<"\n";
                q.push(temp->right);
            }
        }
    }

    int count () {
        return countRecursively (root);
    }

    int height () {
        return heightRecursively (root);
    }

    void preorderIterative () {
        std::stack <Node*> st;
        if (root == nullptr) {
            std::cout<<"Tree is empty\n";
            return;
        }

        st.push(root);
        Node * temp = st.top();
        while (!st.empty()) {
            if (temp != nullptr) {
                std::cout<<temp->data<<"\n";
                st.push(temp);
                temp = temp->left;
            }
            else {
                temp = st.top();
                temp = temp->right;
                st.pop();
            }
        }
    }

    void inorderIterative () {
        std::stack <Node*> st;
        if (root == nullptr) {
            std::cout<<"Tree is empty\n";
            return;
        }

        st.push(root);
        Node * temp = st.top();
        temp = temp->left;
        while (temp != nullptr || !st.empty()) {
        if (temp != nullptr) {
            st.push(temp);
            temp = temp->left;
        }
        else {
            temp = st.top();
            st.pop();
            std::cout<<temp->data<<"\n";
            temp = temp->right;
        }
        }
    }

    void postorderIterative () {
        std::stack<std::pair<Node*, bool>> st;
        if (root == nullptr) {
            std::cout<<"Tree is empty\n";
            return;
        }

        st.push({root, true});
        Node * temp = root->left;
        while (!st.empty()) {
            if (temp != nullptr) {
                st.push({temp, true});
                temp = temp->left;
            }
            else {
                std::pair t = st.top();
                Node * tn = t.first;
                if (t.second == true) {
                    temp = tn->right;
                    st.pop();
                    st.push({tn, false});
                }
                else {
                    std::cout<<"data: "<<tn->data<<"\n";
                    st.pop();
                    temp = nullptr;
                }
            }
        }
    }

    void topview () {

    }

    void bottomview () {

    }

    void leftview () {

    }

    void rightview () {
        
    }
};

int main () {
    BinaryTree BT;
    int a = 2;
    BT.insert(1);
    BT.insert(2);
    BT.insert(3);
    BT.insert(4);
    BT.insert(5);
    BT.insert(6);
    BT.insert(7);
    BT.insert(8);

    
    BT.levelorder();
    std::cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
    BT.preorder();
    std::cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
    BT.preorderIterative();
    std::cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
    BT.inorder();
    std::cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
    BT.inorderIterative();
    std::cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
    BT.postorder();
    std::cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
    BT.postorderIterative();
    std::cout<<"No of nodes: "<<BT.count()<<"\n";
    std::cout<<"Height of tree: "<<BT.height()<<"\n";
}
