# -*- coding: UTF-8

'''
    You are given an array of characters arr that consists of sequences of characters separated by space characters.
    Each space-delimited sequence of characters defines a word.

    Implement a function reverseWords that reverses the order of the words in the array in the most efficient manner.
'''

arr = [ 'p', 'e', 'r', 'f', 'e', 'c', 't', ' ',
        'm', 'a', 'k', 'e', 's', ' ',
        'p', 'r', 'a', 'c', 't', 'i', 'c', 'e' ]

def reverse(arr, st, end):
    while st < end:
        arr[st], arr[end] = arr[end], arr[st]
        end -= 1
        st += 1

def reverse_arr(arr):
    arr = arr[::-1] # this will reverse the string and copy its element to a new string
    st_index = 0
    length = len(arr)

    for i, val in enumerate(arr):
        if val == ' ':
            end_index = i-1
            reverse(arr, st_index, end_index)
            st_index = end_index + 2

        if i == length - 1:
            reverse(arr, st_index, length-1)
   
    return arr

print reverse_arr(arr)
print reverse_arr(['  ', '  ', '  '])
