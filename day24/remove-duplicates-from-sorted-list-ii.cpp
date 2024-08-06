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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *d = new ListNode(0, head);
        ListNode *ans = d;
        while (d->next) {
            if (!d->next->next)
                break;
            if (d->next->val == d->next->next->val) {
                int v = d->next->val;
                ListNode *t = d->next;
                while (t && t->val == v) {
                    d->next = d->next->next;
                    delete t;
                    t = d->next;
                }
            } else {
                d = d->next;
            }
        }
        return ans->next;
    }
};
