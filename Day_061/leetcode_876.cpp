/**
 * ================================================================================
 * LeetCode 876: Middle of the Linked List - Two Pointer Technique
 * ================================================================================
 * 
 * ! Problem: Given the head of a singly linked list, return the middle node.
 * ! If there are two middle nodes (even length), return the second middle node.
 * ! Example: [1,2,3,4,5] → return node with value 3
 * !          [1,2,3,4,5,6] → return node with value 4
 * 
 * * Approach 1 (Length Calculation):
 * * 1. Calculate the length of the linked list
 * * 2. Find middle index: length / 2
 * * 3. Traverse to the middle node and return it
 * 
 * * Approach 2 (Two Pointer / Slow-Fast Technique - OPTIMAL):
 * * 1. Initialize slow pointer at head, fast pointer at head->next
 * * 2. Move slow by 1 step and fast by 2 steps in each iteration
 * * 3. When fast reaches end, slow will be at middle
 * * 4. Return slow pointer
 * 
 * ? Time Complexity: O(n) - Single pass through the list
 * ? Space Complexity: O(1) - Only two pointers used
 * 
 * TODO Key Insight: 
 * *    - The slow-fast pointer technique (tortoise and hare) is elegant
 * *    - When fast pointer moves twice as fast, slow reaches middle when fast reaches end
 * *    - This pattern appears in many linked list problems (cycle detection, etc.)
 * 
 * * Optimizations: 
 * *    - Two-pointer approach requires only one traversal
 * *    - No need to calculate length separately
 * *    - Space-optimal solution
 * ================================================================================
 */

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list node
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    /**
     * Helper function to calculate length of linked list
     * 
     * ! @param head Head of the linked list
     * ! @return Length of the list
     * 
     * ? Used in Approach 1 to determine middle position
     */
    int getLength(ListNode* head) {
        int len = 0;
        
        // * Count nodes by traversing the entire list
        while (head != nullptr) {
            len++;
            head = head->next;
        }
        
        return len;
    }

public:
    /**
     * Find the middle node of a singly linked list
     * 
     * ! @param head Head of the linked list
     * ! @return Pointer to the middle node (second middle if even length)
     * 
     * * Default implementation uses Approach 2 (Two-Pointer Technique)
     * * Uncomment Approach 1 to use length calculation method
     */
    ListNode* middleNode(ListNode* head) {
        // ! Edge case: single node list
        if (head->next == nullptr)
            return head;

        //// !! APPROACH 1: LENGTH CALCULATION METHOD
        //// ? First calculate length, then traverse to middle
        //// * Time: O(n), Space: O(1), but requires two passes
        
        // int len = getLength(head) / 2;  // * Middle index
        // int cnt = 0;
        // ListNode* temp = head;
        // 
        // // * Traverse to the middle node
        // while (cnt < len) {
        //     temp = temp->next;
        //     cnt++;
        // }
        // 
        // return temp;

        //// !! APPROACH 2: TWO-POINTER TECHNIQUE (OPTIMAL)
        //// ? Slow pointer moves 1 step, fast pointer moves 2 steps
        //// * Time: O(n), Space: O(1), single pass solution
        
        // ! Special case: two nodes
        if (head->next->next == nullptr)
            return head->next;

        ListNode* noob = head;        // * Slow pointer (moves 1 step)
        ListNode* pro = head->next;   // * Fast pointer (moves 2 steps)
        
        // * Continue until fast pointer reaches end
        while (pro != nullptr) {
            // * Move slow pointer one step
            noob = noob->next;
            
            // * Move fast pointer two steps
            pro = pro->next;
            if (pro != nullptr) {
                pro = pro->next;
            }
        }
        
        // * When fast reaches end, slow is at middle
        return noob;
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to create a linked list from array
 */
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    
    ListNode* head = new ListNode(arr[0]);
    ListNode* cur = head;
    
    for (int i = 1; i < n; i++) {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    
    return head;
}

/**
 * Helper function to print linked list
 */
void printList(ListNode* head) {
    if (head == nullptr) {
        cout << "[]";
        return;
    }
    
    cout << "[";
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << "]";
}

/**
 * Helper function to print list from a node onwards
 */
void printListFromNode(ListNode* head) {
    if (head == nullptr) {
        cout << "null";
        return;
    }
    
    cout << "[";
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << ",";
        head = head->next;
    }
    cout << "]";
}

/**
 * Helper function to delete linked list and free memory
 */
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

/**
 * Helper function to print test result
 */
void printTestResult(int testNum, int arr[], int n, ListNode* result) {
    cout << "\n========================================\n";
    cout << "Test Case " << testNum << ":\n";
    cout << "Input:  ";
    printList(createList(arr, n));
    cout << "\nMiddle: " << result->val << "\n";
    cout << "Output: ";
    printListFromNode(result);
    cout << "\n========================================\n";
}

int main() {
    Solution solution;
    
    // * Test Case 1: Odd length list
    {
        int arr[] = {1, 2, 3, 4, 5};
        int n = 5;
        ListNode* head = createList(arr, n);
        ListNode* result = solution.middleNode(head);
        printTestResult(1, arr, n, result);
        deleteList(head);
    }
    
    // * Test Case 2: Even length list (return second middle)
    {
        int arr[] = {1, 2, 3, 4, 5, 6};
        int n = 6;
        ListNode* head = createList(arr, n);
        ListNode* result = solution.middleNode(head);
        printTestResult(2, arr, n, result);
        deleteList(head);
    }
    
    // * Test Case 3: Single node
    {
        int arr[] = {1};
        int n = 1;
        ListNode* head = createList(arr, n);
        ListNode* result = solution.middleNode(head);
        printTestResult(3, arr, n, result);
        deleteList(head);
    }
    
    // * Test Case 4: Two nodes
    {
        int arr[] = {1, 2};
        int n = 2;
        ListNode* head = createList(arr, n);
        ListNode* result = solution.middleNode(head);
        printTestResult(4, arr, n, result);
        deleteList(head);
    }
    
    // * Test Case 5: Three nodes
    {
        int arr[] = {1, 2, 3};
        int n = 3;
        ListNode* head = createList(arr, n);
        ListNode* result = solution.middleNode(head);
        printTestResult(5, arr, n, result);
        deleteList(head);
    }
    
    // * Test Case 6: Larger even list
    {
        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int n = 10;
        ListNode* head = createList(arr, n);
        ListNode* result = solution.middleNode(head);
        printTestResult(6, arr, n, result);
        deleteList(head);
    }
    
    // * Test Case 7: Larger odd list
    {
        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int n = 9;
        ListNode* head = createList(arr, n);
        ListNode* result = solution.middleNode(head);
        printTestResult(7, arr, n, result);
        deleteList(head);
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The two-pointer technique is a fundamental pattern for linked list problems
 * ! - Fast pointer moves at 2x speed, so slow reaches middle when fast reaches end
 * * - For even-length lists, we return the second middle node as per problem requirement
 * ? - This technique also works for finding cycle in linked list (Floyd's algorithm)
 * * - The solution is optimal with single pass and constant space
 * ================================================================================
 */