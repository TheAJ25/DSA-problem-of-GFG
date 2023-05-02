question:

/*
Geek is organizing a birthday party, so his friends brought a cake for him. The cake consists of N chunks, whose individual sweetness is represented by the sweetness array. Now at the time of distribution, Geek cuts the cake into K + 1 pieces to distribute among his K friends. One piece he took for himself. Each piece consists of some consecutive chunks. He is very kind, so he left the piece with minimum sweetness for him.

You need to find the maximum sweetness that the Geek can get if he distributes the cake optimally.

Example 1:

Input:
N  = 6, K = 2
sweetness[] = {6, 3, 2, 8, 7, 5}
Output:
9
Explanation:
Geek can divide the cake to [6, 3], [2, 8], [7, 5] 
with sweetness level 9, 10 and 12 respectively.
Example 2:

Input:
N  = 7, K = 3
sweetness[] = {1, 2, 4, 7, 3, 6, 9}
Output:
7
Explanation:
Geek can divide the cake to [1, 2, 4], [7], [3, 6], [9] 
with sweetness level 7, 7, 9 and 9 respectively.
Your Task:
You need to complete the maxSweetness() function which takes an integer array of sweetness, an integer N and an integer K as the input parameters and returns an integer denoting the maximum sweetness that the Geek can get.

Expected Time Complexity: O(NlogM), where M is the sum of elements in the array.
Expected Space Complexity: O(1)

Constraints:
1 <= N <= 105
0 <= K < N
1 <= sweetness[i] <= 109
*/
-------------------------------------------------------------------------------------------------------------------------------------


approach:

/*
At the first look, it seems to be the MCM question, i.e. standard dp. Try partioning, at every interal and find the answer, but gives TLE, and only 12 test cases passed. Adding code for reference. 

// User function Template for C++

class Solution{
    public:
    
    map<vector<int>, int> m;
    int f(vector<int> &a, int n, int k, int si, int prev){
        
        // cout << prev << endl;
        // base case 
        if(k == 0){
            int sum = 0;
            for(int i = si; i < n; i++){
                sum += a[i];
            }
            int val = min(prev, sum);
            return val;
        }
        
        if(m.find({k, si, prev}) != m.end()) return m[{k, si, prev}];
        
        int sum = 0;
        int res = INT_MIN;
        for(int i = si; i < n - k; i++){
            sum += a[i];
            
            int val = min(prev, sum);
            int temp = f(a, n, k - 1, i + 1, val);
            
            res = max(res, temp);
        }
        
        return m[{k, si, prev}] =  res;
    }
    int maxSweetness(vector<int>& a, int n, int k) {
    // Write your code here.
        int res = f(a, n, k, 0, INT_MAX);
        
        return res;
    }
};
Now, we come to binary search, look at the example, in the problem, each subarray, has the sum either equal to the required answer, or greater than it. Ok then, we will take our search space as l = 1, h = sum(array). Apply binary search, for a particular mid value, we will calculate the the number of pieces, as shown in the code. 

if pieces cut are less than total required i.e. k + 1, then, h has to be decreased,  by mid - 1, so that total pieces can be increased, else increment l, by mid + 1. 

Dry run the code, then only this question can be understand well. 

    int maxSweetness(vector<int>& a, int n, int k) {
        
        int l = 1;
        int h = 0;
        
        for(int i = 0; i < n; i++){
            h += a[i];
        }
        
        // int ans;
        while(l <= h){
            int mid = l + (h-l)/2;
            
            
            int piece = 0;
            int sweet = 0;
            for(int i = 0; i < n; i++){
                sweet += a[i];
                
                if(sweet >= mid){
                    piece++;
                    sweet = 0;
                }
            }
            
            if(piece < k+1){
                h = mid  - 1;
            }
            else{
                // ans = mid;
                l = mid+1;
            }
        }
        
        return h;
    }
*/    
    
    

class Solution{
    public:
    int maxSweetness(vector<int>& a, int n, int k){
        
        int l = 1;
        int h = 0;
        
        for(int i = 0; i < n; i++){
            h += a[i];
        }
        
        // int ans;
        while(l <= h){
            int mid = l + (h-l)/2;
            
            
            int piece = 0;
            int sweet = 0;
            for(int i = 0; i < n; i++){
                sweet += a[i];
                
                if(sweet >= mid){
                    piece++;
                    sweet = 0;
                }
            }
            
            if(piece < k+1){
                h = mid  - 1;
            }
            else{
                // ans = mid;
                l = mid+1;
            }
        }
        
        return h;
    }
};


