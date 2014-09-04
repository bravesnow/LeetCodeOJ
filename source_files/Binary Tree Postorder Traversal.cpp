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
    TreeNode *p;//���ڷ��ʵĽ��
    TreeNode *q;//�ձ����ʵĽ��
    s.push(root);//�������ջ
    while (!s.empty()){
	p = s.top();//ȡ��ջ��Ԫ�أ�Ȼ��if�ж������Ƿ���ջ������ֱ�ӷ���
	if ((p->left == NULL && p->right == NULL) ||
	    (q != NULL &&(q == p->left || q == p->right))){
	    //���û��������������ֱ�ӷ��ʣ����������������Ǹշ��ʵĽ��
	    result.push_back(p->val);
	    s.pop();
	    q = p;
	}
	else {
	    //�Ƚ���������ջ����Ϊ�ȷ��ʵ���������
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
