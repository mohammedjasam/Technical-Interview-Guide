import math
# half the number of pages from front |
# half the number of pages to last and then subtract the number of pages to the current page form it
def pageCount(n, p):
    return min(p//2, n//2 - p//2)

print(pageCount(7, 1))

# TAGS: Page turning, first, last, book, minimum
