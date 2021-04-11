class Solution {
public:
    int deepestLeavesSum(TreeNode* root) 
    { 
        queue<TreeNode*>q;
        q.push(root);
        int sum;
        while(!q.empty())
        {
            sum = 0;
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                TreeNode* front = q.front();
                q.pop();
                sum += front->val;
                if(front->left != NULL)
                {
                    q.push(front->left);
                }
                if(front->right != NULL)
                {
                    q.push(front->right);
                }
            }
        }
        return sum;
    }
};
