with open("/mnt/hyperdrive/Code Project/Syntaxius/ProjectEuler/0022_names.txt", "r") as file:
    names = [name.strip('" \n\r\t') for name in file.read().split(',')]

names.sort()
total_score = 0

for pos, name in enumerate(names, start=1):
    name_score = 0

    for char in name:
        name_score += ord(char) - ord('A') + 1

    total_score += pos * name_score


print(total_score)
