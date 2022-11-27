#include<bits/stdc++.h> //万能头文件

//节点结构参考 剑指offer

//链表
struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) :
		val(x), next(NULL) {}
	ListNode() :
		val(0), next(NULL) {}
};

//二叉树

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {}
	TreeNode() :
		val(0), left(NULL), right(NULL) {}
}; 


//链表通解
{
	//初始化部分（初始化指针p,pre等）    有时还要初始化q, pNext
	ListNode* p = pHead; //“基础指针”p从第一个元素开始
	ListNode* pre = nullptr;  //pre自然初始化成nullptr
	其他指针初始化（如果有必要）
		while (p != nullptr)//遍历条件部分
		{
			//操作部分
			通过p, pre等指针对链表执行操作
				//遍历迭代部分
				pre = p;
			p = pNext;
		}
	//此时p=nullptr, pre
}

//求vector中最大值和最小值
//最大值：
int maxValue = *max_element(v.begin(), v.end());
//最小值：
int minValue = *min_element(v.begin(), v.end());

int main()
{
	

}