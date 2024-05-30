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
    bool hasCycle(ListNode *head) {
        ListNode* temp=head;
        unordered_map<ListNode*,int> Nodemap;

        while(temp!=NULL){
            if(Nodemap.find(temp)!=Nodemap.end()){
                return 1;
            }
            Nodemap[temp]=1;
            temp=temp->next;

        }
        return 0;

    }
};