class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head) {

        // Add code here
        Node *z = new Node(-1);
        Node *o = new Node(-1);
        Node *t = new Node(-1);
        Node *z1 = z;
        Node *o1 = o;
        Node *t1 = t;
        while (head) {
            if (head->data == 0) {
                z->next = head;
                z = z->next;
            } else if (head->data == 1) {
                o->next = head;
                o = o->next;
            } else {
                t->next = head;
                t = t->next;
            }
            head = head->next;
        }
        z->next = (o1->next) ? o1->next : t1->next;
        o->next = t1->next;
        t->next = NULL;
        return z1->next;
    }
};
