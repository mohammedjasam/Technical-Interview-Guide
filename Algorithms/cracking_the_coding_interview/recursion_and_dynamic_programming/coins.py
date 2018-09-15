# -*- coding: UTF-8 -*-

'''
	Given an infinite number of quaters(25 cents), dimes(10 cents), nickels(5 cents), pennies(1 cent), write code 
	to calculate the number of ways of representing them.
'''

def count_ways_recursive(total, coins):
	if total < 0:
		return 0

	if total == 0:
		return 1

	if not coins and total:
		return 0

	return count_ways_recursive(total-coins[0], coins) + count_ways_recursive(total, coins[1:])

def count_ways_dynamic(total, coins):
	soln = [[0] * len(coins) for i in range(total+1)]

	for i in range(total+1):
		for j in range(len(coins)):
			if i == 0:
				soln[i][j] = 1

			else:
				if coins[j] <= i:
					soln[i][j] += soln[i-coins[j]][j] 
				if j >= 1:
					soln[i][j] += soln[i][j-1]

	return soln[total][len(coins)-1]

if __name__ == '__main__':
	print count_ways_recursive(100, [25, 10, 5, 1])
	print count_ways_dynamic(100, [25, 10, 5, 1])
