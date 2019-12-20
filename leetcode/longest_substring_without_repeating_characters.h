/*
 * minorlife99@gmail.com
 * Dec-20th, 2019
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */

#pragma once

#include <string>
#include <list>
#include <algorithm>

class Solution {
public:

    /*
     * Sample Inputs & Outputs
     *      1. abcabcbb --> 3, abc
     *      2. bbbbb --> 1, b
     *      3. pwwkew --> 3, wke
     */

    std::list<char> cached;
    int longest;

    bool contains(char ch)
    {
        auto it = std::find(cached.begin(), cached.end(), ch);
        if (it != cached.end())
            return true;
        else
            return false;
    }

    void updateLongest(int candidate)
    {
        if (candidate > longest)
            longest = candidate;
    }

    void extractFromBeginTo(char ch)
    {
        //NOTE(minorlife99): 다음은 leetcode 의 테스트 컴파일러가 통과를 안시켜준다. end() 무효화 때문인가..?
        //                   gcc 8.1.0 에서는 무난하게 컴파일되고 돌아간다.

        //for (auto it  = cached.begin(); it != cached.end(); ++it)
        //{
        //    char met = cached.front();
        //    cached.pop_front();
        //    if (met == ch)
        //        break;
        //}

        while(true)
        {
            char met = cached.front();
            cached.pop_front();
            if (met == ch)
                break;
        }
    }

    int lengthOfLongestSubstring(std::string s) {
        longest = 0;
        cached.clear();

        for (auto it = s.cbegin(); it != s.cend(); ++it)
        {
            bool exists = contains(*it);

            if (exists == true)
            {
                updateLongest( static_cast<int>(cached.size()) );
                extractFromBeginTo( *it );
            }
            cached.push_back( *it );
        }

        updateLongest( static_cast<int>(cached.size()) );
        return longest;
    }
};
