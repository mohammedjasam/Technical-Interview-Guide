# -*- coding: UTF-8 -*-

# Program to find most/least occuring element in a string

def count(s, count_dict):

	for i in s:
		if i not in count_dict:
			count_dict[i] = 1
		else:
			count_dict[i] += 1

	max_value = 0
	max_element = 0
	for i in count_dict:
		if count_dict[i] > max_value:
			max_value = count_dict[i]
			max_element = i

	return max_element

s = "aabbccaaabbmmmlllssssaaa"

count_dict = {}

print count(s, count_dict)
