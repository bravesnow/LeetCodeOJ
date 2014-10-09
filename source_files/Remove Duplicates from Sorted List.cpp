#include <iostream>
using namespace std; 
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
ListNode *deleteDuplicates(ListNode *head)
{
    if (head == NULL) {
	return head;
    }
    ListNode *curp = head, *nextp = head->next;
    while (nextp) {
	if (curp->val == nextp->val) {
	    nextp = nextp->next;
	} else {
	    curp->next = nextp;
	    curp = nextp;
	    nextp = nextp->next;
	}
    }
    curp->next = NULL;
    return head;
}
int main(int argc, char *argv[])
{
    ListNode a(3), b(3), c(5), d(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    travel(deleteDuplicates(&c));

    return 0;
}
