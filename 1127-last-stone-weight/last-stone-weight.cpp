class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(),stones.end());
        while(!maxHeap.empty()){
            int a,b;
            if(!maxHeap.empty()){
                 a = maxHeap.top();
                 maxHeap.pop();
            }else{
                break;
            }
            if(!maxHeap.empty()){
                 b = maxHeap.top();
                 maxHeap.pop();
            }else{
                maxHeap.push(a);
                break;
            }
            int diff = abs(a-b);
            maxHeap.push(diff);
        }
        if(maxHeap.empty()) return 0;
        return maxHeap.top();
    }
};