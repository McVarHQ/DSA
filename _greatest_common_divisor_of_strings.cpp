// For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).

// Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

 

// Example 1:

// Input: str1 = "ABCABC", str2 = "ABC"
// Output: "ABC"
// Example 2:

// Input: str1 = "ABABAB", str2 = "ABAB"
// Output: "AB"
// Example 3:

// Input: str1 = "LEET", str2 = "CODE"
// Output: ""
 

// Constraints:

// 1 <= str1.length, str2.length <= 1000
// str1 and str2 consist of English uppercase letters.

//My Answer(94/123 test cases passed)
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int num1=str1.length();
        int num2=str2.length();
        int min=num1;
        string s=str2;
        if(num2>num1)
        {
            s=str1;
            min=num2;
        }
        int gcd=0;
        int start=0;
        for(int i=0;i<min;i++)
        {
           if(start!=0) 
           {
               if(num1%start==0 && num2%start==0 && start>gcd)
               {
                   gcd=start;
               }
               
           }
           if(str1[start]==str2[start])
           {
               s+=str1[start];
               start++;
           }
           else
           {        
                break;
           }
          
        }
        cout<<gcd;
        return s.substr(0,gcd);
    }
};

//The best answer I found in Leetcode
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
      int num1=str1.length();
      int num2=str2.length();
      int min_number=num2;
      if(num1<num2)
      {
          min_number=num1;
      }
      if(str1+str2 != str2+str1)
      {
          return "";
      }
      else
      {
          return str1.substr(0,gcd(num1,num2));
      }
    }
    
};