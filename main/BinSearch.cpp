/*
 * 34. 在排序数组中查找元素的第一个和最后一个位置
 * 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]。
你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * 思路：找到第一个大于等于target的下标，然后找到第一个大于target的下标，-1即为最后一次出现target的下标
 */
class Solution
{
 public:
	int binsearch(vector<int>& nums, int target, bool islower)
	{
		int n = nums.size();
		int l = 0;
		int r = n - 1;
		int res = n;
		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			if (nums[mid] > target || (islower && (nums[mid] >= target)))
			{
				r = mid - 1;
				res = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		return res;
	}
	vector<int> searchRange(vector<int>& nums, int target)
	{
		int lindex = binsearch(nums, target, true);
		int rindex = binsearch(nums, target, false);
		//判断是否合法
		if (lindex <= rindex && rindex < nums.size() && nums[lindex] == target && nums[lindex] == target)
		{
			return vector<int>{ lindex, rindex };
		}
		return { -1, -1 };
	}
};
/*
 * class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        lindex = self.binsearch(nums,target,True)
        rindex = self.binsearch(nums,target,False)-1
        if lindex <= rindex and rindex < len(nums) and nums[lindex] == target and nums[rindex] == target:
            return [lindex,rindex]
        return [-1,-1]
    def binsearch(self,nums:List[int],target:int,islower:bool):
            l = 0
            r = len(nums)-1
            ans = len(nums)
            while l <= r:
                mid = l + (r - l)//2
                if (nums[mid] > target) or (islower and nums[mid] >= target):
                    r = mid - 1
                    ans = mid
                else:
                    l = mid + 1
            return ans

 */


/*
 *
 * 整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。

你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。
 */

class Solution1
{
 public:
	int search(vector<int>& nums, int target)
	{
		int n = nums.size();
		int l = 0;
		int r = n - 1;
		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			if (nums[mid] == target)
			{
				return mid;
			}
			if (nums[0] <= nums[mid])
			{//0-mid递增
				if (nums[0] <= target && nums[mid] > target)
				{
					r = mid - 1;
				}
				else
				{
					l = mid + 1;
				}
			}
			else
			{
				if (nums[mid] < target && nums[n - 1] >= target)
				{
					l = mid + 1;
				}
				else
				{
					r = mid - 1;
				}
			}

		}
		return -1;
	}
};

/*
 *
 * 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
 */

class Solution3
{
 public:
	bool searchMatrix(vector<vector<int>> matrix, int target)
	{
		auto row = upper_bound(matrix.begin(), matrix.end(), target, [](const int b, const vector<int>& a)
		{
		  return b < a[0];//找到第一列中第一个小于target的元素；
		});
		if (row == matrix.begin())
		{
			return false;
		}
		--row;
		return binary_search(row->begin(), row->end(), target);
	}
};

/*
 *
 * class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows, cols = len(matrix), len(matrix[0])

        left, right = rows - 1, 0

        while left>=0 and right < cols:
            if matrix[left][right]==target:
                return True
            if matrix[left][right] < target:
                right += 1
            else:
                left -=1
        return False
 */


/*
 *
 * 153. 寻找旋转排序数组中的最小值
 * https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/description/
 *
 *
 */

class Solution4
{
 public:
	int findMin(vector<int>& nums)
	{
		int n = nums.size();
		int l = 0;
		int r = n - 1;
		while (l < r)//[3 1 2]为例子，
		{
			int mid = l + (r - l) / 2;
			if (nums[mid] > nums[r])
			{
				l = mid + 1;
			}
			else
			{
				r = mid;
			}
		}
		return nums[l];

	}
};

/*
 * 162寻找峰值
 */


