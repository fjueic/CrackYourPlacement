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
    ListNode *merge(ListNode *a, ListNode *b) {
        ListNode *d = new ListNode(0);
        ListNode *t = d;
        while (a && b) {
            if (a->val < b->val) {
                d->next = a;
                a = a->next;
            } else {
                d->next = b;
                b = b->next;
            }
            d = d->next;
        }
        if (!a && !b)
            return t->next;
        if (a) {
            d->next = a;
        } else {
            d->next = b;
        }
        return t->next;
    }
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *s = head, *f = head;
        while (1) {
            f = f->next->next;
            if (!f || !f->next)
                break;
            s = s->next;
        }
        ListNode *h1 = head;
        ListNode *h2 = s->next;
        s->next = NULL;
        h1 = sortList(h1);
        h2 = sortList(h2);
        return merge(h1, h2);
    }
};
