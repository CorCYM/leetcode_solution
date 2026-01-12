#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Solution {
    public:

        void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {

            if ((m + n) > nums1.size() || n > nums2.size()) {
                throw std::invalid_argument("m or n value is out of range");
            }

            std::vector<int> mer;
            mer.reserve(m+n);

            for (size_t i = 0; i < m; ++i) {
                mer.push_back(nums1[i]);
            }
            for (size_t i = 0; i < n; ++i) {
                    mer.push_back(nums2[i]);
            }

            std::sort(mer.begin(), mer.end());
            
            for (int i =0; i < m+n; ++i){
                nums1[i] = mer[i];
            }
        }
};

void discard_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main(){
    int m, n;

    std::cout << "Enter the number of valid elements m of nums1: ";
    if (!(std::cin >> m)) {
        std::cerr << "m input is incorrect\n";
        return 1;
    }
    discard_line(); 

    std::cout << "Enter the number of valid elements n of nums2: ";
    if (!(std::cin >> n)) {
        std::cerr << "n input is incorrect\n";
        return 1;
    }
    discard_line(); 

    if (m < 0 || n <0) {
        std::cerr << "m and n cannot be negative.\n";
        return 1;
    }

    std::vector<int> nums1(m+n);
    std::vector<int> nums2(n);

    std::cout << "Enter the first " << m << " elements of nums1:\n";
    for (int i = 0; i < m; ++i) {
        if (!(std::cin >> nums1[i])){
            std::cerr << "An error occurred while entering nums1\n";
            return 1;
        }
    }
    discard_line();

    std::cout << "Enter the first " << n << " elements of nums2:\n";
    for (int i = 0; i < n; ++i) {
        if(!(std::cin >> nums2[i])){
            std::cerr << "An error occurred while entering nums2\n";
            return 1;
        }
    }
    discard_line();

    try{
        Solution sol;
        sol.merge(nums1, m, nums2, n);
    } catch(const std::exception& e) {
        std::cerr << "merge error: " << e.what() << '\n';
        return 1;
    }
    

    std::cout << "merge result: \n";
    for (int x : nums1) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    return 0;

}
