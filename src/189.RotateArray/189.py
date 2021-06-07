'''
File: 189.py
Created Date: 2021-03-08
Author: Nick Cao(caoyxsh@outlook.com)
Brief:
-----
Last Modified: 2021-03-08T05:58:06-08:00
Modified By: Nick Cao(caoyxsh@outlook.com)
'''


class Solution1:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Using Extra Array
        """
        k %= len(nums)
        last = nums[-k:]
        for i in reversed(range(k, len(nums))):
            nums[i] = nums[i-k]
        for i in range(0, len(last)):
            nums[i] = last[i]


class Solution2:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Using Cyclic Replacements
        """
        n = len(nums)
        k %= n

        start = count = 0
        while count < n:
            current, prev = start, nums[start]
            while True:
                next_idx = (current + k) % n
                nums[next_idx], prev = prev, nums[next_idx]
                current = next_idx
                count += 1

                if start == current:
                    break
            start += 1


class Solution3:
	"""
	Using Reverse
	"""

	def reverse(self, nums: list, start: int, end: int) -> None:
		while start < end:
            nums[start], nums[end] = nums[end], nums[start]
            start, end = start + 1, end - 1

	def rotate(self, nums: List[int], k: int) -> None:
		n = len(nums)
        k %= n

        self.reverse(nums, 0, n - 1)
        self.reverse(nums, 0, k - 1)
        self.reverse(nums, k, n - 1)
