# Complete the libraryFine function below.
def libraryFine(d2, m2, y2, d1, m1, y1):
    if y2 <= y1:
        if y2<y1:
            return 0
        if m2 <= m1:
            if m2<m1:
                return 0
            if d2 <= d1:
                if d2<d1:
                    return 0
                return 0
            return (d2 - d1) * 15
        return (m2 - m1) * 500
    return 10000

print(libraryFine(2, 7, 1014, 1, 1, 1015))
