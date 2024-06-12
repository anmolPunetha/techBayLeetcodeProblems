class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {   
        //code here
        vector<int>ans;
        //priority_queue<int, vector<int>, greater<int>>>;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq; //declaration fo creating a min heap of vector<int>
        for(int i=0;i<k;i++){
            //arr[i][0], i, 0 ::: element, array index, element index
            pq.push({arr[i][0],i,0});
            
        }
        while(pq.empty()==false){
            vector<int> f = pq.top(); //referring the topmost element
            pq.pop();  //removing the topmost element
            int ele=f[0], arr_index=f[1], ele_index=f[2];
            ans.push_back(ele); //saving in ans
            
            //check and push the next element
            if(ele_index==k-1){
                continue;
            }
            pq.push({arr[arr_index][ele_index+1],arr_index,ele_index+1});
            
        }
        return ans;
    }
};
