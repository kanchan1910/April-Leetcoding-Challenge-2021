/*
Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.

 

Example 1:

Input: n = 27
Output: true
Example 2:

Input: n = 0
Output: false
Example 3:

Input: n = 9
Output: true
Example 4:

Input: n = 45
Output: false
 

Constraints:

-231 <= n <= 231 - 1
 

Follow up: Could you solve it without loops/recursion?

*/
class Solution {
public:
    bool isPowerOfThree(int n) 
    {
        if(n == 1)
        {
            return true;
        }
        if(n < 1)
        {
            return false;
        }
        while(n % 3 == 0)
        {
             n /= 3;
        }
        return n == 1;
    }
};
/*
Time complexity : In our case that is O(\log_3n).The number of divisions is given by that logarithm.

Space complexity : O(1)
*/

class Solution {
public:
    bool isPowerOfThree(int n) 
    {
       return n > 0 && 1162261467 % n == 0;
    }
};
/*
Knowing the limitation of n, we can now deduce that the maximum value of n that is also a power of three is 1162261467. We calculate this as:

3^{\lfloor{}\log_3{MaxInt}\rfloor{}} = 3^{\lfloor{}19.56\rfloor{}} = 3^{19} = 11622614673 
⌊log 
3
​	
 MaxInt⌋
 =3 
⌊19.56⌋
 =3 
19
 =1162261467

Therefore, the possible values of n where we should return true are 3^03 
0
 , 3^13 
1
  ... 3^{19}3 
19
 . Since 3 is a prime number, the only divisors of 3^{19}3 
19
  are 3^03 
0
 , 3^13 
1
  ... 3^{19}3 
19
 , therefore all we need to do is divide 3^{19}3 
19
  by n. A remainder of 0 means n is a divisor of 3^{19}3 
19
  and therefore a power of three.
Time complexity : O(1)O(1). We are only doing one operation.

Space complexity : O(1)O(1). We are not using any additional memory.
*/
// TIP: this method can be applied to any prime number.
  
