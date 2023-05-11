/*
Given a string, S.The string can contain small case English letters or '?'. You can replace '?' with any small English letter. Now if it is possible to make the string S a palindrome after replacing all '?' then find the palindromic string with a minimum ascii sum of differences of adjacent characters. Otherwise, return -1.

Example 1:

Input: S = a???c??c????
Output: 4
Explanation:
We can see that we can make the string
palindrome. Now to get minimum ascii sum we should
replace all the '?' between 'a' and 'c' with
'b' and all the '?' between two 'c' with 'c'.
So after replacing all the '?' the string: 
abbbccccbbba.
The sum of differences of adjacent characters is 4.   
Example 2:

Input: S = a???c??c???c
Output: -1
Explanation:
It is not possible to make the string palindrome.
Your Task:
You don't need to read input or print anything. Your task is to complete the function minimumSum() which takes a string S input parameter and returns an integer denoting the sum of differences of adjacent characters. If it is not possible to make string palindrome, return -1. 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= |S| <= 105
*/


solution:

class Solution {
  public:
  
  //   first of all we check if the string is palindrome or not

 


  bool check(string & s)
  {
      int i=0,j=s.size()-1;
      
      int f=0;
      
      while(i<j)
      {
          if(s[i]==s[j])
          {
              i++;
              j--;
          }
          else if(s[i]=='?' && s[j]!='?')
          {
              i++;
              j--;
          }
          else if(s[i]!='?' && s[j]=='?')
          {
              i++;
              j--;
          }
          else
          {
              f=1;
              break;
          }
          
      }
      
      
      
      return f==1?false:true;
      
  }
  
    int minimumSum(string s) {
        
        
        bool p=check(s);
        
        
        int x1=0;
        
         int cnt=0;
        
        if(p==false)
        {
            x1=1;
        }
        else
        {
            

           // Now if the string is palindrome we will put the value of the same character at the other end except the '?'


            string s1="";
            
            int i=0,j=s.size()-1;
            
            while(i<j)
            {
                if(s[i]!='?' && s[j]!='?')
                {
                    i++;
                    j--;
                    
                }
                else if(s[i]!='?' && s[j]=='?')
                {
                    
                    char c1=s[i];
                    s[j]=c1;
                    
                    i++;
                    j--;
                }
                else if(s[i]=='?' && s[j]!='?')
                {
                    
                    char c2=s[j];
                    s[i]=c2;
                    i++;
                    j--;
                }
                else
                {
                    i++;
                    j--;
                }
            }
            
            
            // Now we will make a string of all the elements except the '?'
            
            for(int i=0;i<s.size();i++)
            {
                if(s[i]!='?')
                {
                    s1+=s[i];
                }
            }
            
           // After that we will find the sum of the difference of the  adjacent charcter  
           
            if(s1.size()==0)
            {
                cnt=0;
            }
            else
            {
                   
             for(int i=0;i<s1.size()-1;i++)
             {
              cnt+=abs(s1[i+1]-s1[i]);
                
             }
             
             
            }

        }

        return x1==1?-1:cnt;              
    }
};
