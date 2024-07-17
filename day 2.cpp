// 1. Palindrome Linked List

bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return 1;
        }
        
        struct ListNode* slow = head;
        struct ListNode* fast = head;
        vector<int> stack; 
        
        while(fast){
            stack.push_back(slow->val);
            
            if(fast==NULL || fast->next==NULL){
                break;
            }

            fast= fast->next->next;
            slow = slow->next;
        }
        while(!stack.empty()){
            if(stack.back()!=slow->val){
                return 0;
            }
            else{
                stack.pop_back();
                slow = slow->next;
            }
        }
        return 1;
    }


//2. Remove Duplicates from Sorted List II
ListNode* deleteDuplicates(ListNode* head) {
        struct ListNode* temp2 = head;
        struct ListNode* dummy = new ListNode(0,head);
        struct ListNode* temp1 = dummy;
        
        while(temp2!=NULL){
            
            if(temp2->next!=NULL &&  temp2->val == (temp2->next)->val){
                
                while(temp2->next!=NULL && temp2->val == (temp2->next)->val){
                    temp2 = temp2->next;
                }
                temp1->next = temp2->next;
                temp2 = temp1->next;
            }
            else{
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        head = dummy->next;
        return head;
    }
