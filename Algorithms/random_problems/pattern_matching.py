# -*- coding: UTF-8 -*-

'''
	Implement a regular expression function isMatch that supports the '.' and '*' symbols. The function 
	receives two strings - text and pattern - and should return true if the text matches the pattern as a 
	regular expression. For simplicity, assume that the actual symbols '.' and '*' do not appear in the 
	text string and are used as special symbols only in the pattern string.

	In case you aren’t familiar with regular expressions, the function determines if the text and 
	pattern are the equal, where the '.' is treated as a single a character wildcard (see third example), 
	and '*' is matched for a zero or more sequence of the previous letter (see fourth and fifth examples). 
	For more information on regular expression matching, see the Regular Expression Wikipedia page.

	Explain your algorithm, and analyze its time and space complexities.

	Examples:

	input:  text = "aa", pattern = "a"
	output: false

	input:  text = "aa", pattern = "aa"
	output: true

	input:  text = "abc", pattern = "a.c"
	output: true

	input:  text = "abbb", pattern = "ab*"
	output: true

	input:  text = "abcd", pattern = "a*c."
	output: true

'''
def is_match(text, pattern):
	if not text and not pattern:
		return True

	if not pattern or not text:
		return False

	if pattern == "*":
		return True

	if pattern[0] == ".":
		return is_match(text[1:], pattern[1:])

	if pattern[0] == "*":
		while(text[0] != pattern[1] and pattern[1] != '.'):
			text = text[1:]
		return is_match(text[1:], pattern[2:])

	else:
		if text[0] != pattern[0]:
			return False
		else:
			return is_match(text[1:], pattern[1:])
		
if __name__ == "__main__":
	print is_match("abcd", "a*c.")
	print is_match("abbb", "ab*")
	print is_match("abc", "a.c")
	print is_match("aa", "a")
	print is_match("ab", "ab")