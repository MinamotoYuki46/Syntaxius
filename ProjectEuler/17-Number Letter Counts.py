UNITS = {
    0: "zero", 1: "one", 2: "two", 3: "three", 4: "four", 5: "five",
    6: "six", 7: "seven", 8: "eight", 9: "nine"
}
TEENS = {
    10: "ten", 11: "eleven", 12: "twelve", 13: "thirteen", 14: "fourteen",
    15: "fifteen", 16: "sixteen", 17: "seventeen", 18: "eighteen", 19: "nineteen"
}
TENS = {
    20: "twenty", 30: "thirty", 40: "forty", 50: "fifty",
    60: "sixty", 70: "seventy", 80: "eighty", 90: "ninety"
}

def number_to_words(n: int) -> str:
    if n == 1000:
        return "one thousand"
    words = []
    hundreds = n // 100
    remainder = n % 100

    if hundreds:
        words.append(UNITS[hundreds])
        words.append("hundred")
        if remainder:
            words.append("and")

    if remainder:
        if remainder < 10:
            words.append(UNITS[remainder])
        elif 10 <= remainder < 20:
            words.append(TEENS[remainder])
        else:
            tens_part = remainder // 10 * 10
            units_part = remainder % 10
            words.append(TENS[tens_part])
            if units_part:
                words.append(UNITS[units_part])

    return " ".join(words)

def count_letters_in_range(a: int, b: int) -> int:
    total = 0
    for n in range(a, b+1):
        w = number_to_words(n)
        cleaned = w.replace(" ", "").replace("-", "")
        total += len(cleaned)
    return total

if __name__ == "__main__":
    result = count_letters_in_range(1, 1000)
    print(result)