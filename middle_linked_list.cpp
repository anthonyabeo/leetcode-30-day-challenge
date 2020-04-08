/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * The tortoise and hare (slow and fast pointer) technique works because starting from
 * the head node, if the hare runs twice as fast as the tortoise, then when the hare gets 
 * to the end of the list, the tortoise would have reached the middle.
*/
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* tortoise = head;
        ListNode* hare = head;
        
        while(hare != NULL && hare->next != NULL) {
            tortoise = tortoise->next;
            hare = hare->next->next;
        }
        
        return tortoise;
    }
};