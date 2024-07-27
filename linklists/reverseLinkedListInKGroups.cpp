#include <cstddef>
using namespace std ;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL ){
            return head ;
        }
        int cnt = 0 ;
        ListNode * cur = head ;
        ListNode * prev = NULL ;
        ListNode * next = NULL ;
        while(cur != NULL && cnt < k ){
            next = cur -> next;
            cur -> next = prev ;
            prev = cur ;
            cur = next ;
            cnt++ ;
        }
        if(cnt < k ){
            cur  = prev ;
            next = NULL ;
            prev = NULL ;
            while(cur && cnt > 0){
                next = cur -> next ;
                cur -> next = prev ;
                prev = cur ;
                cur = next;
                cnt-- ;
            }
        }
        if(next){
            head -> next = reverseKGroup(next,k) ;
        }
        return prev ;

    }
};