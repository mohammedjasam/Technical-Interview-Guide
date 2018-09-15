 #  *  coding: UTF 8  * 
 
 # Program to find intersection of two sorted linked list
 
 import initialize 
 
 class Node(object):
 
 	def __init__(self, data):
 
 		self.data = data
 		self.nextnode = None
 
 def find_intersection_of_two_linked_list(head1, head2, head):
 	if not head1 or not head2:
 		raise ValueError ("Linked list are empty")
 
 	current1 = head1
 	current2 = head2
 
 	while current1 and current2:
 		if current1.data < current2.data:
 			current1 = current1.nextnode
 		elif current2.data < current1.data:
 			current2 = current2.nextnode
 		elif current1.data == current2.data:
 			temp = Node(current1.data)
 			if head == None:
 				head = temp
 				tail = head
 			else:
 				tail.nextnode = temp
 				tail = tail.nextnode
 			current1 = current1.nextnode
 			current2 = current2.nextnode
 	return head
 
 lList1 = initialize.initialize_linked_list_by_array([6, 4, 3, 2, 1])
 lList2 = initialize.initialize_linked_list_by_array([8, 6, 4, 2])
 
 head = find_intersection_of_two_linked_list(lList1.head, lList2.head, None)
 
 while (head):
 	print head.data
 	head = head.nextnode