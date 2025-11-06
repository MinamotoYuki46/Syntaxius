date_mon = {
    "jan": 31,
    "feb": 28,
    "mar": 31,
    "apr": 30,
    "may": 31,
    "jun": 30,
    "jul": 31,
    "aug": 31,
    "sep": 30,
    "oct": 31,
    "nov": 30,
    "dec": 31
}

def leap_year(year: int) -> bool:
    if (year % 4  == 0):
        if (year % 100 != 0):
            return year & 400 == 0
        return True
    else:
        return False


if __name__ == '__main__':
    start = 365 % 7
    count = 0

    years = list(range(1901, 2000 + 1))

    for year in years:
        for month in date_mon:
            if start % 7 == 0:
                count += 1

            days_in_month = date_mon[month]
            if month == "feb" and leap_year(year):
                days_in_month += 1

            start += days_in_month

    print(count)



