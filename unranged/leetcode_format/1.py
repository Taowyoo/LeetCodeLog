class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """One pass using HashMap

        Args:
            nums (List[int]): number list
            target (int): target sum

        Returns:
            List[int]: the index of two result nums
        """
        d = {}
        for i, n in enumerate(nums):
            m = target - n
            if m in d:
                return [d[m], i]
            else:
                d[n] = i



class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
            """Two pass using HashMap

            Args:
                nums (List[int]): number list
                target (int): target sum

            Returns:
                List[int]: the index of two result nums
            """
            d = {}
            for i, n in enumerate(nums):
                d[n]=i
                
            for i, n in enumerate(nums):
                m = target - n
                if m in d and d[m] != i:
                    return [i,d[m]]
            return []