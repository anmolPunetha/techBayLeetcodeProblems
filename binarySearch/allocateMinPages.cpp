class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isMidPossible(int A[], long int mid, int m, int n){
        int numOfStu=1;
        long int pages=0;
        for(int i=0;i<n;i++){
            int curr_book=A[i];
            if(pages+curr_book<=mid){
                pages+=curr_book;
            }else{
                numOfStu++;
                pages=curr_book;
            }
        }
        if(numOfStu<=m) return true;
        return false;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        //range=max(books) to sum(books)=>90 to sth
        long int start=0, end=0;
        for(int i=0;i<N;i++){
            start=max(start, (long int)A[i]);
            end+=A[i];
        }
        if(M>N) return -1;
        int ans=-1;
        while(start<=end){
            long int mid=(start+end)/2;
            if(isMidPossible(A,mid, M, N)==true){
                ans=mid;
                end=mid-1; //would depend upon question
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
    
};


// s1=12
// s2=34+67+90=191

// s1=12+34+67=113
// s2=90

// s1=12+34=46
// s2=67+90=157

// - - - - - - - - - 
// m=2
// {12,34,67,90,}
// op1=150
// s1=12+34+67
// s2=90

// op=100
// s1=12+34
// s2=67
// s3=90

// op=110

//prob LINK: https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
