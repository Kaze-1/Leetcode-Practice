#include<bits/stdc++.h> //����ͷ�ļ�

//�ڵ�ṹ�ο� ��ָoffer

//����
struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) :
		val(x), next(NULL) {}
	ListNode() :
		val(0), next(NULL) {}
};

//������

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {}
	TreeNode() :
		val(0), left(NULL), right(NULL) {}
}; 


//����ͨ��
{
	//��ʼ�����֣���ʼ��ָ��p,pre�ȣ�    ��ʱ��Ҫ��ʼ��q, pNext
	ListNode* p = pHead; //������ָ�롱p�ӵ�һ��Ԫ�ؿ�ʼ
	ListNode* pre = nullptr;  //pre��Ȼ��ʼ����nullptr
	����ָ���ʼ��������б�Ҫ��
		while (p != nullptr)//������������
		{
			//��������
			ͨ��p, pre��ָ�������ִ�в���
				//������������
				pre = p;
			p = pNext;
		}
	//��ʱp=nullptr, pre
}

//��vector�����ֵ����Сֵ
//���ֵ��
int maxValue = *max_element(v.begin(), v.end());
//��Сֵ��
int minValue = *min_element(v.begin(), v.end());

int main()
{
	

}