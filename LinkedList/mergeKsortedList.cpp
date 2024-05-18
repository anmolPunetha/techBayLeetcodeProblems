class Solution {
public:
    ListNode* helper(ListNode* a, ListNode* b){
        //base cases
        if(a==NULL)return b;
        if(b==NULL)return a;

        //main structure
        ListNode*mergedL;

        if(a->val<b->val){
            //a's node should come first
            mergedL=a;
            mergedL->next=helper(a->next, b);
        }else{
            mergedL=b;
            mergedL->next=helper(a, b->next);
        }
        return mergedL;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int sz=lists.size();
        if(sz==0)return NULL;
        if(sz==1)return lists[0];

        ListNode* ans=helper(lists[0],lists[1]);
        for(int i=2;i<sz;i++){
            ans=helper(ans,lists[i]);
        }
        return ans;
    }
};
