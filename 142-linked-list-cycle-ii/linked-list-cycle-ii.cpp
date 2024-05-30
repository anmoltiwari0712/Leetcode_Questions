/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp=head;
        unordered_map<ListNode*,int> nodemap;
        while(temp!=NULL){
            if(nodemap.count(temp)!=0){
                return temp;
            }
            nodemap[temp]=1;
            temp=temp->next;
        }
        return nullptr;
    }
};