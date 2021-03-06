# Linked List Cycle II (Medium)

## Description

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

**Note**: Do not modify the linked list.

**Example 1:**
```html
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, 
            where tail connects to the second node.
            
3 -> 2 -> 0 -> -4
     ^          |     
     |__________|
```
     
**Example 2:**
```html
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, 
            where tail connects to the first node.
                        
    1 -> 2
    ^    |     
    |____|
```

**Example 3:**
```html
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
```

**Follow up**:

Can you solve it without using extra space?

## Idea

Floyd's Tortoise and Hare

Phase 1: Detect Cycle (refer to problem 141).

Phase 2: Get the meeting point.

Phase 3: To find the entrance to the cycle, we have two pointers traverse at the same speed -- one from the front of the list, and the other from the point of intersection. (need math derivation)

