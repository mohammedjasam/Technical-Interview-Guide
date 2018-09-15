# -*- coding: UTF-8 -*-

# Program to verify if a link list is a palindrome

import initialize

def compare(head, head2):
	if not head and not head2:
		return True

	if not head or not head2:
		return False

	while head and head2:
		if head.data != head2.data:
			return False
		head = head.nextnode
		head2 = head2.nextnode

	return True

def reverse(head):
	curr = head
	prev = None

	while curr:
		next = curr.nextnode
		curr.nextnode = prev
		prev = curr
		curr = next

	return prev

def check_palindrome(head):
	if not head or not head.nextnode:
		return True

	fast_ptr = head
	slow_ptr = head
	while fast_ptr and fast_ptr.nextnode:
		prev_slow_ptr = slow_ptr
		slow_ptr = slow_ptr.nextnode
		fast_ptr = fast_ptr.nextnode.nextnode

	if fast_ptr:
		mid_point = slow_ptr
		slow_ptr = slow_ptr.nextnode

	second_half = slow_ptr
	prev_slow_ptr.next = None
	# Reverse second half of linked list
	head_second_half = reverse(second_half)
	# Compare two lists if they are equal or not
	result = compare(head, head_second_half)
	
	head_second_half = reverse(head_second_half)

	if mid_point:
		slow_ptr.nextnode = mid_point
		mid_point.nextnode = head_second_half
	else:
		prev_slow_ptr.nextnode = second_half

	return result

head = initialize.initialize_linked_list()
print check_palindrome(head)
