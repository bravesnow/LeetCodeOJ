#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//Binary Tree Postorder Traversal
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> result;
    if (root == NULL){
	return result;
    }
    stack<TreeNode*> s;
    TreeNode *p;//正在访问的结点
    TreeNode *q;//刚被访问的结点
    s.push(root);//根结点入栈
    while (!s.empty()){
	p = s.top();//取得栈顶元素，然后if判断子树是否入栈，还是直接访问
	if ((p->left == NULL && p->right == NULL) ||
	    (q != NULL &&(q == p->left || q == p->right))){
	    //如何没有左右子树，则直接访问；或者左右子树不是刚访问的结点
	    result.push_back(p->val);
	    s.pop();
	    q = p;
	}
	else {
	    //先将右子树入栈，因为先访问的是左子树
	    if (p->right){
		s.push(p->right);
	    }
	    if (p->left){
		s.push(p->left);
	    }
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
    
    vector<int> x = postorderTraversal(root);
    cout<<x[0]<<x[1]<<x[2]<<x[3]<<endl;
    return 0;
}
