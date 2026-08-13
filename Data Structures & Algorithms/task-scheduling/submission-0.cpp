class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        // first of all i try to solve with heap with map
        vector<int> freq(26, 0);  // here we store the freq of char

        for (int i = 0; i < m; i++) {
            freq[tasks[i] - 'A']++;
        }

        // push in max heap
        priority_queue<int> pq;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push(freq[i]);
            }
        }

        // our target to pick the most frequent element and use iterator
        int count=0;
        while (!pq.empty()) {
            vector<int> arr;  // it is use to store the ferquency of char after reduced by one
            for (int i = 1; i <= n + 1; i++) {
                if (pq.size() > 0) {
                    int x = pq.top();
                    pq.pop();
                    x = x - 1;
                    if (x > 0) {
                        arr.push_back(x);
                    }
                }

                count++;
                if(pq.size()==0 && arr.size()==0){
                    return count;
                }
            }
            for (int j = 0; j < arr.size(); j++) {
                if (arr.size() > 0) {
                   pq.push(arr[j]);
                }
            }
            // if (!pq.empty()) {
            //     count += (n + 1) - arr.size();
            // }
            
        }
        return -1;
    }
};
