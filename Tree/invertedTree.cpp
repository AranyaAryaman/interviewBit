/*
Problem Description

Given a binary tree A, invert the binary tree and return it. 

 Inverting refers to making left child as the right child and vice versa.



Problem Constraints
1 <= size of tree <= 100000



Input Format
First and only argument is the head of the tree A.



Output Format
Return the head of the inverted tree.



Example Input
Input 1:

 
     1
   /   \
  2     3
Input 2:

 
     1
   /   \
  2     3
 / \   / \
4   5 6   7


Example Output
Output 1:

 
     1
   /   \
  3     2
Output 2:

 
     1
   /   \
  3     2
 / \   / \
7   6 5   4


Example Explanation
Explanation 1:

Tree has been inverted.
Explanation 2:

Tree has been inverted.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void makeTreeInverted(TreeNode* head){
    if(head==NULL || (head->left==NULL && head->right==NULL))
        return;
    TreeNode* temp1 = head->left;
    head->left = head->right;
    head->right = temp1;
    makeTreeInverted(head->left);
    makeTreeInverted(head->right);
}
 
TreeNode* Solution::invertTree(TreeNode* A) {
    TreeNode* head = A;
    makeTreeInverted(head);
    return A; 
}
