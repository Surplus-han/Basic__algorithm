#在一个排好序的数组中找第一个大于等于target 的元素的位置



"""
二分常见的问题在：
查找的区间：
[]      >=
        >   看成  >= target + 1
()      <   看成   (>=target) - 1
(]      <=  看成   (>target) - 1



"""
def lower_bound(self,nums:List[int],target:int)->int:
    left = 0
    right = len(nums)-1#闭区间[left,right]
    while left <= right:
        mid = (left + right)//2
        if nums[mid] < target:
            left = mid + 1 #[mid+1,right]
        else:
            right = mid - 1 #[left,mid-1]
    return left


def lower_bound1(self,nums:List[int],target: int)-> int:
    left = 0
    right = len(nums)#闭区间[left,right)
    while left < right:
        mid = (left + right)//2
        if nums[mid] < target:
            left = mid + 1 #[mid+1,right]
        else:
            right = mid #[left,mid-1]
    return left #right



def lower_bound2(self,nums:List[int],target: int)-> int:
    left = -1
    right = len(nums)#开区间(left,right)
    while left < right - 1:
        mid = (left + right)//2
        if nums[mid] < target:
            left = mid  #[mid+1,right]
        else:
            right = mid #[left,mid-1]
    return right



