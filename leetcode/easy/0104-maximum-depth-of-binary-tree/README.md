# Maximum Depth of Binary Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the `root` of a binary tree, return  *its maximum depth*.

A binary tree's  **maximum depth**  is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

 **Example 1:** 

```
Input: root = [3,9,20,null,null,15,7]
Output: 3

```

 **Example 2:** 

```
Input: root = [1,null,2]
Output: 2

```

 

 **Constraints:** 

- The number of nodes in the tree is in the range [0, 104].
- -100 <= Node.val <= 100

## Solution

**Language:** C  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 14.4 MB (beats 36.71%)  
**Submitted:** 2026-10-06T16:01:24.551Z  

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
   if(root ==NULL)
   return 0;
   int leftDepth = maxDepth(root->left);
   int rightDepth = maxDepth(root->right);
   if(leftDepth > rightDepth)
    return leftDepth+1;
    else
    return rightDepth+1;
}
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-depth-of-binary-tree/)