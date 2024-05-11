class Solution {
public:
    vector<int> getNSL(vector<int>& h){
        stack<int>s;
        int sz=h.size();
        vector<int>nsl(sz, -1);
        for(int i=0;i<h.size();i++){
            while(!s.empty() and h[s.top()]>=h[i]){
                s.pop();
            }
            if(!s.empty()){
                nsl[i]=s.top();
            }
            s.push(i);
        }
        return nsl;
    }
    vector<int> getNSR(vector<int>& h){
        stack<int>s;
        int sz=h.size();
        vector<int>nsr(sz, sz); //initialling it with size of array
        for(int i=sz-1;i>=0;i--){
            while(!s.empty() and h[s.top()]>=h[i]){
                s.pop();
            }
            if(!s.empty()){
                nsr[i]=s.top();
            }
            s.push(i);
        }
        return nsr;
    }
    int largestRectangleArea(vector<int>& heights) {
        //nsl, nsr
        vector<int>nsl = getNSL(heights);
        vector<int>nsr = getNSR(heights);
        int ans=0;
        for(int i=0;i<heights.size();i++){
            int curr_area = (nsr[i]-nsl[i]-1)*heights[i];
            ans=max(ans,curr_area);
        }
        return ans;
    }
};
//0
//no nsl->i can take all index on the left
//at 5: from 0 to 5->6
//5-0=5
//5-(-1)=6
