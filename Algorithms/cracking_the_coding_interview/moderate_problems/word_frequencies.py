# find frequency word
# in book 
	

def find_frequency(book, word):
	count = 0
	for each_word in book:
		if each_word == word:
			count += 1