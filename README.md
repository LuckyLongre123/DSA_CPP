<div align="center">

<div style="display: flex; justify-content: center; align-items: center; gap: 20px; margin: 20px 0;">
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/vscode/vscode-original.svg" alt="VS Code" width="100"/>
  <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/cplusplus/cplusplus-original.svg" alt="C++" width="110"/>
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/git/git-original.svg" alt="Git" width="100"/>
  <img src="https://upload.wikimedia.org/wikipedia/commons/1/19/LeetCode_logo_black.png" alt="LeetCode" width="110"/>
  <img src="https://avatars.githubusercontent.com/u/583231?s=200&v=4" alt="Algorithms" width="100"/>
</div>

<h1>C++ FUNDAMENTALS TO DSA MASTERY</h1>

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![LeetCode](https://img.shields.io/badge/LeetCode-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)
![GeeksforGeeks](https://img.shields.io/badge/GeeksforGeeks-298D46?style=for-the-badge&logo=geeksforgeeks&logoColor=white)
![Data Structures](https://img.shields.io/badge/Data_Structures-FF6B6B?style=for-the-badge&logo=databricks&logoColor=white)
![Algorithms](https://img.shields.io/badge/Algorithms-4ECDC4?style=for-the-badge&logo=algorithm&logoColor=white)

</div>

## 🎯 Learning Journey Overview

A **beginner-friendly** learning path from C++ basics to programming confidence. This repository contains a simplified, step-by-step approach with easy examples, clear explanations, and fun projects designed specifically for programming newcomers.

### 📚 Learning Approach
- **Beginner First**: Start with absolute basics, no prior experience needed
- **Simple Examples**: Every concept uses easy-to-understand code
- **Gentle Progression**: Small steps, lots of practice, build confidence gradually  
- **Fun Projects**: Interactive games and practical applications

## 📊 My LeetCode Journey

![LeetCode Stats](https://leetcard.jacoblin.cool/Lucky_Longre_SD)

## 📚 Learning Path Structure

### Phase 1: Building C++ Foundation 🏗️
| Day | Topic | Status |
|-----|-------|--------|
| [001](Day_001) | C++ Basics & Simple Programs | ✅ |
| [002](Day_002) | Conditions & Simple Loops | ✅ |
| [003](Day_003) | Basic Functions & Simple Math | ✅ |
| [004](Day_004) | Arrays & Basic Strings | ✅ |
| [005](Day_005) | Simple Pointers & Memory Basics | ✅ |
| [006](Day_006) | Simple Structures & Basic Vectors | ✅ |
| [007](Day_007) | Basic File Operations | ✅ |
| [008](Day_008) | Simple Code Organization | ✅ |
| [009](Day_009) | Programming Practice & Exercises | ✅ |
| [010](Day_010) | Fun Programming Projects | ✅ |

### Phase 2: DSA Problem Solving 🚀

## 🎯 Problem Solving Journey

![Data Structures Classification](https://media.geeksforgeeks.org/wp-content/uploads/20220520182504/ClassificationofDataStructure-660x347.jpg)

### 🔥 Current Problem Count: **14 Solved**

---

## <------------ARRAY ----------->

**Day 11** [View Code](Day_011) - 25 Aug, 2025  
Array Problems

**Two Sum**
- **Definition**: Find two numbers in array that add up to target sum
- **Use Cases**: Hash map optimization, pair finding patterns
- **Key Concepts**:
  - Brute Force: O(n²) nested loops approach
  - Hash Map: O(n) single pass with complement lookup
  - Index management: Return indices, not values
  - Avoid duplicate usage: Start inner loop from i+1

**Power of Two**
- **Definition**: Check if number is power of 2 using bit manipulation
- **Use Cases**: Binary operations, mathematical checks
- **Key Concepts**:
  - Bit Manipulation: n & (n-1) == 0 for powers of 2
  - Edge Cases: Handle n ≤ 0
  - Mathematical Property: Powers of 2 have single bit set

---

## <------------DIGIT MANIPULATION ----------->

**Day 12** [View Code](Day_012) - 26 Aug, 2025  
Digit Manipulation Problems

**Find Smallest Index Where Index Equals Sum of Digits**
- **Definition**: Find index i where i equals sum of digits of nums[i]
- **Use Cases**: Mathematical properties, digit processing
- **Key Concepts**:
  - Digit Extraction: Use num % 10 and num / 10
  - Sum Calculation: Iterate through digits
  - Early Return: Return first matching index
  - Linear Search: O(n × d) where d is average digits

---

## <------------VOTING ALGORITHMS ----------->

**Day 13** [View Code](Day_013) - 27 Aug, 2025  
Boyer-Moore Voting Algorithm

**Majority Element**
- **Definition**: Find element appearing more than ⌊n/2⌋ times
- **Use Cases**: Majority detection, voting systems, data analysis
- **Key Concepts**:
  - Boyer-Moore Algorithm: O(n) time, O(1) space
  - Voting Logic: Increment for candidate, decrement for others
  - Mathematical Guarantee: Majority survives cancellation
  - Counter Reset: New candidate when counter reaches 0

---

## <------------INTEGER MANIPULATION ----------->

**Day 14** [View Code](Day_014) - 28 Aug, 2025  
Integer Manipulation Problems

**Reverse Integer**
- **Definition**: Reverse digits of 32-bit signed integer with overflow protection
- **Use Cases**: Number manipulation, overflow handling
- **Key Concepts**:
  - Digit Reversal: Extract with % 10, build with * 10
  - Overflow Detection: Check before multiplication to prevent overflow
  - Boundary Checks: INT_MIN/10 and INT_MAX/10 comparisons
  - Edge Cases: Negative numbers, trailing zeros, overflow returns 0

---

## <------------MATHEMATICAL ALGORITHMS ----------->

**Day 15** [View Code](Day_015) - 29 Aug, 2025  
Mathematical Algorithm Problems

**Sqrt(x)**
- **Definition**: Compute and return the square root of x (integer part only)
- **Use Cases**: Mathematical computations, binary search applications
- **Key Concepts**:
  - Binary Search: O(log x) time complexity on answer space
  - Integer Square Root: Return floor value, no decimals
  - Overflow Prevention: Use long for mid calculations
  - Search Space: Between 0 and x for optimization

---

## <------------TWO POINTERS ----------->

**Day 16** [View Code](Day_016) - 30 Aug, 2025  
Two Pointers Technique

**Remove Duplicates from Sorted Array**
- **Definition**: Remove duplicates in-place from sorted array, return new length
- **Use Cases**: Array modification, in-place algorithms, space optimization
- **Key Concepts**:
  - Two Pointers: Slow pointer for unique elements, fast pointer for traversal
  - In-place Modification: Modify array without extra space
  - Sorted Array Property: Duplicates are adjacent, simplifies detection
  - Return Length: First k elements contain unique values

---

## <------------SIEVE ALGORITHMS ----------->

**Day 17** [View Code](Day_017) - 31 Aug, 2025  
Mathematical Algorithms - Prime Numbers

**Count Primes**
- **Definition**: Count prime numbers less than non-negative number n
- **Use Cases**: Number theory, mathematical computations, optimization
- **Key Concepts**:
  - Sieve of Eratosthenes: O(n log log n) classical algorithm
  - Prime Marking: Mark multiples starting from i²
  - Space Optimization: Boolean array for memory efficiency
  - Mathematical Insight: Only check up to √n for completeness

---

## <------------BINARY SEARCH VARIATIONS ----------->

**Day 18** [View Code](Day_018) - 1 Sep, 2025  
Binary Search - Rotated Arrays

**Search in Rotated Sorted Array**
- **Definition**: Search target in rotated sorted array with O(log n) complexity
- **Use Cases**: Modified binary search, sorted array variations
- **Key Concepts**:
  - Rotation Detection: Identify which half is properly sorted
  - Conditional Logic: Check target range in sorted half
  - Binary Search Adaptation: Modify standard algorithm for rotation
  - Pivot Handling: Work with unknown rotation point

---

## <------------PEAK FINDING ----------->

**Day 19** [View Code](Day_019) - 2 Sep, 2025  
Binary Search - Mountain Arrays

**Peak Index in Mountain Array**
- **Definition**: Find peak element in mountain array using binary search
- **Use Cases**: Unimodal function optimization, peak detection
- **Key Concepts**:
  - Mountain Property: Strictly increasing then decreasing
  - Binary Search Logic: Compare mid with mid+1 for direction
  - Convergence: Eliminate half search space each iteration
  - Guaranteed Peak: Mountain structure ensures unique maximum

---

## <------------DYNAMIC PROGRAMMING ----------->

**Day 20** [View Code](Day_020) - 3 Sep, 2025  
Dynamic Programming - Sequences

**Fibonacci Number**
- **Definition**: Calculate nth Fibonacci number efficiently
- **Use Cases**: Sequence generation, DP optimization, mathematical sequences
- **Key Concepts**:
  - Iterative DP: O(n) time, O(1) space optimization
  - Space Reduction: Use variables instead of array
  - Recurrence Relation: F(n) = F(n-1) + F(n-2)
  - Base Cases: F(0) = 0, F(1) = 1

---

## <------------ADVANCED ALGORITHMS ----------->

**Day 21** [View Code](Day_021) - 4 Sep, 2025  
Power & Maximum Subarray Problems

**Pow(x, n)**
- **Definition**: Implement power function with binary exponentiation
- **Use Cases**: Mathematical computations, optimization algorithms
- **Key Concepts**:
  - Binary Exponentiation: O(log n) fast power calculation
  - Bit Manipulation: Use binary representation for efficiency
  - Negative Handling: Convert to reciprocal for negative exponents
  - Overflow Prevention: Handle INT_MIN edge case

**Maximum Subarray (Kadane's Algorithm)**
- **Definition**: Find contiguous subarray with maximum sum
- **Use Cases**: Array optimization, dynamic programming patterns
- **Key Concepts**:
  - Kadane's Algorithm: O(n) optimal solution
  - Reset Strategy: Start fresh when sum becomes negative
  - Local vs Global: Track current and maximum sums
  - Dynamic Programming: Optimal substructure property

---

## <------------SUBSEQUENCE ----------->

**Day 22** [View Code](Day_022) - 5 Sep, 2025  
Subsequence Problems

**Longest Common Subsequence**
- **Definition**: Find length of longest common subsequence between two sequences
- **Use Cases**: Sequence alignment, dynamic programming applications
- **Key Concepts**:
  - Dynamic Programming: O(m × n) time complexity
  - 2D Array: Store lengths of common subsequences
  - Recurrence Relation: LCS(i, j) = LCS(i-1, j-1) + 1 if match
  - Initialization: Handle edge cases for empty strings

---

## 🛠️ How to Use This Repository

### Prerequisites
- Basic computer literacy
- Any C++ compiler (GCC, Clang, MSVC)
- Text editor or IDE (VS Code, Code::Blocks, Dev-C++)
- Online compiler option: [Programiz C++ Compiler](https://www.programiz.com/cpp-programming/online-compiler)

### Daily Study Plan
1. **Read the README** in each day's folder
2. **Study the simple code examples** with beginner-friendly comments
3. **Run and experiment** with the provided programs
4. **Try the practice exercises** at your own pace
5. **Take notes** on key concepts and don't rush


## 🔧 Setup Instructions

### Local Development
```bash
# Clone the repository
git clone <repository-url>

# Navigate to any day's folder
cd Day_001

# Compile and run
g++ filename.cpp -o program
./program
```

### Online Compiler
Visit [Programiz C++ Compiler](https://www.programiz.com/cpp-programming/online-compiler) and copy-paste any `.cpp` file to run directly in browser.

## 🚀 Next Steps

### Current Focus
- Continue daily LeetCode problem solving
- Master fundamental data structures
- Build algorithmic thinking skills

### Future Learning Path
1. **Data Structures**: Linked Lists, Trees, Graphs, Hash Tables
2. **Algorithms**: Sorting, Searching, Dynamic Programming, Greedy
3. **Advanced Topics**: System Design, Competitive Programming

## 🎓 Journey Summary

This repository documents a complete learning path from C++ fundamentals to DSA mastery. The first 10 days established essential programming skills, while Day 011+ focuses on algorithmic problem-solving and data structure implementation.

**Key Principles:**
- **Practice consistently** - Daily coding builds muscle memory
- **Understand deeply** - Focus on concepts over speed
- **Apply knowledge** - Build projects and solve real problems

**Happy Coding!** 🚀

---

*Educational repository with thoroughly commented code examples for effective learning.*
