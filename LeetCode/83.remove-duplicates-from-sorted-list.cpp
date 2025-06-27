/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 */

#include <bits/stdc++.h>

// @lc code=start

//  Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head -> next == NULL) return head;

        ListNode *curr = head;

        while(curr != NULL){
            if (curr -> next != NULL && curr -> val == curr -> next -> val){
                ListNode *next = curr -> next;
                curr -> next = curr -> next -> next;
                delete next;
            }
            else {
                curr = curr -> next;
            }
        }

        return head;
    }
};
// @lc code=end

