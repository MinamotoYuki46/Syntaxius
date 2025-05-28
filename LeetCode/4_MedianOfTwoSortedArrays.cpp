/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        if (m > n) return findMedianSortedArrays(nums2, nums1);

        int lo = 0, hi = m;
        while(lo <= hi){
            int mid1 = (lo + hi) / 2;
            int mid2 = (n + m + 1) / 2 - mid1;

            int l1 = (mid1 == 0 ? INT_MIN : nums1[mid1 - 1]);
            int r1 = (mid1 == m ? INT_MAX : nums1[mid1]);

            int l2 = (mid2 == 0 ? INT_MIN : nums2[mid2 - 1]);
            int r2 = (mid2 == n ? INT_MAX : nums2[mid2]);

            if (l1 <= r2 && l2 <= r1){
                if (!((m + n) & 1)) return (max(l1, l2) + min(r1, r2)) / 2.0;
                else                return max(l1, l2);
            }

            if (l1 > r2)    hi = mid1 -1;
            else            lo = mid1 + 1;
        }
        return 0;
    }
};
// @lc code=end

