# -*- coding: UTF-8 -*-

'''
	Problem: Create all the array sequence that will result in the same binary search tree. 

	Example:
			    2
			  /   \
			 1     3

			Result: {2, 1, 3} {2, 3, 1}
'''

def findAllSeq(root):
	''' Function to print all the sequences of a binary search tree '''
	
	result = []
	if root is None:
		result.append([])
		return result

	prefix = []
	prefix.add(root.data)

	left = findAllSeq(root.left)
	right = findAllSeq(root.right)

	for i in range(len(left)):
		for j in range(len(right)):
			weaved = []
			weavedLists(left, right, weaved, prefix)
			result.append(weaved)
	
	return result

def weavedLists(first, second, results, prefix):
	if len(first) == 0 or len(second) == 0:
		result = prefix
		result.append(first)
		result.append(second)
		results.append(result)
		return


	headfirst = 
	prefix.append(headfirst)
	weavedLists(first, second, results, prefix)
	prefix.pop()
	first.append(headfirst)

	headSecond = second



