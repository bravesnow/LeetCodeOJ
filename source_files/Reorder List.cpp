#include <iostream>
using namespace std;
//LeetCode: Reorder List 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void travel(ListNode *pNode)
{//当前结点遍历链表
    while (pNode) {
	cout<<pNode->val<<endl;
	pNode = pNode->next;
    }
}
ListNode *reverse(ListNode *head)
{//单链表头插法带头结点翻转
    ListNode dummy(-1);
    ListNode *curpNode = head, *nextpNode;
    while (curpNode) {
	nextpNode = curpNode->next;
	curpNode->next = dummy.next;
	dummy.next = curpNode;
	curpNode = nextpNode;
    }
    return dummy.next;
}
void reorderList(ListNode *head) {
    if (head == NULL) {
	return;
    }
    ListNode *slow, *fast;
    slow = fast = head;
    while (fast->next && fast->next->next) {
	slow = slow->next;
	fast = fast->next->next;
    }    
    ListNode *halfhead = slow->next;
    slow->next = NULL;
    halfhead = reverse(halfhead);
    ListNode *curpNode = head, *nextpNode;
    ListNode *halfcurpNode = halfhead, *halfnextpNode;
    while (halfcurpNode) {
	halfnextpNode = halfcurpNode->next;
	nextpNode = curpNode->next;
	halfcurpNode->next = curpNode->next;
	curpNode->next = halfcurpNode;
	halfcurpNode = halfnextpNode;
	curpNode = nextpNode;
    }
}
int main(int argc, char *argv[])
{
    ListNode a(3), b(4), c(5);
    a.next = &b;
    b.next = &c;
    reorderList(&a);
    travel(&a);
    return 0;
}
