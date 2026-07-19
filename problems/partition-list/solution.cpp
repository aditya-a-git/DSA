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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) {
            return head;
        }

        ListNode *head1 = nullptr, *head2 = nullptr;
        ListNode *curr1 = nullptr, *curr2 = nullptr;
        ListNode* temp = head;

        while (temp) {
            if (temp->val < x) {
                if (!head1) {
                    head1 = temp;
                }

                if (!curr1) {
                    curr1 = temp;
                } else {
                    curr1->next = temp;
                    curr1 = temp;
                }
            } else {
                if (!head2) {
                    head2 = temp;
                }

                if (!curr2) {
                    curr2 = temp;
                } else {
                    curr2->next = temp;
                    curr2 = temp;
                }
            }

            temp = temp->next;
        }

        if (curr2) {
            curr2->next = nullptr;
        }

        if (curr1) {
            curr1->next = head2;
        }

        return head1 ? head1 : head2;
    }
};