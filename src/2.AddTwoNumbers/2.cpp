/*
 * File: 2.cpp
 * File Created: 2021-01-04 20:29:22 -08:00
 * Author: Taowyoo (caoyxsh@outlook.com)
 * Brief: https://leetcode.com/problems/add-two-numbers/solution/
 * -----
 * Last Modified: 2021-01-04 21:06:15 -08:00
 * Modified By: Taowyoo (caoyxsh@outlook.com>)
 * -----
 * Copyright 2020 - 2021
 */


/**
 * @brief Add two number one by one
 * 
 * @param l1 First number in linked list format
 * @param l2 Second number in linked list format
 * @return ListNode* The head pointer of the result linked list
 */
ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode preHead(0), *p = &preHead;
    // use a variable to store carry
    int extra = 0;
    while (l1 || l2 || extra) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
        extra = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return preHead.next;
}