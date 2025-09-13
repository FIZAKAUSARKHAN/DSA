/*  GFG Question: https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
    void solve(Node* root, int sum,int &maxSum, int len, int &maxLen)
    {
        if(root == NULL)
        {
            if(len>maxLen)
            {
                maxLen = len;
                maxSum = sum;
            }
            else if(len == maxLen)
            {
                maxSum = max(sum , maxSum);
            }
            return;
        }
        
        sum = sum + root->data;
        solve(root->left, sum, maxSum, len+1, maxLen);
        solve(root->right, sum, maxSum, len+1, maxLen);

    }
  public:
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        int len = 0;
        int maxLen = 0;
        
        int sum = 0;
        int maxSum = 0;
        solve(root, sum, maxSum, len, maxLen);
        return maxSum;
        
    }
};
