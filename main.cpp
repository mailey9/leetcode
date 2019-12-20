#include <stdio.h>
#include <string>
#include <array>

#include "leetcode/longest_substring_without_repeating_characters.h"

int main()
{
    std::array<std::string, 6> test_cases =
    {
        "hello",
        "",
        "abcabcbb",
        "bbbbb",
        "pwwkew",
        "dvdf"
    };

    for (auto str : test_cases)
    {
        Solution s;
        int rv = s.lengthOfLongestSubstring(str);
        printf("%s[  %d  ]\n", str.c_str(), rv);
    }

    return 0;
}