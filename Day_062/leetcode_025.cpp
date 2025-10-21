/**
 * ================================================================================
 * LeetCode 25: Reverse Nodes in k-Group - Advanced Linked List Manipulation
 * ================================================================================
 * 
 * ! Problem: Given the head of a linked list, reverse the nodes of the list k at 
 * ! a time, and return the modified list. k is a positive integer and is less than 
 * ! or equal to the length of the linked list. If the number of nodes is not a 
 * ! multiple of k then left-out nodes, in the end, should remain as it is.
 * 
 * * Approach:
 * * 1. Count k nodes from current position to check if we have enough nodes
 * * 2. If we have k nodes, reverse this group using iterative reversal
 * * 3. Recursively process the remaining list after the reversed group
 * * 4. Connect the reversed group with the result from recursive call
 * * 5. If less than k nodes remain, leave them unchanged
 * 
 * ? Time Complexity: O(n) - We visit each node exactly once
 * ? Space Complexity: O(n/k) - Recursive stack depth for n/k groups
 * 
 * TODO Key Insight: 
 * *    - The challenge is reversing in groups while maintaining connections
 * *    - We need to count nodes first to avoid partial reversal of last group
 * *    - Recursion elegantly handles the "process remaining list" step
 * *    - The original head becomes the tail after reversal, perfect for linking
 * 
 * * Optimizations: 
 * *    - Single pass through the list
 * *    - In-place reversal without extra space for nodes
 * *    - Early termination when insufficient nodes remain
 * ================================================================================
 */

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    /**
     * Reverses nodes of a linked list k at a time
     * @param head Pointer to the head of the linked list
     * @param k The group size for reversal
     * @return Pointer to the new head of the modified list
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        //// * STEP 1: Count if we have k nodes available from current position
        ListNode* temp = head;
        int count = 0;
        
        while (temp != nullptr && count < k) {
            temp = temp->next;  // * Traverse to count nodes
            count++;
        }
        
        //// ! BASE CASE: If we don't have k nodes, return as is
        if (count < k) {
            return head;  // ? No reversal needed for incomplete group
        }
        
        //// * STEP 2: Reverse the current group of k nodes
        ListNode* prev = nullptr;  // * Will become the new head after reversal
        ListNode* cur = head;      // * Current node being processed
        ListNode* next = nullptr;  // * Temporary storage for next node
        int cnt = 0;
        
        // ? Classic iterative reversal pattern for k nodes
        while (cur != nullptr && cnt < k) {
            next = cur->next;      // * Save next node before breaking link
            cur->next = prev;      // ! Reverse the link direction
            prev = cur;            // * Move prev forward
            cur = next;            // * Move cur forward
            cnt++;
        }
        
        //// * STEP 3: Recursively process remaining list and connect
        // ? At this point:
        // ? - prev points to new head of reversed group
        // ? - head now points to last node of reversed group (will be tail)
        // ? - next points to first node of next group
        
        if (next != nullptr) {
            // * Recursively reverse remaining groups and link to current tail
            head->next = reverseKGroup(next, k);
        }
        
        //// * STEP 4: Return new head of this reversed group
        return prev;  // ! prev is the new head after reversal
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
    ListNode* current = head;
    
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    
    return head;
}

/**
 * Helper function to print linked list
 */
void printList(ListNode* head) {
    ListNode* current = head;
    cout << "[";
    
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next;
    }
    
    cout << "]";
}

/**
 * Helper function to compare two linked lists
 */
bool compareLists(ListNode* l1, ListNode* l2) {
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val != l2->val) return false;
        l1 = l1->next;
        l2 = l2->next;
    }
    return l1 == nullptr && l2 == nullptr;
}

/**
 * Helper function to delete linked list
 */
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

/**
 * Test case execution function
 */
void runTest(int testNum, int arr[], int n, int k, int expected[], int expSize) {
    cout << "\n========================================\n";
    cout << "Test Case " << testNum << ":\n";
    cout << "========================================\n";
    
    // * Create input list
    ListNode* head = createList(arr, n);
    cout << "Input:  ";
    printList(head);
    cout << "\nk = " << k << "\n";
    
    // * Execute solution
    Solution solution;
    ListNode* result = solution.reverseKGroup(head, k);
    
    // * Create expected list
    ListNode* expectedList = createList(expected, expSize);
    
    // * Print result
    cout << "Output: ";
    printList(result);
    cout << "\nExpected: ";
    printList(expectedList);
    
    // * Verify result
    bool passed = compareLists(result, expectedList);
    cout << "\nStatus: " << (passed ? "✅ PASS" : "❌ FAIL") << "\n";
    
    // * Cleanup
    deleteList(result);
    deleteList(expectedList);
}

int main() {
    // * Test Case 1: Basic reversal with k=2
    {
        int arr[] = {1, 2, 3, 4, 5};
        int expected[] = {2, 1, 4, 3, 5};
        runTest(1, arr, 5, 2, expected, 5);
    }
    
    // * Test Case 2: Full reversal with k=3
    {
        int arr[] = {1, 2, 3, 4, 5};
        int expected[] = {3, 2, 1, 4, 5};
        runTest(2, arr, 5, 3, expected, 5);
    }
    
    // * Test Case 3: k equals list length
    {
        int arr[] = {1, 2, 3, 4, 5};
        int expected[] = {5, 4, 3, 2, 1};
        runTest(3, arr, 5, 5, expected, 5);
    }
    
    // * Test Case 4: k = 1 (no change)
    {
        int arr[] = {1, 2, 3, 4, 5};
        int expected[] = {1, 2, 3, 4, 5};
        runTest(4, arr, 5, 1, expected, 5);
    }
    
    // ! Test Case 5: Single node
    {
        int arr[] = {1};
        int expected[] = {1};
        runTest(5, arr, 1, 1, expected, 1);
    }
    
    // * Test Case 6: Two nodes with k=2
    {
        int arr[] = {1, 2};
        int expected[] = {2, 1};
        runTest(6, arr, 2, 2, expected, 2);
    }
    
    // * Test Case 7: Longer list with k=4
    {
        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
        int expected[] = {4, 3, 2, 1, 8, 7, 6, 5};
        runTest(7, arr, 8, 4, expected, 8);
    }
    
    // * Test Case 8: k larger than remaining nodes
    {
        int arr[] = {1, 2, 3};
        int expected[] = {3, 2, 1};
        runTest(8, arr, 3, 3, expected, 3);
    }
    
    cout << "\n========================================\n";
    cout << "All tests completed!\n";
    cout << "========================================\n";
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - The solution uses recursion for elegant group processing
 * ! - We must count nodes before reversal to avoid partial reversal of last group
 * * - The iterative reversal within each group is the standard three-pointer technique
 * ? - After reversing, the original head becomes the tail, perfect for linking next group
 * * - Time: O(n) as each node is visited once; Space: O(n/k) for recursion stack
 * ! - Be careful with pointer manipulation to avoid losing references
 * ================================================================================
 */