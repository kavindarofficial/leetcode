/*
1980. Find Unique Binary String
Solved
Medium
Topics
Companies
Hint
Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.



Example 1:

Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.
Example 2:

Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.
Example 3:

Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.


Constraints:

n == nums.length
1 <= n <= 16
nums[i].length == n
nums[i] is either '0' or '1'.
All the strings of nums are unique.
*/

class Solution {
private:
    string result;
    bool buildNumber(unordered_set<string>& numbers, string& current, int& n) {
        if (current.size() == n) {
            if (numbers.count(current) == 0) {
                result = current;
                return true;
            }
            return false;
        }
        current.push_back('0');
        if (buildNumber(numbers, current, n)) return true;
        current.pop_back();

        //Try '1'
        current.push_back('1');
        if (buildNumber(numbers, current, n)) return true;
        current.pop_back();

        return false;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> numbers(nums.begin(), nums.end());

        string current = "";
        buildNumber(numbers, current, n);
        return result;
    }
};