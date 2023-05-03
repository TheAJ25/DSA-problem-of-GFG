/*
You are given an array of strings arr of size n. You have to find out if it is possible to make a palindromic string by concatenating the strings in any order. Provided that all the strings given in the array are of equal length.

Example 1:

Input:
n = 4
arr = {"djfh", "gadt", "hfjd", "tdag"}
Output:
YES
Explanation:
You can make the string "djfhgadttdaghfjd", by concatenating the given strings which is a palindrome.
Example 2:

Input:
n = 3
arr = {"jhjdf", "sftas", "fgsdf"}
Output:
NO
Explanation:
You can't make a palindromic string with this strings.
Your Task:
You don't need to read input or print anything. Your task is to complete the function makePalindrome() which takes an integer n and an array of strings arr respectively and returns true or false.

Expected Time Complexity: O(n * len(arr[i]))
Expected Space Complexity: O(n * len(arr[i]))
*/

code -


class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
        // Code here
        unordered_map<string,int> mp;
        for(auto it:arr)
        {
            string rev=it;
            reverse(rev.begin(),rev.end());
            if(mp.find(rev)!=mp.end())
            {
                mp[rev]--;
                if(mp[rev]==0) mp.erase(rev);
            }
            else
            {
                mp[it]++;
            }
        }
        if(mp.size()==0) return true;
        if(mp.size()==1)
        {
            string curr=mp.begin()->first;
            string rev=curr;
            reverse(rev.begin(),rev.end());
            return rev==curr;
        }
        return false;
    }
};
