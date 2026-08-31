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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critidx;
        ListNode* curr = head->next;
        int idx = 1;
        ListNode* prev = head;

        while (curr->next) {
            if (curr->val > prev->val && curr->val > curr->next->val) {
                critidx.push_back(idx);
            } else if (curr->val < prev->val && curr->val < curr->next->val) {
                critidx.push_back(idx);
            }

            prev = curr;
            curr = curr->next;
            idx++;
        }

        int n = critidx.size();
        if (n < 2) {
            return {-1, -1};
        }

        int minDist = INT_MAX;

        for (int i = 1; i < n; i++) {
            minDist = min(minDist, critidx[i] - critidx[i - 1]);
        }

        return {minDist, critidx[n - 1] - critidx[0]};
    }
};