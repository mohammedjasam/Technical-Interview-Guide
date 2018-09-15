# -*- coding: UTF-8 -*-

# Program to add two numbers

import initialize
import linked_list

def add(head1, head2):

	if not head1 or not head2:
		return "Linked List are empty"

	curr = None
	carry = 0

	while (head1 or head2):
		total_sum = 0
		
		if head1:
			total_sum += head1.data

		if head2:
			total_sum += head2.data

		
		sum = carry + (total_sum % 10)
		carry = total_sum / 10

		temp = linked_list.Node(sum)

		if curr:
			curr.nextnode = temp
			curr = curr.nextnode
		else:
			ll = linked_list.LinkedList(temp)
			curr = ll.head

		if head1:
			head1 = head1.nextnode
		if head2:
			head2 = head2.nextnode

	if carry:
		curr.nextnode = linked_list.Node(carry)

	return ll


lList1 = initialize.initialize_linked_list_by_array([8, 0, 0])
lList2 = initialize.initialize_linked_list_by_array([8, 0, 0])

ll = add(lList1.head, lList2.head)

ll.print_list()