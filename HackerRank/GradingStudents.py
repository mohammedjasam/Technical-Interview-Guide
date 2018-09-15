import math
def gradingStudents(grades):
    result = []
    res = -1
    for grade in grades:
        if grade < 38:
            result.append(grade)
            res = grade
        elif grade >= 38 and grade <= 40:
            result.append(40)
            res = 40
        elif grade > 40:
            quotient = grade / 5
            diff = (math.ceil(quotient) * 5) - grade
            if diff <= 2:
                result.append(grade + diff)
                res = grade + diff
            else:
                result.append(grade)
                res = grade
        print(res)
    return result

gradingStudents([73, 67, 38, 33])
