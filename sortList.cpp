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
    ListNode *sortList(ListNode *head) {
        if(NULL == head || NULL == head->next)
            return head;
        std::multimap<int, ListNode*> m;
        ListNode* pCur = head;
        while(pCur)
        {
            m.insert(std::pair<int, ListNode*>(pCur->val, pCur));
            pCur = pCur->next;
        }
        std::multimap<int, ListNode*>::iterator it = m.begin();
        ListNode* pPre = it->second;
        ListNode* pHead = pPre;
        it++;
        while(it != m.end())
        {
            pPre->next = it->second;
            pPre = it->second;
            it++;
        }
        pPre->next = NULL;
        return pHead;
    }
};
