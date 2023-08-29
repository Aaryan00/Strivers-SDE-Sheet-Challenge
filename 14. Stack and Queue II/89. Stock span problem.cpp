class StockSpanner {

    stack<pair<int,int>> st;
    int index = -1;

public:
    StockSpanner() {
        while(!st.empty()){
            st.pop();
        }
        int index = -1;
    }
    
    int next(int price) {
        index++;
        int ans = 0;
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        if (!st.empty()){
            int previndex = st.top().second;
            ans = index - previndex ;
            
        }else{
            ans = index+1;
        }

        st.push({price,index});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */