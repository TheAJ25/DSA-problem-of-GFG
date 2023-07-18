// Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.

// The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B. For example, A = "xax" and B = "xax" then the index of first "x" must be different in the original string for A and B.

// Example 1:

// Input:
// str = "axxzxy"
// Output: 2
// Explanation:
// The given array with indexes looks like
// a x x z x y 
// 0 1 2 3 4 5

// The longest subsequence is "xx". 
// It appears twice as explained below.

// subsequence A
// x x
// 0 1  <-- index of subsequence A
// ------
// 1 2  <-- index of str 


// subsequence B
// x x
// 0 1  <-- index of subsequence B
// ------
// 2 4  <-- index of str 

// We are able to use character 'x' 
// (at index 2 in str) in both subsequences
// as it appears on index 1 in subsequence A 
// and index 0 in subsequence B.
// Example 2:

// Input:
// str = "axxxy"
// Output: 2
// Explanation:
// The given array with indexes looks like
// a x x x y 
// 0 1 2 3 4

// The longest subsequence is "xx". 
// It appears twice as explained below.

// subsequence A
// x x
// 0 1  <-- index of subsequence A
// ------
// 1 2  <-- index of str 


// subsequence B
// x x
// 0 1  <-- index of subsequence B
// ------
// 2 3  <-- index of str 

// We are able to use character 'x' 
// (at index 2 in str) in both subsequences
// as it appears on index 1 in subsequence A 
// and index 0 in subsequence B.

// Your Task:
// You don't need to read or print anything. Your task is to complete the LongestRepeatingSubsequence() which takes str as input parameter and returns the length of the longest repeating subsequnece.


// Expected Time Complexity: O(n2)
// Expected Space Complexity: O(n2)



class Solution {

public:

    int maxSub(int i, int j, int n, string& s, vector<vector<int>>& dp) {

        if (i == n || j == n)

            return 0;

 

        if (dp[i][j] != -1)

            return dp[i][j];

 

        if (i != j && s[i] == s[j]) {

            dp[i][j] = 1 + maxSub(i + 1, j + 1, n, s, dp);

        } else {

            dp[i][j] = maxSub(i, j + 1, n, s, dp);

            dp[i][j] = max(dp[i][j], maxSub(i + 1, j, n, s, dp));

        }

 

        return dp[i][j];

    }

 

    int LongestRepeatingSubsequence(string str) {

        int n = str.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return maxSub(0, 0, n, str, dp);

    }

};
