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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            temp = temp->next;
            n++;
        }
        if (k == 0 || n == 0) {
            return head;
        }
        k = k % n;
        if (k == 0) {
            return head;
        }
        // taking window
        ListNode* newHead = head;
        ListNode* newTail = head;
        ListNode* oldTail;
        temp = head;
        k--;
        while (k != 0 && temp->next != nullptr && temp != NULL) {
            k--;
            newTail = temp->next;
            temp = temp->next;
        }
        while (newTail->next != nullptr) {
            newTail = newTail->next;
            if (newTail->next == nullptr) {
                newTail->next = head;
                temp = newHead;
                head = newHead->next;
                temp->next = nullptr;
                break;
            }
            newHead = newHead->next;
        }
        return head;
    }
};