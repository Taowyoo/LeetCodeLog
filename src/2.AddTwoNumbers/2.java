/*
 * @Author: Nick Cao
 * @Date: 2021-03-25 12:42:36
 * @LastEditTime: 2021-06-06 17:19:42
 * @LastEditors: Nick Cao
 * @Description: 
 * @FilePath: \LeetCodeLog\src\2.AddTwoNumbers\2.java
 */

public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    ListNode dummyHead = new ListNode(0);
    ListNode curr = dummyHead;
    int carry = 0;
    while (l1 != null || l2 != null || carry != 0) {
        int x = (l1 != null) ? l1.val : 0;
        int y = (l2 != null) ? l2.val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr.next = new ListNode(sum % 10);
        curr = curr.next;
        if (l1 != null) l1 = l1.next;
        if (l2 != null) l2 = l2.next;
    }
    
    return dummyHead.next;
}