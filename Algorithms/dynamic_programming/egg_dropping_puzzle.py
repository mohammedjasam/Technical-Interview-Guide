# -*- coding: UTF-8 -*-

# Egg dropping puzzle

'''
	Suppose that we wish to know which stories in a 36-story building are safe to drop eggs from, and which will cause the
	eggs to break on landing. We make a few assumptions:

	- An egg that survives a fall can be used again.
	- A broken egg must be discarded.
	- The effect of a fall is the same for all eggs.
	- If an egg breaks when dropped, then it would break if dropped from a higher floor.
	- If an egg survives a fall then it would survive a shorter fall.
	- It is not ruled out that the first-floor windows break eggs, nor is it ruled out that the 36th-floor
	do not cause an egg to break.

	If only one egg is available and we wish to be sure of obtaining the right result, the experiment can be carried out
	in only one way. Drop the egg from the first-floor window; if it survives, drop it from the second floor window.
'''
import sys

def egg_drop(eggs, floor):
	# If no floor is present, then no trial is needed
	if not floor:
		return 0

	# If one floor is there, only one trial is required
	if floor == 1:
		return 1

	# If eggs is 1, then trial will be same as number of floors
	if eggs == 1:
		return floor

	else:
		min = sys.maxint
		for i in range(2, floor):
			egg_breaks = egg_drop(eggs-1, i-1)
			egg_does_not_break = egg_drop(eggs, floor-i)
			# We are calculating the number of trials, if egg breaks at i, trials will be reduced  i-1, else
			# if egg does not break, trials will reduce by floor-i, we will have to consider the max of the two possibilities
			res = max(egg_breaks, egg_does_not_break)

			if res < min:
				min = res

		return min + 1

def egg_drop_dynamic(eggs, floor):
	trials = [[0] * (floor+1) for i in range(eggs+1)]

	# When the egg is 1, we will have to do 1 trial at each floor
	for i in range(1, floor+1):
		trials[1][i] = i

	# If floor is one, there will be only one trial
	for i in range(1, eggs+1):
		trials[i][1] = 1

	for i in range(2, eggs+1):
		for j in range(2, floor+1):
			trials[i][j] = sys.maxint
			for k in range(1, j+1):
				does_break = trials[i-1][k-1]
				does_not_break = trials[i][j-k]

				res = max(does_break, does_not_break) + 1

				if res < trials[i][j]:
					trials[i][j] = res
	return trials[eggs][floor]

import unittest

class MyTest(unittest.TestCase):
	def setUp(self):
		self.eggs = 3
		self.floors = 20

	def test_edit_distance_recursive(self):
		self.assertEqual(egg_drop(self.eggs, self.floors), 4)

	def test_edit_distance_dynamic(self):
		self.assertEqual(egg_drop_dynamic(self.eggs, self.floors), 4)

if __name__ == "__main__":
	unittest.main()
