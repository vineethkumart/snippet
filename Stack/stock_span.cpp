// This is a good application of stack
// Given an array and you have to report span of each day. Span meaning consecutive days where the stock price is increasing
// 1,2,3,4,5 span is [1,1,2,3,4]
//

class StockSpanner {
public:
    StockSpanner() {
        i = 0;
    }

    int next(int price) {
        v.push_back(price);
        int span(1);

        if (s.empty()) {
            s.push(i);
        }
        else if (price < v[s.top()]) {
            s.push(i);
        } else {
            while (!s.empty() && v[s.top()] <= price) {
                s.pop();
            }
            int sp = -1;
            if (!s.empty()) sp  = s.top();
            span = (i - sp);
            s.push(i);
        }

        i++;
        return span;
    }

    vector<int> v;
    int i;
    stack<int> s;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
