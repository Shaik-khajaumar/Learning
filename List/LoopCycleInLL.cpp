
//  * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
bool hasCycle(ListNode *head) {
        if (head == nullptr)
        return false;
        ListNode *temp1 = head;
        ListNode *temp2 = head->next;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1 == temp2) 
            return true;
            temp1 = temp1->next;
            if(temp2->next != nullptr)
            temp2 = temp2->next->next;
            else
            temp2 = temp2->next;
        } 
        return false;
    }
};