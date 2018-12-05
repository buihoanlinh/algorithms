#include <stdio.h>
#include <vector>
#include <map>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& findNums, std::vector<int>& nums) {
        std::map<int, int> indexMap;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            indexMap.insert({nums.at(i), i + 1});
        }
        
        std::vector<int> result;
        for (int i = 0; i < findNums.size(); ++i) {
            int index = indexMap.at(findNums.at(i));
            if (index < n) {
                for (int j = index; j < n; ++j) {
                    if (findNums.at(i) < nums.at(j)) {
                        result.push_back(nums.at(j));
                        break;
                    }
                    else {
                        if (j == n - 1) {
                            result.push_back(-1);
                        }
                    }
                }
            }
            else
            {
                result.push_back(-1);
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    int a[] = {1, 3, 2, 4};
    int b[] = {1, 4, 3};
    std::vector<int> nums(a, a + 4);
    std::vector<int> findNums(b, b + 3);
    std::vector<int> v = s.nextGreaterElement(findNums, nums);
    printf("[");
    for (int i = 0; i < v.size(); ++i) {
        printf("%d", v.at(i));
        if (i < v.size() - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}