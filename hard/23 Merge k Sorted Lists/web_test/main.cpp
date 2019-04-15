/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    // time complexity: O(size of lists[i] + size of lists[j])
    void merge(int i, int j, std::vector<ListNode *>& lists)
    {
        // assuming i < j; we want to make sure sorted list is placed at index i
        if (lists[i] && lists[j] && lists[j]->val < lists[i]->val) {
            auto tmp = lists[j];
            lists[j] = lists[i];
            lists[i] = tmp;
        }
        // sort lists at index i and j
        auto n1 = lists[i], n2 = lists[j];
        ListNode *p1 = nullptr;
        while (n2 && n1)
        {
            if (n1->val <= n2->val) {
                p1 = n1;
                n1 = n1->next;
            } else {
                lists[j] = lists[j]->next;
                n2->next = n1;
                if (p1) {
                    p1->next = n2;
                } else {
                    lists[i] = n2;
                }
                p1 = n2;
                n2 = lists[j];
            }
        }
        if (!n1) {
            if (p1) {
                p1->next = lists[j];
                lists[j] = nullptr;
            } else {
                lists[i] = lists[j];
                lists[j] = nullptr;
            }
        }
    }
public:
    // Time complexity: O((number of nodes in all the lists) * (log lists.size()))
    // SPace Comlexity: O(1)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int i = 0, j = 0;
        if (lists.size() == 0) {
            return nullptr;
        }
        // The real challenge was this logic. pow(2, x) ranges from [1, 2, 4..] and is essential to generate values of i and j
        // this for loop will be called log(lists.size()) times
        for (int x = 0; pow(2, x) < lists.size(); x++)
        {
            i = 0;
            j = i + pow(2, x);
            // we can potentially parallelize this while loop and then wait for all threads to join after the while loop
            // all iterations of while loop at this level will take O(n) time combined,
            // where n = total number of nodes in all the lists
            while (j < lists.size())
            {
                merge(i, j, lists);
                i = j + pow(2, x);
                j = i + pow(2, x);
            }
        }
        return lists[0];
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

class Solution {
public:
    static bool heapComp(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head(0);
        ListNode *curNode = &head;
        vector<ListNode*> v;   
        for(int i =0; i<lists.size(); i++){
            if(lists[i]) v.push_back(lists[i]);
        }
        make_heap(v.begin(), v.end(), heapComp); //vector -> heap data strcture

        while(v.size()>0){
            curNode->next=v.front();
            pop_heap(v.begin(), v.end(), heapComp); 
            v.pop_back(); 
            curNode = curNode->next;
            if(curNode->next) {
                v.push_back(curNode->next); 
                push_heap(v.begin(), v.end(), heapComp);
            }
        }
        return head.next;
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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> answer;
        if (lists.size()<1)
            return NULL;
        else if (lists.size() == 1)
            return lists[0];
        for (int i = 0; i < lists.size(); i++){
            ListNode* temp = lists[i];
            while(temp){
                answer.push_back(temp->val);
                temp = temp -> next;
            }
        }
        if(answer.size() == 0)
            return NULL;
        sort(answer.begin(), answer.end());
        ListNode*head;
        head = new ListNode(answer[0]);
        ListNode* temp = head;
        for (int i = 1; i < answer.size(); i++){
            ListNode *neww;
            neww = new ListNode((answer[i]));
            temp->next = neww;
            temp = temp->next;
        }
        return head;
    }
};