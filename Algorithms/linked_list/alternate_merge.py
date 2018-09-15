# -*- coding: UTF-8 -*-

# Program to alternately merge the elements of two given linked lists into a single list.

import initialize

def alternate_merge(head1, head2):

	if not head1 and not head2:
		return

	if not head2:
		return head1
	
	if not head1:
		return head2

	temp1 = head1
	temp2 = head2
	prev1 = None

	while (temp1 and temp2):

		prev1 = temp1
		next1 = temp1.nextnode

		prev2 = temp2
		next2 = temp2.nextnode

		prev1.nextnode = prev2
		prev2.nextnode = next1

		temp2 = next2
		temp1 = next1

	if temp2:
		prev2.nextnode = temp2

	return head1

lList1 = initialize.initialize_linked_list()
lList2 = initialize.initialize_linked_list_by_array([4, 5, 6, 7, 8, 9])

head1 = alternate_merge(lList1.head, lList2.head)

while (head1):
	print head1.data
	head1 = head1.nextnode