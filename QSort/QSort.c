#include<stdio.h>

/**
 * 快速排序主函数
 * 
 * 参数：
 *   - array：待排序的数组。在C语言中可进行原址排序。
 * 	 - left：数组的左边界。
 *   - right：数组的右边界，初始值为数组最后一项的索引。
 */
void QSort(int *array, int left, int right)
{
	// 退出递归的条件，即左边界不再小于右边界
	//
	// 【注意】递归过程中，left最终会等于 len(array)，这会导致越界。
	// 		但在GNU C中，array[len(array)]是有效的，不会因越界而出现段错误，
	// 		因此这一句可以写在`int base = array[left];`后面。
	//		不过在Python中是不允许的。
	if(left > right)
		return;

	// 两个指针，分别从数组左右端往中间遍历
	int i = left, j = right;
	// 基准数。快速排序的目标，就是使基准数左边的数都比它小，右边的数都比它大
	// 默认选择数组最左边一项，但若要提高效率也可随机挑选一个数组项
	int base = array[left];

	// 开始用两个指针进行遍历
	while(i != j)
	{
		// 右指针先走，找到第一个比基准数小的数
		// 注意这里的大于等于号，如果不加等于，则指针j处数组项等于base时就不会再往前遍历了
		while(i < j  &&  array[j] >= base)		
			j--;

		// 左指针后走，找到第一个比基准数大的数
		// 注意这里的大于等于号，如果不加等于，则指针i在base处时就不会再往前遍历了
		while(i < j  &&  array[i] <= base)		
	       	i++;

		// 交换左右指针的数组项
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}

	// 当左右指针位置相同时，它们所在的位置就是可以放置基准数的地方了
	// 将基准数与指针所在处交换
	int temp = array[left];
	array[left] = array[i];
	array[i] = temp;

	// 分治，递归排序子数组
	QSort(array, left, i - 1);
	QSort(array, i + 1, right);
}


int main()
{
	//int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int arr[10] = {7, 8, 2, 6, 5, 3, 1, 9, 4, 10};
	QSort(arr, 0, 9);

	printf("arr[10]=%d\n", arr[10]);

	int i;
	for(i=0; i<10; i++)
		printf("%d\t", arr[i]);
}
