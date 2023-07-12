# ����������
# https://leetcode.cn/contest/biweekly-contest-108/problems/longest-alternating-subarray/

# ����ѭ��ģ��

# ����ѭ��
# ���ѭ����ȷ������������
# �ڲ�ѭ����ö����������Ҷ˵�

#ʱ�临�Ӷ�O(n)   
class Solution:
    def alternatingSubarray(self, nums: List[int]) -> int:
        ans = -1
        i = 0
        n = len(nums)
        while i < n - 1:
            if nums[i+1] - nums[i] != 1:
                i+=1
                continue
            i0 = i # ��¼���
            i+=1   # i �ĺ���������������Ҷ˵�
            while i < n and nums[i] == nums[i0 + (i-i0) % 2]: # ��������
                i+=1
            ans = max(ans,i-i0) # [i0,i)
            i-=1 # �������� 3 4 3 4 5 4 5  3434 ��һ�������� 4545 Ҳ�ǣ��н���4��i��Ҫ����1
        return ans

        