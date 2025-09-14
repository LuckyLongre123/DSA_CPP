# Day 30: Stack Applications - String Processing

## 🎯 Learning Objectives

By the end of this day, you will master:
- **Stack Data Structure**: Understanding LIFO (Last In First Out) principle
- **String Stack Operations**: Using strings as stacks for character processing
- **Adjacent Duplicate Removal**: Pattern recognition and elimination techniques
- **Iterative String Processing**: Single-pass algorithms for string manipulation

---

## Problem 1: Remove All Adjacent Duplicates In String (LeetCode 1047)

### 📋 Problem Statement

**Difficulty**: Easy  
**Category**: String, Stack  
**Companies**: Amazon, Microsoft, Google, Facebook

You are given a string `s` consisting of lowercase English letters. A **duplicate removal** consists of choosing two **adjacent** and **equal** letters and removing them.

We repeatedly make duplicate removals on `s` until we no longer can.

**Task**: Return the final string after all such duplicate removals have been made.

### 🔍 Problem Analysis

**Key Insights**:
- We need to remove adjacent duplicate characters repeatedly
- This is similar to matching parentheses - perfect for stack approach
- Each removal might expose new adjacent duplicates
- We process characters one by one, maintaining a "clean" result

**Pattern Recognition**:
```
"abbaca" → "aaca" → "ca"
Step 1: Remove "bb" → "aaca"
Step 2: Remove "aa" → "ca"
Final: "ca"
```

### 📚 Examples with Detailed Analysis

#### Example 1: Multiple Removal Rounds
```
Input: s = "abbaca"
Output: "ca"

Step-by-step process:
Initial: "abbaca"
Process 'a': result = "a"
Process 'b': result = "ab"
Process 'b': duplicate found! result = "a" (remove last 'b')
Process 'a': duplicate found! result = "" (remove last 'a')
Process 'c': result = "c"
Process 'a': result = "ca"

Final result: "ca"
```

#### Example 2: Chain Reaction Removals
```
Input: s = "azxxzy"
Output: "ay"

Step-by-step process:
Initial: "azxxzy"
Process 'a': result = "a"
Process 'z': result = "az"
Process 'x': result = "azx"
Process 'x': duplicate found! result = "az" (remove last 'x')
Process 'z': duplicate found! result = "a" (remove last 'z')
Process 'y': result = "ay"

Final result: "ay"
```

#### Example 3: No Duplicates
```
Input: s = "abcd"
Output: "abcd"

Step-by-step process:
Process 'a': result = "a"
Process 'b': result = "ab"
Process 'c': result = "abc"
Process 'd': result = "abcd"

No adjacent duplicates found, original string returned.
```

### 🔄 Solution Approaches

#### Approach 1: Stack Using String ⭐

**💡 Core Idea**: Use a string as a stack to track characters and remove duplicates

**📊 Complexity Analysis**:
- **Time Complexity**: O(n) - single pass through string
- **Space Complexity**: O(n) - worst case when no duplicates exist

**🔍 Algorithm Steps**:
1. **Initialize**: Create empty result string (acts as stack)
2. **Iterate**: Process each character in input string
3. **Check**: If result not empty and top character equals current character
4. **Remove**: Pop from stack (remove last character from result)
5. **Add**: Otherwise, push to stack (add character to result)
6. **Return**: Final result string

```cpp
string removeDuplicates(string s) {
    string result;  // Acts as a stack
    
    for (char c : s) {
        // Check for adjacent duplicate
        if (!result.empty() && result.back() == c) {
            result.pop_back();  // Remove duplicate
        } else {
            result.push_back(c);  // Add character
        }
    }
    
    return result;
}
```

### 🔬 Algorithm Deep Dive

#### Stack Simulation for "abbaca":
```
Input: "abbaca"
Stack (result): []

Process 'a': Stack = ['a']
Process 'b': Stack = ['a', 'b']
Process 'b': Duplicate! Stack = ['a'] (removed 'b')
Process 'a': Duplicate! Stack = [] (removed 'a')
Process 'c': Stack = ['c']
Process 'a': Stack = ['c', 'a']

Final result: "ca"
```

#### Visual Representation:
```
Original: a b b a c a
          ↓ ↓ ↓ ↓ ↓ ↓
Stack:    a → ab → a → [] → c → ca
          
Step 1: Add 'a'
Step 2: Add 'b' 
Step 3: Remove 'b' (duplicate with previous 'b')
Step 4: Remove 'a' (duplicate with previous 'a')
Step 5: Add 'c'
Step 6: Add 'a'
```

#### Approach 2: Explicit Stack with std::stack

**💡 Core Idea**: Use standard stack container for clarity

```cpp
string removeDuplicates(string s) {
    stack<char> st;
    
    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop();
        } else {
            st.push(c);
        }
    }
    
    // Reconstruct string from stack
    string result;
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }
    
    return result;
}
```

**📊 Complexity**: O(n) time, O(n) space - but requires additional string reconstruction

### 📊 Performance Comparison

