/*
You are given 5 integers - N,A,B,C,D.
Let us say all the integers of length N, having only A or B in their decimal representation are good integers. Also, among all the good integers, all those integers whose sum of digits contains either C or D or both are best integers.
Find the number of best integers of length N. Since the number of best integers can be huge, print it modulo 109+7.
 

Example 1:

Input:
N = 2, A = 1, B = 2, C = 3, D = 5
Output: 
2
Explanation: 
The following are good integers:- 
{ 12 , 22 , 11 , 21 }
And the following are best integers:- 
{ 12, 21 } because sum of digits of 11,22
are 2 and 4, they are not equal to C or D.
Example 2:

Input:
N = 1, A = 1, B = 1, C = 2, D = 3
Output: 
0
Explanation: 
The following are good integers: - { 1 }
Since sum of digits is 1 which is not equal to
C or D, therefore, answer is 0.
Your Task:
The task is to complete the function solve() which takes five integers N,A,B,C and D as input parameters and returns the number of best integers modulo 109+7.

Expected Time Complexity: O(NlogN)
Expected Space Complexity: O(N)

Constraints:
1 ≤ A, B, C, D ≤ 9
1 ≤ N ≤ 105
*/

long long mod = 1e9+7;
bool hogya=false;
long long factorial[100001];
long long mm[100001];
class Solution {
  public:
    void help(){
        factorial[0]=1;
        for(int i=1;i<=100000;i++){
            factorial[i] = (i*factorial[i-1])%mod;
        }
        mm[100000] = power(factorial[100000],mod-2);
        for(int i=99999;i>=0;i--){
            mm[i] = (mm[i+1]*(i+1))%mod;
        }
    }
    long long power(long long x,int y)
    {
        long long res = 1;
        x = x % mod;
        while (y > 0)
        {
            if (y & 1)
                res = (res * x) % mod;
     
            y = y >> 1;
            x = (x * x) % mod;
        }
        return res;
    }
    int help2(int n,int r){
     
        return (factorial[n] * mm[r] % mod
                * mm[n - r] % mod)
               % mod;
    }
    int bestNumbers(int N, int A, int B, int C, int D) {
        // code here
        bool hai=false;
        int i=0,sum;
        if(A==B){
            sum = N*A;
            while(sum!=0){
                int digit = sum%10;
                if(digit==C or digit==D){
                    hai=true;
                    break;
                }
                sum/=10;
            }
            if(hai)return 1;
            return 0;
        }
        if(hogya==false){
            help();
            hogya=true;
        }
        long long ans = 0;
        while(i<=N){
            sum = A*i+(B*(N-i));
            hai=false;
            while(sum!=0){
                int digit = sum%10;
                if(digit==C or digit==D){
                    hai=true;
                    break;
                }
                sum/=10;
            }
            if(hai==true){
                ans+=help2(N,i);
                ans%=mod;
            }
            i++;
        }
        return ans;
    }
};
