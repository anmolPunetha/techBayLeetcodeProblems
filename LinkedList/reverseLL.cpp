class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head or !(head->next))return head;

        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nxt=head; //any initialised value is fine

        while(curr!=NULL){
            nxt=curr->next;
            curr->next=prev;

            prev=curr;
            curr=nxt;
        }
        return prev;
    }
};
