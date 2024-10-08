class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

    DLLNode* reverseDLL(DLLNode* temp) {
        // Your code here
        DLLNode * head = nullptr;
        if (temp == nullptr || temp->next == nullptr) {
            return temp;
        }
        
        DLLNode* curr = temp;
        //newNode = 196                 //head = 59
        while (curr != nullptr) {
            if (curr->next == nullptr)
            head = curr;
            DLLNode* nn = curr->prev;
            DLLNode* next = curr->next;
            curr->next = nn;
            curr->prev = next;

            curr = next;
        }
        return head;
    }