class Solution:
    # def climbStairs(self, n: int) -> int:
    # options = [1,1] #0:1 1:1
    # for i in range(2, n+1):
    #     options.append(options[i-1]+options[i-2])
    # return options[n]
    def climbStairs(self, n: int) -> int:
        prev_one_step, prev_two_steps = 1, 1
        for i in range(2, n + 1):
            current_ways = prev_one_step + prev_two_steps
            prev_one_step, prev_two_steps = current_ways, prev_one_step
        return prev_one_step


if __name__ == "__main__":
    print(Solution().climbStairs(2))
    print(Solution().climbStairs(3))
    print(Solution().climbStairs(4))
    print(Solution().climbStairs(5))
