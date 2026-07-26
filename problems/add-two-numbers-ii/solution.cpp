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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1, st2;

        while (l1 != nullptr) {
            st1.push(l1->val);
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            st2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* head = nullptr;
        int carry = 0;

        while (!st1.empty() || !st2.empty() || carry != 0) {
            int num1 = !st1.empty() ? st1.top() : 0;
            int num2 = !st2.empty() ? st2.top() : 0;

            int sum = num1 + num2 + carry;
            carry = sum / 10;
            sum = sum % 10;

            ListNode* newnode = new ListNode(sum);
            newnode->next = head;
            head = newnode;

            if (!st1.empty()) {
                st1.pop();
            }

            if (!st2.empty()) {
                st2.pop();
            }
        }

        return head;
    }
};