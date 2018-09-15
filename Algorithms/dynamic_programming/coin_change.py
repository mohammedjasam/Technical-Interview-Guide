# -*- coding: UTF-8 -*-

'''
	coin change problem

	Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} 
	valued coins, how many ways can we make the change? 
'''

# Time complexity: O(2^n) as each coin has two possibility either included or not included
def coin_change(coins, total):
	'''Find the number of possible ways to make the change'''

	# When total is 0, we have got a set, hence returns 1
	if not total:
		return 1

	# When total < 0, no set possible, returns 0
	if total < 0:
		return 0
	
	if not coins and total:
		return 0
	
	else: 
		# It involves two cases:
		# 1. When the coin at 0 index is part of the set, then the set will remain same and total will reduce
		# 2. When the coin at 0 index is not part of the set, then the set will remove the coin[0] and total will remain same
		return coin_change(coins, total - coins[0]) + coin_change(coins[1:], total)

# Time complexity: O(m*n)
def coin_change_dynamic(coins, total):
	'''Return the number of ways to to make the change using dynamic approach'''
	result = [[0] * len(coins) for i in range(total+1)] 

	for i in range(total+1):
		for j, coin in enumerate(coins):
			if not i:
				result[i][j] = 1
			else:
				# When the coin is part of the solution
				x = result[i-coin][j] if i - coin >= 0 else 0
				# When coin is not part of the solution
				y = result[i][j-1] if j >= 1 else 0
				
				# total count
				result[i][j] = x + y

	return result[total][len(coins)-1]

# Writing unittest for the above functions
import unittest

class MyTest(unittest.TestCase):
	def setUp(self):
		self.total = 4
		self.coins = [1, 2, 3]

	def test_coin_change_recursive(self):
		self.assertEqual(coin_change(self.coins, self.total), 4)

	def test_coin_change_dynamic(self):
		self.assertEqual(coin_change_dynamic(self.coins, self.total), 4)

if __name__ == "__main__":
	unittest.main()
