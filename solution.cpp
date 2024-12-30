class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        priority_queue<int, vector<int>, greater<int>> q;
        for (int num : nums) {
            if (num > 0) {
                q.push(num);
            }
        }

        int count = 0;

       
        while (!q.empty()) {
            int a = q.top(); 
            q.pop();

           count++;
            priority_queue<int, vector<int>, greater<int>> tempq;
            while (!q.empty()) {
                int val = q.top();
                q.pop();
                val -= a;
                if (val > 0) {
                    tempq.push(val);
                }
            }

           
            q = tempq;
        }

        return count;
    }
};
