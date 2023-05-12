/*
You are given an array arr of n integers. You must return the minimum number of operations required to make this array 0. For this you can do an operation :

Choose a sub-array of non-zero elements & replace all with 0(0 must be present in arr, if not you can not replace it).
Example 1:

Input:
n = 4
arr = {3,0,4,5}
Output:
2
Explanation:
First, we can choose 3 replace with 0(which is on 1st Index) and in the second operation, we can choose 4 & 5 -> replace with 0(1st Index).

Example 2:

Input:

n = 8 
arr = {10,4,9,6,10,10,4,4} 
Output: 
-1 
Explanation: 
If we do operations here, we can not make the entire 0 
because no 0 is present in the array, hence -1.
Your Task:
You don't need to read input or print anything. Your task is to complete the function arrayOperations() which takes an integer n and an array arr as inputs and find the minimum number of operations you must perform to make all the elements of the array 0. If not possible return -1;

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= n <= 105
0 <= arr[i] <= 109
*/


Logic: The number of operations requried depends upon the number of subarrays which is counted using the number of 0s (0 must not be consecutive).

     In the below code, the above mentioned logic is applied with few modifications such as:

If there exists any non-zero value at the end of the array it means that this particular subarray is missed. So, in order to consider this subarray the value of count is incremented outisde the loop. 
If the 0s are consecutive then the above mentioned logic fails especially when the 0s are at the terminals of the array. Therefore, the variable nonZero is used which counts the non-zero values. And, the subarray is only counted when it exists (i.e., there is non-zero values between two 0s).
Now if, the array doesn't consist any of it's element valued 0 then the value of the variable nonZero must be equal to the length of the array and in that case it must return -1.
  
  
  
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        // code here
        int count=0, nonZero=0;
        for(int i=0;i<n;i++)
            if(arr[i]==0){
                if(nonZero) //there must exist a subarray
                    count++;
                nonZero=0; // one subarray traversed
            }
            else
                nonZero++;
        if(nonZero==n)
            return -1;
        else if(nonZero)
            count++;
        return count;
    }
};
