def reverse_num(num: int) -> int:
    res = 0
    while num > 0:
        res = res * 10 + num % 10
        num //= 10
    
    return res

def is_palindrome(num: int) -> bool:
    return num == reverse_num(num)

if __name__ == "__main__":
    res = 0

    a = 999
    while a >= 100:
        if a % 11 == 0:
            b = 999
            db = 1
        else:
            b = 990
            db = 11
        
        while b >= a:
            if (a * b <= res): 
                break

            if is_palindrome(a * b):
                res = a * b
            
            b -= db
        a -= 1
    
    print(res)