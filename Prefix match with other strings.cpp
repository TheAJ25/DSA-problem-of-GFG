// Given an array of strings arr[] of size n, a string str and an integer k. The task is to find the count of strings in arr[] whose prefix of length k matches with the k-length prefix of str.

// Example 1:

// Input:
// n = 6
// arr[] = {“abba”, “abbb”, “abbc”, “abbd”, 
// “abaa”, “abca”}
// str = “abbg”
// k = 3
// Output: 
// 4 
// Explanation:
// “abba”, “abbb”, “abbc” and “abbd” have their prefix of length 3 equal to 3-length prefix of str i.e., "abb".
// Example 2:

// Input:
// n = 3
// arr[] = {“geeks”, “geeksforgeeks”, “forgeeks”}
// str = “geeks”
// k = 2
// Output: 
// 2
// Explanation:
// “geeks” and “geeksforgeeks” have their prefix of length 2 equal to 2-length prefix of str i.e., "ge".
// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function klengthpref() which takes the array of strings arr[], its size n and an integer k, a string str as input parameters and returns the count of strings in arr[] whose prefix of length k matches with the k length prefix of str.

// Expected Time Complexity: O(n*l) where l is the length of the longest word in arr[].
// Expected Auxiliary Space: O(n*l) where l is the length of the longest word in arr[].



class Solution{   
public:
    int klengthpref(string arr[], int n, int k, string str){
        if(k > str.length()){
            return 0;
        }
        string temp = str.substr(0,k);
        int count = 0;
        for(int i=0; i<n; i++){
            if(temp == arr[i].substr(0,k)){
                count ++;
            }
        }
        return count;
    }
};
