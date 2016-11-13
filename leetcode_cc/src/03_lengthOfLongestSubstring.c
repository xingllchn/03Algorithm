/*
Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
#include <stdio.h>
#include <stdlib.h>
int lengthOfLongestSubstring1(char* s)
{
    int ans = 0;
    for(int i = 0;s[i] != '\0';i ++)
    {
        bool    hash[200] = {false};
        int count = 0;
        for(int j = i;s[j] != '\0';j ++)
        {
            if(!hash[s[j]])
            {
                hash[s[j]] = true;
                count ++;
            }
            else
                break;
        }
        ans = ans > count ? ans : count;
    }
    return  ans;
}
int lengthOfLongestSubstring2(char* s)
{
   int max_len = 0,start_max_len = 0,ans = 0;
    int index[130] = {0};
    bool    visited[130] = {false};

    for(int i = 0;s[i] != '\0';i ++)
        if(!visited[s[i]])
        {
            visited[s[i]] = true;
            index[s[i]] = i;
            max_len ++;
            ans = ans > max_len ? ans : max_len;
        }
        else
        {
            if(index[s[i]] < start_max_len)
            {
                index[s[i]] = i;
                max_len ++;

                ans = ans > max_len ? ans : max_len;
            }
            else
            {
                start_max_len = index[s[i]] + 1;
                max_len = i - start_max_len + 1;
                ans = ans > max_len ? ans : max_len;
                index[s[i]] = i;
            }
        }

    return  ans;
}