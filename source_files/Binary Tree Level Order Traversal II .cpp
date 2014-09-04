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
{//��α���
    vector<vector<int> > rt;    
    if (root == NULL){
	//�������ؿ�����
	return rt;
    }
    
    queue<TreeNode*> q_cur;//��¼��ǰ��Ľ��
    q_cur.push(root);//��ʼ����
    vector<int> elem;//�洢һ�����ֵ
    while (!q_cur.empty()){
	queue<TreeNode*> q_next;//��¼��һ����ڵĽ��
	while (!q_cur.empty()){
	    //�Ե�ǰ����ѭ�����ӣ�������һ���㣬����洢���ֵ	    
	    TreeNode *temp = q_cur.front();//ȡ����ͷ���
	    q_cur.pop();//ɾ����ͷ���
	    elem.push_back(temp->val);	    
	    if (temp->left)//�ǿ����������
		q_next.push(temp->left);
	    if (temp->right)//�ǿ����������
		q_next.push(temp->right);
	}
	rt.push_back(elem);
	elem.clear();
	q_cur = q_next;//����һ����Ϊ��ǰ��
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
