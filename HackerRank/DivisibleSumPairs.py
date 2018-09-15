# The idea is that you separate elements into buckets depending on their mod k. For example, you have the elements: 1 3 2 6 4 5 9 and k = 3
#
# mod 3 == 0 : 3 6 9
# mod 3 == 1 : 1 4
# mod 3 == 2 : 2 5
# Now, you can make pairs like so: Elements with mod 3 == 0 will match with elements with (3 - 0) mod k = 0, so other elements in the mod 3 == 0 list, like so:
#
# (3, 6) (3, 9) (6, 9)
# There will be n * (n - 1) / 2 such pairs, where n is length of the list, because the list is the same and i != j. Elements with mod 3 == 1 will match with elements with (3 - 1) mod k = 2, so elements in the mod 3 == 2 list, like so:
#
# (1, 2) (1, 5) (4, 2) (4, 5)
# There will be n * k such elements, where n is the length of the first list, and k of the second.
#
# Because you don't need to print the actual pairs, you need to store only the number of elements in each list.
# https://www.hackerrank.com/challenges/divisible-sum-pairs/forum

def divisibleSumPairs(n, k, ar):
    nums = [0] * k
    count = 0
    for ele in ar:
        modu = ele % k
        print(f"{ele} {modu} {count} {nums} - after modu")
        count += nums[(k - modu) % k]
        print(f"{ele} {modu} {count} {nums} - after count+=")
        nums[modu] += 1
        print(f"{ele} {modu} {count} {nums} - after nums+=")
        print("-----------------------")
        print(count)
        print("-----------------------\n")
    return count

print(divisibleSumPairs(7, 3, [1, 3, 2, 6, 4, 5, 9]))
