// Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

// Example 1:

// Input: s = "abciiidef", k = 3
// Output: 3
// Explanation: The substring "iii" contains 3 vowel letters.
// Example 2:

// Input: s = "aeiou", k = 2
// Output: 2
// Explanation: Any substring of length 2 contains 2 vowels.
// Example 3:

// Input: s = "leetcode", k = 3
// Output: 2
// Explanation: "lee", "eet" and "ode" contain 2 vowels.
 

// Constraints:

// 1 <= s.length <= 105
// s consists of lowercase English letters.
// 1 <= k <= s.length

//My answer(Java)
class Solution {
    public int maxVowels(String s, int k) {
        int vowelCount=0;
        for(int i=0;i<k;i++){
            if(s.charAt(i)=='a'||s.charAt(i)=='e'||s.charAt(i)=='i'||s.charAt(i)=='o'||s.charAt(i)=='u')
            {
                vowelCount++;
            }
        }
        int maxCount=vowelCount;
        for(int i=0;i<s.length()-k;i++)
        {
            if(s.charAt(i+k)=='a'||s.charAt(i+k)=='e'||s.charAt(i+k)=='i'||s.charAt(i+k)=='o'||s.charAt(i+k)=='u')
            {
                vowelCount++;
            }
            if(s.charAt(i)=='a'||s.charAt(i)=='e'||s.charAt(i)=='i'||s.charAt(i)=='o'||s.charAt(i)=='u')
            {
                vowelCount--;
            }
            if(vowelCount>maxCount && vowelCount<=k)
            {
                maxCount=vowelCount;
            }
        }
        return maxCount;
    }
}

//The best answer I found in leetcode(CPP)
class Solution {
public:
    int maxVowels(string s, int k) {
    int vowels[26] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1};
    int max_vow = 0;
    for (int i=0,cur_vow=0;i<s.size();i++)
    {
        cur_vow+=vowels[s[i]-'a'];
        if (i>=k)
            cur_vow -= vowels[s[i-k]-'a'];
        max_vow=max(max_vow,cur_vow);
    }
    return max_vow;
    }
};
