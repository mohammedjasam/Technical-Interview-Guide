# https://www.hackerrank.com/challenges/taum-and-bday/problem

# See if the price of conversion is justified, if so then return the one that you want to convert.
def CanWeConvert(bc, wc, z):
    if bc + z < wc:
        return 1
    if wc + z < bc:
        return 2
    else:
        return 0

# if conversion is possible then based on the color to convert to, calculate the cost
def taumBday(b, w, bc, wc, z):
    convert = CanWeConvert(bc, wc, z)
    if convert == 1:
        return (bc + z) * w + bc * b
    elif convert == 2:
        return (wc + z) * b + wc * w
    else:
        return b * bc + w * wc

print(taumBday(5, 9, 2, 4, 1))
