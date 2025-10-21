/**
 * ================================================================================
 * LeetCode 141: Linked List Cycle - Two Pointer Technique
 * ================================================================================
 * 
 * ! Problem: Given the head of a linked list, determine if the linked list has 
 * ! a cycle in it. A cycle exists if there is some node in the list that can be 
 * ! reached again by continuously following the next pointer.
 * 
 * * Approach:
 * * 1. Initialize two pointers: slow and fast, both starting at head
 * * 2. Move slow pointer one step at a time
 * * 3. Move fast pointer two steps at a time
 * * 4. If fast and slow meet, a cycle exists
 * * 5. If fast reaches NULL, no cycle exists
 * 
 * ? Time Complexity: O(n) - We visit each node at most twice
 * ? Space Complexity: O(1) - Only two pointers used, no extra space
 * 
 * TODO Key Insight: 
 * *    - Floyd's Cycle Detection Algorithm (Tortoise and Hare)
 * *    - If there's a cycle, the fast pointer will eventually catch the slow pointer
 * *    - The fast pointer moves twice as fast, closing the gap in a cycle
 * *    - No cycle means fast pointer reaches the end (NULL)
 * 
 * * Optimizations: 
 * *    - Single pass through the list
 * *    - No additional data structures needed
 * *    - Early termination when cycle detected
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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * Detects if a linked list contains a cycle using Floyd's algorithm
     * @param head The head node of the linked list
     * @return true if cycle exists, false otherwise
     */
    bool hasCycle(ListNode* head) {
        // ! Edge Case: Empty list or single node without cycle
        if (!head || !head->next)
            return false;

        // * Initialize two pointers at the head
        ListNode* slow = head;  // * Tortoise: moves 1 step at a time
        ListNode* fast = head;  // * Hare: moves 2 steps at a time

        // * Traverse the list with both pointers
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;        // * Move slow pointer by 1 step
            fast = fast->next->next;  // * Move fast pointer by 2 steps

            // ! Cycle Detection: If pointers meet, cycle exists
            if (slow == fast)
                return true;  // * Cycle found!
        }

        // ? Fast pointer reached the end (NULL), no cycle exists
        return false;
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to create a linked list with a cycle
 * @param values Array of node values
 * @param size Size of the array
 * @param pos Position where cycle connects (-1 for no cycle)
 * @return Head of the created linked list
 */
ListNode* createCycleList(int values[], int size, int pos) {
    if (size == 0) return nullptr;
    
    // * Create nodes
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    ListNode* cycleNode = nullptr;
    
    // * Track the node where cycle should connect
    if (pos == 0) cycleNode = head;
    
    // * Build the list
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
        
        // * Mark the cycle connection point
        if (i == pos) cycleNode = current;
    }
    
    // * Create cycle if pos is valid
    if (pos != -1 && cycleNode != nullptr) {
        current->next = cycleNode;  // ! Create the cycle
    }
    
    return head;
}

/**
 * Helper function to print test result
 */
void printTestResult(int testNum, bool result, bool expected, const string& description) {
    cout << "\n* Test Case " << testNum << ": " << description << "\n";
    cout << "   Result:   " << (result ? "true (cycle detected)" : "false (no cycle)") << "\n";
    cout << "   Expected: " << (expected ? "true" : "false") << "\n";
    cout << "   Status:   " << (result == expected ? "PASS ✓" : "FAIL ✗") << "\n";
}

/**
 * Helper function to free memory (for non-cycle lists only)
 */
void freeList(ListNode* head, bool hasCycle) {
    if (hasCycle) return;  // * Can't safely free a cyclic list in this simple helper
    
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution solution;
    
    // * Test Case 1: List with cycle at position 1
    {
        int values[] = {3, 2, 0, -4};
        ListNode* head = createCycleList(values, 4, 1);
        bool result = solution.hasCycle(head);
        printTestResult(1, result, true, "Cycle at position 1: [3,2,0,-4], tail connects to node index 1");
        // Note: Memory cleanup skipped for cyclic lists
    }
    
    // * Test Case 2: List with cycle at position 0 (tail connects to head)
    {
        int values[] = {1, 2};
        ListNode* head = createCycleList(values, 2, 0);
        bool result = solution.hasCycle(head);
        printTestResult(2, result, true, "Cycle at position 0: [1,2], tail connects to head");
    }
    
    // * Test Case 3: Single node, no cycle
    {
        int values[] = {1};
        ListNode* head = createCycleList(values, 1, -1);
        bool result = solution.hasCycle(head);
        printTestResult(3, result, false, "Single node: [1], no cycle");
        freeList(head, false);
    }
    
    // * Test Case 4: Empty list
    {
        ListNode* head = nullptr;
        bool result = solution.hasCycle(head);
        printTestResult(4, result, false, "Empty list: []");
    }
    
    // ! Test Case 5: Two nodes, no cycle
    {
        int values[] = {1, 2};
        ListNode* head = createCycleList(values, 2, -1);
        bool result = solution.hasCycle(head);
        printTestResult(5, result, false, "Two nodes: [1,2], no cycle");
        freeList(head, false);
    }
    
    // * Test Case 6: Multiple nodes, no cycle
    {
        int values[] = {1, 2, 3, 4, 5};
        ListNode* head = createCycleList(values, 5, -1);
        bool result = solution.hasCycle(head);
        printTestResult(6, result, false, "Five nodes: [1,2,3,4,5], no cycle");
        freeList(head, false);
    }
    
    // * Test Case 7: Large cycle
    {
        int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        ListNode* head = createCycleList(values, 10, 5);
        bool result = solution.hasCycle(head);
        printTestResult(7, result, true, "Large list: 10 nodes, cycle at position 5");
    }
    
    // * Test Case 8: Self-loop (single node cycle)
    {
        int values[] = {1};
        ListNode* head = createCycleList(values, 1, 0);
        bool result = solution.hasCycle(head);
        printTestResult(8, result, true, "Self-loop: [1], node points to itself");
    }
    
    cout << "\n" << string(60, '=') << "\n";
    cout << "* All test cases completed!\n";
    cout << string(60, '=') << "\n";
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - Floyd's Cycle Detection is also known as the "Tortoise and Hare" algorithm
 * ! - The algorithm is guaranteed to detect a cycle if one exists
 * * - In a cycle, the fast pointer will always catch up to the slow pointer
 * ? - Why does fast pointer catch slow? Because it closes the gap by 1 each iteration
 * * - This is a classic example of the two-pointer technique
 * ! - Alternative approach: Use a hash set (O(n) space) to track visited nodes
 * * - Floyd's algorithm is optimal: O(n) time and O(1) space
 * ================================================================================
 */