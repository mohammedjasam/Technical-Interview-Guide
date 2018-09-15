def timeConversion(s):
    hh = s[0:2]
    mm = s[3:5]
    ss = s[6:8]
    AMorPM = s[8:10]
    if AMorPM == "PM":
        if int(hh) < 12:
            hh = str(int(hh) + 12)
    else:
        if int(hh) == 12:
            hh = str("00")
    return hh + ":" + mm + ":" + ss






print(timeConversion("12:05:45AM"))
