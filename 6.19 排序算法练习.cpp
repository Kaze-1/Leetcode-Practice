#include<bits/stdc++.h>
using namespace std;

//将[i,h)调整成大顶堆（[i-1,h)本身已经是堆）
void adjust(vector<int>& nums, int i, int h)
{
	int temp = nums[i];//先取出当前待调整元素nums[i]
	for (int k = i * 2 + 1; k < h; k = k * 2 + 1) {//从i结点的左子结点开始，也就是2i+1处开始
		if (k + 1 < h && nums[k] < nums[k + 1]) {//如果左子结点小于右子结点，k指向右子结点
			k++;
		}
		if (nums[k] > temp) {//如果子节点大于父节点，将子节点值赋给父节点（不用进行交换）
			nums[i] = nums[k];
			i = k;
		}
		else {
			break;
		}
	}
	nums[i] = temp;//将temp值放到最终的位置
}

void heapSort(vector<int>& nums)
{
	int n = nums.size(), i;
	for (i = n/2- 1; i >= 0; i--)
		adjust(nums, i,n);
	for (i = n - 1; i >=1; i--)
	{	
		swap(nums[0], nums[i]);
		adjust(nums,0, i);
	}
}


int partition(vector<int>& nums, int l, int h)
{
	int pivot = nums[l];
	while (l < h)
	{
		while (l < h && nums[h] >= pivot)
			h--;
		nums[l] = nums[h];
		while (l < h && nums[l] <= pivot)
			l++;
		nums[h] = nums[l];
	}
	nums[l] = pivot;
	return l;
}


void rapidSort(vector<int>& nums, int l, int h)
{
	if (l < h)
	{
		int pivot=partition(nums, l, h);
		rapidSort(nums, l, pivot-1);
		rapidSort(nums, pivot+1, h);
	}
}

void bubbleSort(vector<int>&nums)
{
	int n = nums.size(),i,j;
	for(i=0;i<n-1;i++)
		for (j = i + 1; j < n; j++)
		{
			if (nums[j] < nums[i])
				swap(nums[j], nums[i]);
		}
}

int main()
{
	vector<int>nums = { 5,4,8,2,1,0 };
	//bubbleSort(nums);
	heapSort(nums);
	//rapidSort(nums, 0, nums.size() - 1);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
}
