def QSort(array):
    """
    快速排序函数。
    这是一个封装，因为Python不支持原址排序。

    参数：
        - array: 待排序的数组list。
    
    返回：
        排好序的数组list。
    """

    # 工作数组。
    # Python不支持原址排序，所以只能用闭包了
    # 主函数_QSort可以直接对它进行修改，能够起到C语言里原址排序的作用
    _array = array.copy()

    def _QSort(left, right):
        """
        快速排序函数的本体。
        
        参数：
            - left：子数组的左边界。
            - right：子数组的右边界，为数组的最后一项。
        """

        # 退出递归的条件，即左边界不再小于右边界
        if left > right:
            return

        # 定义一前一后两个指针i、j
        i = left
        j = right
        # 基准数。默认挑选数组第一项
        base = _array[left]

        # 开始用两个指针进行遍历
        while i != j:

            # 右指针先走，找到第一个比基准数小的数
            while i < j and _array[j] >= base:
                j -= 1
            
            # 左指针后走，找到第一个比基准数大的数
            while i < j and _array[i] <= base:
                i += 1

            # 交换左右指针的数组项
            # Python只用一个语句就可以完成两个变量值的交换
            _array[i], _array[j] = _array[j], _array[i]

        # 当左右指针位置相同时，它们所在的位置就是可以放置基准数的地方了
        # 将基准数与指针所在处交换
        _array[i], _array[left] = _array[left], _array[i]

        # 分治，递归排序子数组
        _QSort(left, i - 1)
        _QSort(i + 1, right)


    # 调用本体进行快排，最后返回结果
    _QSort(0, len(array) - 1)
    return _array


if __name__ == "__main__":
    arr = [7, 8, 2, 6, 5, 3, 1, 9, 4, 10]
    print(QSort(arr))


