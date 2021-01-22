#Problem:
#Balanced strings are those who have equal quantity of 'L' and 'R' characters.
#Given a balanced string s split it in the maximum amount of balanced strings.
#Return the maximum amount of splitted balanced strings.



#Solution
def balancedStringSplit(s):
    """
    :type s: str
    :rtype: int
    """
    g = answer = 0

    l = len(s)
    for i in range(l):
        if(s[i] == "R"):
            g+=1
        else:
            g-=1
        if(g == 0):
            answer+=1

    return answer
