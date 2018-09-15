# -*- coding: UTF-8 -*-

# Program to check if two strings are anagrams of each other

def count_characters(str1, count_dict):

	for i in str1:
		if i not in count_dict:
			count_dict[i] = 1
		else:
			count_dict[i] += 1

	return count_dict

def check_anagrams(str1, str2):

	count_dict = count_characters(str1, {})

	for i in str2:
		if i in count_dict and count_dict[i] > 0:
			count_dict[i] -= 1
		else:
			return False

	for i in count_dict:
		if count_dict[i] != 0:
			return False

	return True

print check_anagrams("aabbrd", "rabab")