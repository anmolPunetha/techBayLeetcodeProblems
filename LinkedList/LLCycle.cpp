class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //detect
        //find the junction node=the node where cuycle begins
        ListNode*fast=head;
        ListNode*slow=head;

        if(head==NULL or head->next==NULL)return NULL;

        while(fast!=NULL and fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)break;
        }

        if(fast!=slow)return NULL; //no cycle

        //finding the junction node
        fast=head;
        //slow is poitning to the first meeting point
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow; //junction node
    }
};
