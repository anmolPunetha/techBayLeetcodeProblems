class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>treeInfo;
        int result=0;
        int start=0, end=0, sizeOfArr = fruits.size();
        while(end<sizeOfArr){
            //expand the window
            //3 buckets used->shrink here
            //update the ans with the count of fruits we have=>window's size
            //start,end=> curr_window_size=end-start+1
            //if ans exceeds my overall ans, i will update
            
            treeInfo[fruits[end]]+=1;
            while(treeInfo.size()>2){ //the no. of buckets used hsould be less or equalt to 2
                //u need to shrink
                treeInfo[fruits[start]]-=1;
                if(treeInfo[fruits[start]]==0){
                    treeInfo.erase(fruits[start]);
                }
                start+=1;
            }
            int curr_window_size=end-start+1;
            result=max(result,curr_window_size);
            end+=1;
        }
        return result;
    }
};

// fruits = [1,2,1,3,2,2, 3,2]
// bucket1=2,2,2
// bucket2=3,3
// ans=5
// overallans=5

// [1,3]

// b1=1
// b2=3

// fruits = [0,2,1,2,1,2,2,3,3,3,3,3]
// ans=3
// overallans=3
// [2,3]
// b1=2,2
// b2=3

//map/dict->key=fruittype, value=count of that type
// [2]->1
//rthe size of map/dict = no. of buckets used

// fruits = [0,1,2,2]
// start=1
// result=3


// map[1]=1
// map[2]=4
// end=3
// [1,2,2,2,2]

//TC: O(N)
//SC: O(1)
