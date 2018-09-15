# -*- coding: UTF-8 -*-

'''
	Problem: Implement a program to print kth element from end

	example: 1 -> 4 -> 8 -> 9 -> 2       k=3
	answer: 8

	Approach: Take a pointer and iterate it through the kth index in the list. Then start a counter from head and iterate
	both the counters till the first counter reaches end of the list. Then return the second pointer. 

	Time Complexity: O(n) Space complexity: O(1)

'''

def k_from_end(head, k):
	'''Function to return the kth node from end using iterative approach'''

	if not head:
		raise ValueError("List is empty")

	k_node = head
	counter = 0

	while(counter < k):
		k_node = k_node.nextnode

		if not k_node.nextnode:
			raise ValueError("kth index out of range")

		counter += 1

	current = head
	while (k_node):
		current = current.nextnode
		k_node = k_node.nextnode


	return current

''' 
	Aprroach 2: Pass a value by reference of counter by making it a class object.  Recursively keep checking the index value and if 
	matches the k given, return the head. 
'''

class Index:
	def __init__(self):
		self.value = 0

def kth_to_last(head, k):
	'''Return the node at kth index of the list'''
	idx = Index()

	return kth_to_last_helper(head, k, idx)

def kth_to_last_helper(head, k, idx):
	'''Recursive function that checks if the index is equal to k'''
	if head is None:
		return None

	node = kth_to_last_helper(head.nextnode, k, idx)
	idx.value += 1

	if (idx.value == k):
		return head

	return node

if __name__ == "__main__":
	# Initializing the linked list
	import linked_list
	ll = linked_list.initialize_linked_list()
	ll.print_list()

	k = 3
	node = k_from_end(ll.head, k)
	print "Calculating the kth node using iterative approach. %s element from end is %s" %(k, node.data)

	node = kth_to_last(ll.head, k)
	print "Calculating the kth node using recursive approach. %s element from end is %s" %(k, node.data)
