#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//Binary Tree Preorder Traversal
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> inorderTraversal(TreeNode *root)
{//中序遍历
    vector<int> result;
    if (root == NULL){
	return result;
    }
    stack<TreeNode*> s;
    TreeNode *p = root;//正在访问的结点
    while (p || !s.empty()){
	while (p != NULL){	    
	    s.push(p);
	    p = p->left;
	}
	if (!s.empty()){
	    p = s.top();
	    result.push_back(p->val);
	    s.pop();
	    p = p->right;
	}
    }
    return result;  
}
int main(int argc, char *argv[])
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(5);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    
    vector<int> x = inorderTraversal(root);
    cout<<x[0]<<x[1]<<x[2]<<x[3]<<endl;
    return 0;
}
