#pragma once

#include <vector>
/*
Given an integer x, return true if x is a
palindrome
, and false otherwise.



Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.


Constraints:

-231 <= x <= 231 - 1


Follow up: Could you solve it without converting the integer to a string?


*/


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || x == 10)
        {
            return false;
        }
        if (x == 0)
        {
            return true;
        }
        if (x >= 1 && x <= 9)
        {
            return true;
        }
        int tempNum = x;
        std::vector<int> VecInt{};

        for (int i = 1; tempNum >= 10; i * 10)
        {
            VecInt.push_back(tempNum % 10);
            tempNum /= 10 * i;
        }
        VecInt.push_back(tempNum);

        int VecHalfLenght = VecInt.size() / 2 - 1;
        for (int i = 0; i <= VecHalfLenght; i++)
        {
            if (VecInt[i] != VecInt[VecInt.size() - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
};