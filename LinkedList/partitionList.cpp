class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* smaller=new ListNode(-1);
        ListNode* greater=new ListNode(-1);
        ListNode* s_tail=smaller;
        ListNode* g_tail=greater;

        while(head!=NULL){
            if(head->val<x){
                //merge it with smaller
                s_tail->next=head;
                s_tail=s_tail->next;
                //break the link
            }else{
                //merge with greater
                g_tail->next=head;
                g_tail=g_tail->next;
            }
            head=head->next;
        }
        s_tail->next=greater->next;
        g_tail->next=NULL;
        return smaller->next;
    }
};
