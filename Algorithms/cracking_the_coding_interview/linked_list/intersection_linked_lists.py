# coding: UTF-8

'''
    Problem: Write a program to find the intersection of two linked list.

    Solution: First compare the tail of two linked lists, if not same return False, otherwise look for intersection point. 
    Calculate the length of both linked lists and find the difference between the two. Then move a pointer in the 
    longer linked list forward by the difference in lengths, then compare each node of the linked list. If two nodes 
    matches, check rest of the linked list and if same, return the intersection point. 

    Example: 
        33 4 8 41 9 6 13 5 4

        8 10 9 6 13 5 4

        Result: 9

'''

import linked_list

def get_size_and_tail(linked_list):
    '''Return the tail and size of linked list'''
    current = linked_list.head
    size = 0

    while(current.nextnode is not None):
        size += 1
        current = current.nextnode

    return current, size+1

def check_Rest_of_node(linked_list1, linked_list2):
    '''When two nodes matches, check if remaining lists are same'''
    while (linked_list1 != None and linked_list2 != None):
        if (linked_list1 != linked_list2):
            return False

        linked_list1 = linked_list1.nextnode
        linked_list2 = linked_list2.nextnode

    return True

def find_intersection(linked_list1, linked_list2, difference):
    '''Check if two linked lists are intersecting'''
    for i in range(difference):
        linked_list1 = linked_list1.nextnode

    while (linked_list1 != None and linked_list2 != None):
        if linked_list1 == linked_list2:
            intersection_node = linked_list1.data
            if check_Rest_of_node(linked_list1, linked_list2):
                return intersection_node
        
        linked_list1 = linked_list1.nextnode
        linked_list2 = linked_list2.nextnode
    
    return False

def find_intersection_helper(linked_list1, linked_list2):
    '''Calculate the difference between length of two linked lists and call find_intersection function'''
    tail1, len_1 = get_size_and_tail(linked_list1)
    tail2, len_2 = get_size_and_tail(linked_list2)

    # IF the tails of two linked list are different, then they do not intersect
    if tail1 != tail2:
        return False

    if len_1 > len_2:
        difference = len_1 - len_2
        return find_intersection(linked_list1.head, linked_list2.head, difference)

    else:
        difference = len2 - len_1
        return find_intersection(linked_list2, linked_list1, difference)

if __name__ == "__main__":
    # Initialize linked list 1
    linked_list1 = linked_list.initialize_linked_list()
    
    # Initialize linked list 2
    linked_list2 = linked_list.LinkedList()

    linked_list2.head = linked_list1.head.nextnode.nextnode.nextnode.nextnode
    linked_list2.insert(10)
    linked_list2.insert(8)

    linked_list1.print_list()
    linked_list2.print_list()
    print find_intersection_helper(linked_list1, linked_list2)
