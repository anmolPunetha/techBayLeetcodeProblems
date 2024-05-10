class StockSpanner {
public:
    stack<pair<int,int>>s; //day,price
    int day;
    StockSpanner() {
        day=1;
    }
    
    int next(int price) {
        int ans=0;
        //i need to know i am talking about which day
        //implementing NGL
        while(!s.empty() and s.top().second<=price){
            s.pop();
        }
        if(s.empty()){
            ans=day;
        }
        else{
            int ngl_day = s.top().first;
            ans=day-ngl_day;
        }
        s.push({day,price});
        day+=1;

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */


