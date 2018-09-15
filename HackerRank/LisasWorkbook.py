# https://www.hackerrank.com/challenges/lisa-workbook/problem

def workbook(n, k, a):
    num_special = 0
    cur_page = 1

    for i in range(len(a)):

        num_probs_in_chapter = a[i]
        num_full_pages, leftover_probs = divmod(num_probs_in_chapter, k)

        total_pages = num_full_pages + (1 if leftover_probs else 0)
        problems_in_chapter=iter(range(1, a[i] + 1))

        for _ in range(total_pages):
            probs_on_page = [next(problems_in_chapter, None) for _ in range(k)]
            if cur_page in probs_on_page:
                num_special += 1
            cur_page += 1
    return num_special






n = 10
k = 5
arr = [3, 8, 15, 11, 14, 1, 9, 2, 24, 31]

print(workbook(n, k, arr))
