#Problem:
#Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

#Solution:
def foo(nums):
    maxSum = []
    maxSum.append(nums[0])
    
    for i in range(len(nums)-1):
        sum = maxSum[i] + nums[i+1]
        if(sum > nums[i+1]):
            maxSum.append(sum)
        else:
            maxSum.append(nums[i+1])
    
    return max(maxSum)


print(foo([-2,1,-3,4,-1,2,1,-5,4]))
