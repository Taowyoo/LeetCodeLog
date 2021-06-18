/*
 * @Author: Nick Cao
 * @Date: 2021-03-25 12:42:05
 * @LastEditTime: 2021-06-18 12:16:59
 * @LastEditors: Nick Cao
 * @Description: https://leetcode.com/problems/merge-k-sorted-lists/
 * @FilePath: /LeetCodeLog/src/23.MergeKSortedLists/23.cpp
 */

// my solution
// continuously merge two list on head and end, until to 1;
// Time: O(kN), where k is the number of linked lists, N is the number of all
// nodes
// Space: O(1);
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() < 1)
      return nullptr;
    if (lists.size() == 1)
      return lists[0];
    int n = lists.size();
    while (n > 1) {
      int l = 0;
      int r = n - 1;
      while (l < r) {
        lists[l] = mergeTwoLists(lists[l], lists[r]);
        ++l;
        --r;
        --n;
      }
    }
    return lists[0];
  }

private:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode dummy(INT_MIN);
    ListNode *tail = &dummy;

    while (l1 && l2) {
      if (l1->val < l2->val) {
        tail->next = l1;
        l1 = l1->next;
      } else {
        tail->next = l2;
        l2 = l2->next;
      }
      tail = tail->next;
    }

    tail->next = l1 ? l1 : l2;
    return dummy.next;
  }
};

// Priority-Queue Solution
// Time: O(log(k)N), where k is the number of linked lists, N is the number of
// all nodes
// Space: O(k);
struct compare {
  bool operator()(const ListNode *l, const ListNode *r) {
    return l->val > r->val;
  }
};
ListNode *mergeKLists(vector<ListNode *> &lists) { // priority_queue
  priority_queue<ListNode *, vector<ListNode *>, compare> q;
  for (auto l : lists) {
    if (l)
      q.push(l);
  }
  if (q.empty())
    return NULL;

  ListNode *result = q.top();
  q.pop();
  if (result->next)
    q.push(result->next);
  ListNode *tail = result;
  while (!q.empty()) {
    tail->next = q.top();
    q.pop();
    tail = tail->next;
    if (tail->next)
      q.push(tail->next);
  }
  return result;
}

// Heap
static bool heapComp(ListNode *a, ListNode *b) { return a->val > b->val; }
ListNode *mergeKLists(vector<ListNode *> &lists) { // make_heap
  ListNode head(0);
  ListNode *curNode = &head;
  vector<ListNode *> v;
  for (int i = 0; i < lists.size(); i++) {
    if (lists[i])
      v.push_back(lists[i]);
  }
  make_heap(v.begin(), v.end(), heapComp); // vector -> heap data strcture

  while (v.size() > 0) {
    curNode->next = v.front();
    pop_heap(v.begin(), v.end(), heapComp);
    v.pop_back();
    curNode = curNode->next;
    if (curNode->next) {
      v.push_back(curNode->next);
      push_heap(v.begin(), v.end(), heapComp);
    }
  }
  return head.next;
}
