# -*- coding: UTF-8 

# Program to find the length of longest palindrome substring

def longest_palindrome(s):
	maxLength = 1

	start = 0

	# consider one by one every point as its center point of even and odd substring
	for k in range(1, len(s)):

		# considering all even length substrings with center as k and k-1
		low = k-1
		high = k

		while low >= 0 and high < len(s) and s[low] == s[high]:
			if high-low+1 > maxLength:
				maxLength = high-low+1
				start = low
			# expand the substring on both left and right side
			high += 1
			low -= 1

		# consider all odd length strings with center as k
		low = k-1
		high = k+1

		while low >= 0 and high < len(s) and s[low] == s[high]:
			if high-low+1 > maxLength:
				maxLength = high-low+1
				start = low

			high += 1
			low -= 1


	longest_substring = "".join(s[start:start+maxLength])

	print "longest palindromic substring", longest_substring

s = list("forgeeksskeegrof")

longest_palindrome(s)
