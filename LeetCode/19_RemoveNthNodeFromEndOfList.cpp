// LeetCode Problem: Remove Nth Node From the End Of List
// Problem URL: https://leetcode.com/problems/remove-nth-node-from-end-of-list
// Difficulty: Medium
// Solution Date: 5 November 2025

// Problem Statement:
// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Constraint
// 
// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz


// Approach:
// using two pointer, fast and slow. The fast one traverse first as much as n. if n is more than the sz, we delete the head. If not, then we traverse as long fast next is not null for both fast and slow. Then, tracking which node to be delete.

// Complexity Analysis:
// Time Complexity: O(N) - since all of it using single loop
// Space Complexity: O(1)) - just storing the pointer

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        ListNode *slow = head;

        for (int i = 0; i < n; ++i) {
            fast = fast -> next;
        }

        if (!fast) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }


        while (fast -> next) {
            fast = fast -> next;
            slow = slow -> next;
        }

        ListNode *dlt = slow -> next;
        slow -> next = slow -> next -> next;
        delete dlt;

        return head;
    }
};

// Optional: Main function for quick testing
// int main() {
//     Solution sol;
//     // Example test case
//     <ReturnType> result = sol.functionName(test parameters);
//     cout << "Result: " << result << endl;
//     return 0;
// }