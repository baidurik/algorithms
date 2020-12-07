import random

for i in range(1, 101):
    with open('sorting_tests/input' + str(i), 'w') as f:
        n = random.randint(1, 100000)
        f.write(str(n) + '\n')
        for j in range(n):
            number = random.randint(-100000, 100000)
            f.write(str(number) + ' ')