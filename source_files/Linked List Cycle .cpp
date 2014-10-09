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
bool hasCycle(ListNode *head)
{
    if (head == NULL || head->next == NULL) {
	return false;
    }
    ListNode *slow = head, *fast = head->next->next;
    while (fast != NULL && fast->next != NULL) {
	if (slow == fast) {
	    return true;
	}
	slow = slow->next;
	fast = fast->next->next;
    }
    return false;
}

int main(int argc, char *argv[])
{
    ListNode a(3), b(4), c(5);
    a.next = &b;
    b.next = &c;
    //c.next = &a;
    cout<<hasCycle(&a);
    
    return 0;
}
