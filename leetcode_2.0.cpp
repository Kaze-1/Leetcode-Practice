#include<bits/stdc++.h>		//需要在vs的启动目录的include文件中手动设置
/*#include<iostream>
#include<vector>
#include<string>#include<algorithm>
*/
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};

int pairSum(ListNode* head) {

	ListNode* p = head;
	vector<int>front_half,rear_half,sums;
	int n = 0,num=0,i;
	while (p != nullptr)
	{
		p = p->next;
		n++;//get length of the list
	}
	p = head;
	while (p != nullptr)
	{
		if (num <= (n / 2) - 1)
			front_half.push_back(p->val);
		else 
			rear_half.push_back(p->val);
		p = p->next;
		num++;
	}
	reverse(rear_half.begin(),rear_half.end());
	for (i = 0; i < front_half.size(); i++)
		sums.push_back(front_half[i] + rear_half[i]);
	int max = *max_element(sums.begin(), sums.end());
	return max;
}


int main()
{
	vector<int>head = { 5, 4, 2, 1 };
	vector<ListNode*> List_nodes;
	for (int i = 0; i < head.size(); i++)
	{
		ListNode* tem=new ListNode;
		tem->val = head[i];
		List_nodes.push_back(tem);
	}
	ListNode* list = List_nodes[0];
	for (int i = 0; i < head.size(); i++)
	{
		ListNode* p = List_nodes[i];
		if (i < head.size()-1) p->next = List_nodes[i + 1];
		else p->next = nullptr;
	}
	ListNode* list_head = List_nodes[0];
	cout<<pairSum(list_head);
}