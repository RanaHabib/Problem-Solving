#Problem:
#On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
#Once you pay the cost, you can either climb one or two steps.
#You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

#Solution:
def minCost(cost):
    l = len(cost)
    dp0 = dp1 = dp2 = 0
    for i in range(l):
        dp0 = cost[i] + min(dp1, dp2)
        dp2 = dp1
        dp1 = dp0
        
    return min(dp1,dp2)                
