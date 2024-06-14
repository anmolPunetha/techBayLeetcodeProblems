 class MedianFinder {
public:
    priority_queue<int>mxHeap;
    priority_queue<int, vector<int>, greater<int>>mnHeap;
    double med=0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //all logic here
        //update med variable
        //in which half should i push (the number <> median)
        //size is always maintained (diff<=1)
        if(mxHeap.size()>mnHeap.size()){ //left half has more size
            if(num>med){
                mnHeap.push(num); //pushing to the right half
            }else{
                mnHeap.push(mxHeap.top());
                mxHeap.pop();
                mxHeap.push(num);
            }
            med=(mnHeap.top()+mxHeap.top())/2.0;
        }
        else if(mxHeap.size() == mnHeap.size()){
            if(num>med){
                mnHeap.push(num); //pushing to the right half
                med=mnHeap.top();
            }else{
                mxHeap.push(num);
                med=mxHeap.top();
            }
        }
        else{ //right half has more size
            if(num>med){
                mxHeap.push(mnHeap.top());
                mnHeap.pop();
                mnHeap.push(num); //pushing to the right half
            }else{
                mxHeap.push(num);
            }
            med=(mnHeap.top()+mxHeap.top())/2.0;
        }
    }
    
    double findMedian() {
        return med;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
