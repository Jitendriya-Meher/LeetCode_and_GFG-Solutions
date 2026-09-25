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

    class comp {
        public:
            bool operator()(ListNode *a, ListNode *b){
                return a->val > b->val;
            }
    };

    // KSortList function
    ListNode* KSortList(vector<ListNode*> list){
        // create a minheap to store the min node
        priority_queue<ListNode*, vector<ListNode*> , comp> minheap;

        // create a dummy head to store the ans 
        ListNode *head = new ListNode(-1);
        ListNode *temp = head;

        // push the first node of each list into the minheap
        for( int i=0; i<list.size(); i++ ){
            ListNode *top = list[i];
            // push into minheap if it is not NULL
            if( top != NULL){
                minheap.push(list[i]);
            }
        }

        // treverse the minheap until it is empty
        while( !minheap.empty() ){
            // get the min element element heap and delete the element
            ListNode *top = minheap.top();
            minheap.pop();
            
            int data = top->val;
            ListNode* last = top->next;

            // push the element to the result
            temp->next = top;
            temp = temp->next;

            // push the next element of the array to the minheap if exists
            if( last!= NULL){
                minheap.push(last);
            }
        }

        // retuen head->next , as head is a dumy node
        return head->next;

    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return KSortList(lists);
    }
};