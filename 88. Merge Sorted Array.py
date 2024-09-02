from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        p1, p2 = m - 1, n - 1
        p = m + n - 1

        while p1 >= 0 and p2 >= 0:
            if nums1[p1] < nums2[p2]:
                nums1[p] = nums2[p2]
                p2 -= 1
            else:
                nums1[p] = nums1[p1]
                p1 -= 1
            p -= 1

        nums1[: p2 + 1] = nums2[: p2 + 1]

        # def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:

    #     for i in range(len(nums1))[::-1]:
    #         if m == 0:
    #             nums1[ : n] = nums2[ : n]
    #             break

    #         if n == 0:
    #             break

    #         if nums1[m-1] >= nums2[n-1]:
    #             nums1[i] = nums1[m-1]
    #             m -= 1
    #         else:
    #             nums1[i] = nums2[n-1]
    #             n -= 1


if "__main__" == __name__:
    sol = Solution()
    nums1 = [1, 2, 3, 0, 0, 0]
    nums2 = [2, 5, 6]
    sol.merge(nums1, len(list(filter(lambda x: x != 0, nums1))), nums2, len(nums2))
    print(nums1)
