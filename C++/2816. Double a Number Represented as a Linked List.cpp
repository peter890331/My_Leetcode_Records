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
    // To compute twice the value of each node's value and propagate carry
    int twiceOfVal(ListNode* head){
        // Base case: if head is null, return 0
        if (!head) return 0;
        
        // Double the value of current node and add the result of next nodes
        // 對於當前節點，將其值乘以 2，個位數於更新當前節點的值，十位數返回做遞迴。（可以從遞迴的最後，也就是最後一位數開始理解。）
        int doubledValue = head->val * 2 + twiceOfVal(head->next);
        
        // Update current node's value with the units digit of the result
        // 更新當前節點的值為結果的個位數。
        head->val = doubledValue % 10;
        
        // Return the carry (tens digit of the result)
        // 返回結果的十位數，用作進位。
        return doubledValue / 10;
    }
    
    ListNode* doubleIt(ListNode* head) {
        int carry = twiceOfVal(head);
        
        // If there's a carry, insert a new node at the beginning with the carry value
        // 如果有進位，則在鏈表的開頭插入一個新的節點，節點值為進位值。
        if (carry) 
            head = new ListNode(carry, head);
        
        return head;
    }
};

// Mohammed_Raziullah_Ansari's solution.

// [1, 8, 9] =>

// [1, 8, X] =>
//     1  8

// [1, X, 8] =>
//  1  6+1

// [X, 7, 8] =>
//  2+1

// [3, 7, 8] #