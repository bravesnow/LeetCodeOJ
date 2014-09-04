#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//Binary Tree Preorder Traversal
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<vector<int> > levelOrder(TreeNode *root)
{//层次遍历
    vector<vector<int> > rt;    
    if (root == NULL){
	//空树返回空容器
	return rt;
    }
    
    queue<TreeNode*> q_cur;//记录当前层的结点
    q_cur.push(root);//初始层结点
    vector<int> elem;//存储一层结点的值
    while (!q_cur.empty()){
	queue<TreeNode*> q_next;//记录下一层存在的结点
	while (!q_cur.empty()){
	    //对当前层结点循环出队，产生下一层结点，及其存储结点值	    
	    TreeNode *temp = q_cur.front();//取出队头结点
	    q_cur.pop();//删除队头结点
	    elem.push_back(temp->val);	    
	    if (temp->left)//非空左子树入队
		q_next.push(temp->left);
	    if (temp->right)//非空右子树入队
		q_next.push(temp->right);
	}
	rt.push_back(elem);
	elem.clear();
	q_cur = q_next;//将下一层置为当前层
    }
    reverse(rt.begin(), rt.end());
    return rt;
    
}
int main(int argc, char *argv[])
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(5);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    
    vector<vector<int> > x = levelOrder(root);
    cout<<x.size()<<endl;
    return 0;
}
