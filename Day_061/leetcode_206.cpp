/**
 * ================================================================================
 * LeetCode 206: Reverse Linked List - Pointer Manipulation Masterclass
 * ================================================================================
 * 
 * ! Problem: Given the head of a singly linked list, reverse the list and return
 * ! the reversed list. The reversal should be done in-place by changing the node 
 * ! pointers without creating new nodes.
 * 
 * * Approach 1 (Iterative - Three Pointer Technique):
 * * 1. Initialize three pointers: prev (nullptr), cur (head), forward (nullptr)
 * * 2. Traverse the list while cur is not null:
 * *    - Save the next node: forward = cur->next
 * *    - Reverse the current link: cur->next = prev
 * *    - Move prev and cur one step forward
 * * 3. Return prev (new head of reversed list)
 * 
 * * Approach 2 (Recursive - Pass by Reference):
 * * 1. Use recursion with head passed by reference
 * * 2. Base case: if current is null, set head to prev
 * * 3. Recursively reverse remaining list after reversing current link
 * 
 * * Approach 3 (Recursive - Return New Head):
 * * 1. Base case: if head is null or single node, return head
 * * 2. Recursively get the new head from the rest of the list
 * * 3. Reverse the link between current and next node
 * * 4. Set current->next to null and return the new head
 * 
 * ? Time Complexity: O(n) - We visit each node exactly once
 * ? Space Complexity: 
 * ?   - Iterative: O(1) - Only three pointers used
 * ?   - Recursive: O(n) - Call stack depth equals number of nodes
 * 
 * TODO Key Insight: 
 * *    - The iterative approach is space-optimal and industry-preferred
 * *    - The recursive approaches demonstrate understanding of recursion patterns
 * *    - All three approaches change pointers in-place without new nodes
 * 
 * * Optimizations: 
 * *    - Iterative solution uses constant space
 * *    - Early termination for null or single-node lists
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
     * Approach 2: Recursive reversal using reference parameter
     * 
     * ! @param head Reference to head pointer (will be updated to new head)
     * ! @param cur Current node being processed
     * ! @param prev Previous node in the original list
     * 
     * ? How it works:
     * ?   - Recursively traverse to the end of the list
     * ?   - On the way back, reverse each link
     * ?   - Update head to the last node (new head)
     */
    void reverse(ListNode*& head, ListNode* cur, ListNode* prev) {
        // * Base case: reached end of original list
        if (cur == nullptr) {
            head = prev;  // ! prev is now the new head
            return;
        }
        
        // * Save next node before changing cur->next
        ListNode* next = cur->next;
        
        // * Reverse the link
        cur->next = prev;
        
        // * Move to next node
        prev = cur;
        
        // * Recursive call for remaining list
        reverse(head, next, prev);
    }

    /**
     * Approach 3: Pure recursive reversal returning new head
     * 
     * ! @param head Current head of the list to reverse
     * ! @return New head of the reversed list
     * 
     * ? How it works:
     * ?   - Recursively reverse the rest of the list
     * ?   - The deepest call returns the new head (original tail)
     * ?   - Each call reverses one link and passes the new head back up
     */
    ListNode* reverse1(ListNode* head) {
        // * Base case: empty list or single node
        if (head == nullptr || head->next == nullptr)
            return head;

        // * Recursively reverse the rest of the list
        // * ans will be the new head (original tail)
        ListNode* ans = reverse1(head->next);
        
        // * Reverse the link: make next node point back to current
        head->next->next = head;
        
        // * Set current node's next to null (will be updated by previous call)
        head->next = nullptr;
        
        // * Return the new head back up the call stack
        return ans;
    }

public:
    /**
     * Main function to reverse a singly linked list
     * 
     * ! @param head Head of the original linked list
     * ! @return Head of the reversed linked list
     * 
     * * Default implementation uses Approach 1 (Iterative)
     * * Uncomment other approaches to use them instead
     */
    ListNode* reverseList(ListNode* head) {
        // ! Edge case: empty list or single node
        if (head == nullptr || head->next == nullptr)
            return head;

        //// !! APPROACH 1: ITERATIVE THREE-POINTER TECHNIQUE (OPTIMAL)
        //// ? This is the most space-efficient solution
        //// * Time: O(n), Space: O(1)
        
        ListNode* prev = nullptr;    // * Previous node (starts as null)
        ListNode* cur = head;        // * Current node being processed
        ListNode* forward = nullptr; // * Next node (saved before reversing)

        // * Process each node in the original list
        while (cur != nullptr) {
            // * Step 1: Save next node before we lose reference to it
            forward = cur->next;
            
            // * Step 2: Reverse the link (point current back to previous)
            cur->next = prev;
            
            // * Step 3: Move prev and cur one step forward
            prev = cur;
            cur = forward;
        }
        
        // * prev is now pointing to the new head (original tail)
        return prev;
        

        //// !! APPROACH 2: RECURSIVE WITH REFERENCE PARAMETER
        //// ? Demonstrates recursion with pass-by-reference
        //// * Time: O(n), Space: O(n) due to call stack
        // ListNode* prev = nullptr;
        // ListNode* cur = head;
        // reverse(head, cur, prev);
        // return head;


        //// !! APPROACH 3: PURE RECURSIVE SOLUTION
        //// ? Elegant recursive approach returning new head
        //// * Time: O(n), Space: O(n) due to call stack
        // return reverse1(head);
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
    cout << "Original: ";
    printList(createList(arr, n));
    cout << "\nReversed: ";
    printList(result);
    cout << "\n========================================\n";
}

int main() {
    Solution solution;
    
    // * Test Case 1: Regular list
    {
        int arr[] = {1, 2, 3, 4, 5};
        int n = 5;
        ListNode* head = createList(arr, n);
        ListNode* result = solution.reverseList(head);
        printTestResult(1, arr, n, result);
        deleteList(result);
    }
    
    // * Test Case 2: Two nodes
    {
        int arr[] = {1, 2};
        int n = 2;
        ListNode* head = createList(arr, n);
        ListNode* result = solution.reverseList(head);
        printTestResult(2, arr, n, result);
        deleteList(result);
    }
    
    // * Test Case 3: Single node
    {
        int arr[] = {1};
        int n = 1;
        ListNode* head = createList(arr, n);
        ListNode* result = solution.reverseList(head);
        printTestResult(3, arr, n, result);
        deleteList(result);
    }
    
    // ! Test Case 4: Empty list
    {
        ListNode* head = nullptr;
        ListNode* result = solution.reverseList(head);
        cout << "\n========================================\n";
        cout << "Test Case 4 (Empty List):\n";
        cout << "Original: []";
        cout << "\nReversed: ";
        printList(result);
        cout << "\n========================================\n";
    }
    
    // * Test Case 5: Larger list
    {
        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int n = 10;
        ListNode* head = createList(arr, n);
        ListNode* result = solution.reverseList(head);
        printTestResult(5, arr, n, result);
        deleteList(result);
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The iterative approach is preferred in production code due to O(1) space
 * ! - Recursive approaches are elegant but use O(n) call stack space
 * * - All approaches modify pointers in-place without creating new nodes
 * ? - Understanding all three approaches demonstrates mastery of linked lists
 * * - The three-pointer technique is a fundamental pattern for list manipulation
 * ================================================================================
 */