class Solution5
{
 public:
	int findPeakElement(vector<int>& nums)
	{
		int n = nums.size();
		int idx = rand() % n;

		// 辅助函数，输入下标 i，返回一个二元组 (0/1, nums[i])
		// 方便处理 nums[-1] 以及 nums[n] 的边界情况
		auto get = [&](int i) -> pair<int, int>
		{
		  if (i == -1 || i == n)
		  {
			  return { 0, 0 };
		  }
		  return { 1, nums[i] };
		};
		while (!(get(idx - 1) < get(idx) && get(idx) > get(idx + 1)))
		{
			if (get(idx) < get(idx + 1))
			{
				idx += 1;
			}
			else
			{
				idx -= 1;
			}
		}
		return idx;
	}
};

/**
 * @brief https://leetcode.cn/problems/minimum-limit-of-balls-in-a-bag/
 * 1760. 袋子里最少数目的球
 */

/**
 * @brief 
 * 
 * @param nums nums[i]表示第i个袋子里球的数目，
 * @param maxOperations 最大操作数
 * @return int 
 */


 int minimumSize(vector<int>& nums, int maxOperations) {
 /**
        * 最大值最小化  -二分答案
        * l:从1 开始
        * r: 从 数组中最大的数开始
        * 对于操作数进行二分，如果操作数小于等于maxoperations：
        本题二分的思路就是二分单个袋子里面的球的个数的最大值，也就是袋子容量，
        然后判断此次的操作数有没有大于最大操作数
如果大于最大操作数，违法了。那么我们就减少操作数即可，减少操作数对应就是增加单个袋子容量
如果小于等于最大操作数，合法。因此我们可以增大操作数，或者保持不变，那么对应就是减少单个袋子容量
        */
        int n = nums.size();
        int l = 1;
        int r = *max_element(nums.begin(),nums.end());
        int ans  = 0;
        while( l <= r){
            int mid = l + ((r-l) >> 1);
			/**
			 * @brief 操作数表示：nums[i]-1 ) / mid   向下取整
			 * nums[i] <= mid  无需操作
			 * nums[i] > mid && nums[i] < 2 * mid 操作一次
			 * 2 * mid  < nums[i] && nums[i] < 3 * mid 操作两次
			 * 
			 */
            int opt = 0;
            for(auto num:nums){     
                opt+=(num-1)/mid;

            }
            if (opt <= maxOperations){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;

    }


/**
 * @brief https://leetcode.cn/problems/koko-eating-bananas/
 * 
 * @param piles piles[i]代表有多少香蕉
 * @param h 时间
 * @return int 
 * 返回最小速度
 * 随着最小速度k的 增加，h就会减小，反之，h就会增大。则当吃香蕉的速度大于每小时 k 个香蕉时一定可以在 h小时内吃掉所有香蕉，
 * 当吃香蕉的速度小于每小时 k 个香蕉时一定不能在 h 小时内吃掉所有香蕉。
 * 
 * 假设吃香蕉的速度是speed,则当一堆香蕉的数目是pile时候，吃掉这堆香蕉所消耗时间是pile / speed 向上取整  
 * 由此可以计算出吃掉所有香蕉需要的时间。如果在速度 speed 下可以在 h小时内吃掉所有香蕉，
 * 则最小速度一定小于或等于 speed，因此将上界调整为 speed；否则，最小速度一定大于 speed，
 * 因此将下界调整为 speed+1。

二分查找结束之后，即可得到在 h小时内吃掉所有香蕉的最小速度 kk。

 */
class minEatingspeed{
	 int minEatingSpeed(vector<int>& piles, int h) {
		int l = 1;  //最小值是 1
		int r = *max_element(piles.begin(), piles.end());  //最大值是 香蕉数目最大的


		int ans = r;
		while (l < r)		
		{
			int speed = (r-l) / 2 + l;

			int time = getTime(piles,speed);

			if(time <= h){
				ans = speed;
				r = speed;
			}
			else{
				l = speed + 1;
			}
		}
		return ans;
    }
	long long  getTime(vector<int>&piles,int speed){
		long long time = 0;
		for (auto pile:piles){
			int curtime = (pile + speed - 1) / speed;
			time += curtime;
		}
		return time;
	}

};







