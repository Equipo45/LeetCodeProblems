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
        ListNode* responseNode = new ListNode();
        ListNode* tail = responseNode;
        int carrete = 0;
        while (l1 != nullptr || l2!= nullptr || carrete != 0) {
            int numberSum = (l1 != nullptr ? l1->val : 0) + (l2 != nullptr ? l2->val : 0) + carrete;

            carrete = numberSum / 10;
            numberSum -= carrete * 10;

            ListNode* newNode = new ListNode(numberSum);
            tail->next = newNode;
            tail = tail->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
        
        return responseNode->next;
    }
};