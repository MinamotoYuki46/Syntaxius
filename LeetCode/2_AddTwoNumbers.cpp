// LeetCode Problem: Add Two Numbers
// Problem URL: https://leetcode.com/problems/add-two-numbers/
// Difficulty: Medium
// Solution Date: 26 October 2024

// Problem Statement:
// Given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, 
// and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Approach:
// We will traverse both linked lists, adding the corresponding digits along with the carry.
// If the sum of two digits is greater than 9, we will carry over the 1 to the next higher digit.
// We'll create a new linked list to store the result.

// Complexity Analysis:
// Time Complexity: O(max(m, n)), where m and n are the lengths of the two linked lists.
// This is because we need to traverse both lists entirely, which may require iterating through the longer list.
// Space Complexity: O(max(m, n)), for the new linked list that will store the result.
// In the worst case, the result can have the same number of nodes as the longer input list plus one more for the carry.

#include <bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;

        while(l1 || l2 || carry){
            int a = l1 ? l1 -> val : 0;
            int b = l2 ? l2 -> val : 0;
            int sum = carry + a + b;
            carry = sum / 10;

            curr -> next = new ListNode(sum % 10);
            curr = curr -> next;

            // traverse to next digit
            l1 = l1 ? l1 -> next : nullptr;
            l2 = l2 ? l2 -> next : nullptr;
        }

        ListNode* result = dummyHead -> next;
        delete dummyHead;
        return result;
    }
};

// Optional: Main function for quick testing
int main() {
    Solution sol;
    // Create first linked list: 2 -> 4 -> 3 (represents the number 342)
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Create second linked list: 5 -> 6 -> 4 (represents the number 465)
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* result = sol.addTwoNumbers(l1, l2);
    cout << "Result: ";
    while (result) {
        cout << result->val << " -> ";
        result = result->next;
    }
    cout << "nullptr" << endl;
    return 0;
}