| Approach | Time Complexity | Space Complexity | Pros | Cons |
|----------|-----------------|------------------|------|------|
| String as Stack | O(n) | O(n) | Direct result, efficient | None |
| Explicit Stack | O(n) | O(n) | Clear stack operations | Extra reconstruction step |

### 🎯 Key Learning Points

#### 1. **Stack Applications in String Processing** 💡

**When to Use Stack for Strings**:
- Adjacent element matching/removal
- Parentheses/bracket matching
- Expression evaluation
- Undo operations

**Stack Operations Mapping**:
```cpp
// Traditional Stack    →    String as Stack
stack.push(item)       →    str.push_back(char)
stack.pop()            →    str.pop_back()
stack.top()            →    str.back()
stack.empty()          →    str.empty()
```

#### 2. **Pattern Recognition** 🔍

**Adjacent Duplicate Pattern**:
```
Input Pattern: ...XYY...  or  ...YYX...
Action: Remove YY
Result: ...X... or ...X...

This creates potential for new adjacent duplicates!
```

**Chain Reaction Example**:
```
"abccba" → "abba" → "aa" → ""
Each removal can expose new duplicates
```

### 🧪 Comprehensive Testing

#### Edge Cases:
```cpp
// Empty string
removeDuplicates("") → Expected: ""

// Single character
removeDuplicates("a") → Expected: "a"

// All duplicates
removeDuplicates("aabbcc") → Expected: ""

// No duplicates
removeDuplicates("abcdef") → Expected: "abcdef"

// Complex chain reaction
removeDuplicates("abccba") → Expected: ""

// Alternating pattern
removeDuplicates("ababab") → Expected: "ababab"
```

#### Test Case Walkthrough:
```cpp
Test: "abccba"
Step 1: "abccba" → process 'a' → result = "a"
Step 2: "abccba" → process 'b' → result = "ab"  
Step 3: "abccba" → process 'c' → result = "abc"
Step 4: "abccba" → process 'c' → result = "ab" (remove 'c')
Step 5: "abccba" → process 'b' → result = "a" (remove 'b')
Step 6: "abccba" → process 'a' → result = "" (remove 'a')

Final: ""
```

### 📏 Constraints and Implications

**Given Constraints:**
- `1 ≤ s.length ≤ 10^5`
- `s` consists of lowercase English letters only

**Constraint Analysis:**
```
Large Input: up to 10^5 characters
→ O(n) solution required for efficiency
→ O(n^2) approaches would be too slow

Lowercase Letters Only: 
→ Simple character comparison sufficient
→ No case sensitivity concerns
→ ASCII values 'a' to 'z' only

Memory Considerations:
→ Result string can be at most same length as input
→ Worst case: no duplicates, full string stored
→ Best case: all duplicates, empty result
```

---

## 📊 Progress Summary

| Problem | Difficulty | Status | Approach | Time Complexity | Space Complexity |
|---------|------------|--------|----------|-----------------|------------------|
| Remove Adjacent Duplicates | Easy | ✅ Solved | String Stack | O(n) | O(n) |

## 🎯 Key Learnings Achieved

### ✅ **Stack Data Structure Mastery**
- **LIFO Principle**: Last In, First Out operations
- **String as Stack**: Using string methods for stack operations
- **Efficient Operations**: O(1) push/pop with string back operations
- **Memory Efficiency**: Direct result construction without extra space

### ✅ **String Processing Patterns**
- **Adjacent Element Processing**: Comparing current with previous elements
- **Chain Reaction Handling**: How one removal can trigger more removals
- **Single Pass Algorithms**: Processing strings in one iteration
- **Pattern Recognition**: Identifying when stack-based solutions are optimal

## 🚀 Next Steps and Advanced Topics

### Immediate Practice:
- **LeetCode 20**: Valid Parentheses (classic stack problem)
- **LeetCode 1544**: Make The String Great (similar duplicate removal)
- **LeetCode 844**: Backspace String Compare (stack simulation)

### Advanced Concepts:
- **Balanced Parentheses**: Multiple bracket types
- **Expression Evaluation**: Infix to postfix conversion
- **Monotonic Stack**: Stack with ordering properties
- **Stack with Minimum**: Efficient min element tracking

## 💡 Master Problem-Solving Tips

### 🎯 **Stack Pattern Recognition**
```
When to use Stack:
✅ Adjacent element matching/comparison needed
✅ Need to "undo" or "backtrack" operations
✅ Processing nested structures
✅ Maintaining order while allowing removals

Stack vs Other Approaches:
- Stack: O(n) time, natural for adjacent operations
- Two Pointers: Complex for this problem due to removals
- Recursion: Possible but stack is more intuitive
```

### 🧠 **Optimization Strategies**
1. **Choose Right Container**: String vs std::stack based on needs
2. **Minimize Operations**: Direct result construction vs reconstruction
3. **Handle Edge Cases**: Empty strings, single characters
4. **Test Chain Reactions**: Verify multiple removal rounds work correctly

---

**Total Problems Solved**: 24/∞

*Master the stack, master string processing! 📚*
