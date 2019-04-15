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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *res = nullptr;
        ListNode *cur = nullptr;
        while(true){
            int mink = -1;
            int m = INT_MAX;
            for(int i = 0;i < lists.size();i++){
                if(lists[i] == nullptr)
                    continue;
                if(m > lists[i]->val){
                    m = lists[i]->val;
                    mink = i;
                }
            }
            if(mink == -1)
                break;
            if(cur == nullptr){
                cur = new ListNode(m);
                res = cur;
            }
            else{
                cur->next = new ListNode(m);
                cur = cur->next;
            }
            lists[mink] = lists[mink]->next;
        }
        return res;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.first>b.first;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = nullptr;
        ListNode* cur = nullptr;
        priority_queue< pair<int,int>, vector<pair<int,int>>, cmp > pq;
        for(int i = 0;i < lists.size();i++){
            if(lists[i] == nullptr)
                continue;
            pq.push({lists[i]->val,i});
        }
        while(!pq.empty()){
            if(cur == nullptr){
                cur = new ListNode(pq.top().first);
                res = cur;
            }
            else{
                cur->next = new ListNode(pq.top().first);
                cur = cur->next;
            }
            int i = pq.top().second;
            lists[i] = lists[i]->next;
            pq.pop();
            if(lists[i] != nullptr)
                pq.push({lists[i]->val,i});
        }
        return res;
    }
};