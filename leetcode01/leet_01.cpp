#include <iostream>
#include <vector>

class Solution {
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target) {
            std::vector<int> ans;
            for (size_t i =0; i < nums.size(); ++i) {
                for (size_t j = i + 1; j < nums.size(); ++j) {
                    int res = nums[i] + nums[j];
                    if (res == target) {
                        ans.push_back(i);
                        ans.push_back(j);
                    }
                }
            }
            return ans;

        }
};

int main() {
    std::vector<int> nums = {2,7,11,15};
    int target = 9;

    Solution sol;
    std::vector<int> result = sol.twoSum(nums, target);

    for (int idx : result) {
        std::cout << idx << " ";
    }

    return 0;
}