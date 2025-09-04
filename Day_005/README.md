# Day 5: Pointers & Dynamic Memory

## 🎯 Learning Objectives
- Understand what pointers are and why they're useful
- Learn pointer declaration, initialization, and dereferencing
- Master pointer arithmetic and array relationships
- Explore dynamic memory allocation with new/delete
- Practice safe pointer usage and avoid common pitfalls

## 📚 Topics Covered

### 1. Pointer Basics
- **What are Pointers**: Variables that store memory addresses
- **Declaration**: `int* ptr;` or `int *ptr;`
- **Address Operator**: `&variable` gets address of variable
- **Dereference Operator**: `*ptr` accesses value at address

### 2. Pointer Operations
- **Initialization**: `int* ptr = &variable;`
- **Null Pointers**: `int* ptr = nullptr;`
- **Pointer Arithmetic**: Moving through memory
- **Pointer Comparison**: Comparing addresses

### 3. Pointers and Arrays
- **Array Names**: Are pointers to first element
- **Pointer Notation**: `*(arr + i)` same as `arr[i]`
- **Traversing Arrays**: Using pointer arithmetic
- **Pointer vs Array**: Understanding the differences

### 4. Dynamic Memory Allocation
- **new Operator**: Allocate memory at runtime
- **delete Operator**: Free allocated memory
- **Memory Leaks**: What happens when you forget to delete
- **Best Practices**: Always pair new with delete

### 5. Pointers and Functions
- **Pass by Pointer**: Modifying variables through pointers
- **Returning Pointers**: Functions that return addresses
- **Pointer Parameters**: Efficient parameter passing
- **Double Pointers**: Pointers to pointers

## 💻 Practice Files
- `pointers_basic.cpp` - Pointer fundamentals and operations
- `pointer_arithmetic.cpp` - Pointer arithmetic and array relationships
- `dynamic_memory.cpp` - Dynamic allocation with new/delete
- `pointer_functions.cpp` - Pointers in function parameters and returns
- `pointer_practice.cpp` - Practical pointer applications

## 🔥 Mini Challenges
1. Swap two numbers using pointers
2. Find array elements using pointer arithmetic
3. Create dynamic arrays of user-specified size
4. Implement a simple dynamic string class
5. Build a basic linked list node structure

## 📖 Key Concepts to Remember
- Pointers store memory addresses, not values
- Always initialize pointers before use
- Use nullptr for null pointers (not NULL or 0)
- Every new must have a corresponding delete
- Dereferencing null pointers causes crashes

## ⚠️ Common Pitfalls
- **Dangling Pointers**: Pointing to freed memory
- **Memory Leaks**: Forgetting to delete allocated memory
- **Wild Pointers**: Uninitialized pointers
- **Double Deletion**: Calling delete twice on same memory

## 🚀 Next Day Preview
Tomorrow we'll learn about structures and vectors - organizing data efficiently!
