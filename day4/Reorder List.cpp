class Solution {
public: 
    ListNode* reverse(ListNode* head){
        struct ListNode *post = NULL;
        struct ListNode *curr = head;
        struct ListNode *prev = NULL;
            
        while(curr!= NULL){
            post = curr->next;
            curr->next = prev;
            prev = curr;
            curr = post;
        }
        head = prev;
        return head;
        }
    
    
    void reorderList(ListNode* head) {
        struct ListNode* slow = head;
        struct ListNode* fast = head;
        struct ListNode* temp;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        temp = reverse(slow->next);
        slow->next = NULL;
        
        struct ListNode* dummy = new ListNode(0);
        struct ListNode* dumb = dummy;
        
        while(head!=NULL && temp!=NULL){
            dumb->next = head;
            head = head->next;
            dumb = dumb->next;
            dumb->next = temp;
            dumb = dumb->next;
            temp = temp->next;
        }
        dumb->next = head;
        head = dummy->next;
    }
};
