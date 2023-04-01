/*You are given an integer N. Consider an array arr having N elements where arr[i] = 2*i+1. (The array is 0-indexed)

You are allowed to perform the given operation on the array any number of times:

1) Select two indices i and j and increase arr[i] by 1 and decrease arr[j] by 1.

Your task is to find the minimum number of such operations required to make all the elements of the array equal.

Example 1:

Input:
N = 3
Output:
2
Explanation:
Initially the array is {1, 3, 5}. If we perform
the operation once on the indices 0 and 2, the 
resulting array will be {2, 3, 4}. If we again 
perform the operation once on the indices 0
and 2, the resulting array will be {3, 3, 3}.
Hence, the minimum operations required is 2
in this case. 
Example 2:

Input: 
N = 2
Output:
1
Explanation: 
The array initially is {1, 3}. After performing 
an operation the array will be {2, 2}. Hence,
the answer is 1 in this case.
Your Task:
Complete the function minOperations() which takes the integer N as the input parameter, and returns the minimum operations required to make all the array elements equal.

Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)
*/

approach -------------->>
  
FOR N =2 WE NEED MAKE ALL ELEMENTS EQUAL TO 2

FOR N=3 WE NEED TO MAKE ALL ELEMENTS EQUAL TO 3

.

.

.

FOR N=6 WE NEED TO MAKE ALL ELEMENTS EQUAL TO 6

SO THE AFTER APPLYING ALL THE OPERATIONS WE GET ALL  ELEMENTS IN ARRAY WILL BE EQUAL TO N ITSELF.

THAT IS FOR N=6 ARRAY ={6,6,6,6,6,6};

FOR N=7 ARRAY={7,7,7,7,7,7};

NOW CONSIDER FOR N=6

ORIGINAL ARRAY = {1,3,5,7,9,11};

SO FROM THE ABOVE OBSERVATION WE NEED TO MAKE ALL ELEMENTS EQUAL TO " 6 ".

SO FOR CHANGING 1 TO 6 , IT TAKES | 1-6 | OPERATIONS .

FOR CHANGING 3 TO 6 , IT TAKES |3-6| OPERATIONS .

AND SOON .

-->

DERIVATION OF FORMULA :

SO FOR N=6 , TO MAKE ALL ARRAY ELEMENTS EQUAL TO 6 , WE SHOULD CALCULATE THE VALUE OF 

 

" ( | 1-6 | + | 3- 6 | + | 5 - 6 | + | 7-6 | + | 9 -  6| + | 11 - 6| ) "

WHICH IS EQUAL TO

 SUM OF N ODD NUMBERS - SQUARE OF N "

BUT AS MENTIONED IN THE QUESTION 

WE CAN INCREMENT AND DECREMENT IN ONE SINGLE STEP 

THE FORMULA BECOMES 

  (  SUM OF N ODD NUMBERS - ( (SQUARE OF N)/2) )/2 

WHICH IS EQUAL TO  (N^2 - ((N^2)/2))/2 

WHICH CAN BE FURTHER SIMPLIFIED TO

( 2*(N^2)-(N^2))/4 ==== (N^2)/4

SO THE FINAL FORMULA IS :

     ( N^2) /4 

C++ CODE :

class Solution {
  public:
    long long int minOperations(int N) {
        // Code here
        return ((long long)N*N)/4;
    }
};
