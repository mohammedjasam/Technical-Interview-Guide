# coding: UTF-8

'''
	Problem: Write a program to check if a linked lists is a palindrome or not. 

	Solution: Iterate upto half of the linked list and put the elements in a stack and pop element one by one and compare it with the
	rest of the linked list. If all elements matches, it is a palindrome. 

	Example: 1->2->3->2->1 returns True
			 1->3->4->3->5 returns False 

	# TODO: Solve this problem by reversing the linked list
'''

import linked_list

def check_palindrome(ll):
	'''Check if a linked list is a palindrome '''
	slow_ptr = ll.head
	fast_ptr = ll.head
	stack = []

	while(fast_ptr != None and fast_ptr.nextnode != None):
		# Append the half of the linked list into a stack
		stack.append(slow_ptr.data)
		slow_ptr = slow_ptr.nextnode
		fast_ptr = fast_ptr.nextnode.nextnode

	# To check if the linked list is odd length or even length
	if fast_ptr is None:
		second_half = slow_ptr
	else:
		second_half = slow_ptr.nextnode

	while (len(stack) != 0 and second_half != None):
		first_half = stack.pop(-1)
		if first_half != second_half.data:
			return False
		second_half  = second_half.nextnode

	return True

if __name__ == "__main__":
	# Check for the linked list (33 4 8 41 9 6 13 5 4)
	ll = linked_list.initialize_linked_list()
	ll.print_list()
	print check_palindrome(ll)

	ll = linked_list.LinkedList()
	ll.insert(4)
	ll.insert(5)
	ll.insert(13)
	ll.insert(13)
	ll.insert(5)
	ll.insert(4)
	ll.print_list()
	# Check for the linked list (4 5 13 13 5 4)
	print check_palindrome(ll)
		