hoar_sum = 0
shell_sum = 0
heap_sum = 0
intro_sum = 0
for i in range(1, 101):
    inp_file = open('sorting_tests/input' + str(i), 'r')
    n = int(inp_file.readline())
    arr = list(map(int, inp_file.readline().split()))
    arr.sort()
    hoar_file = open('hoar_test/output' + str(i), 'r')
    hoar_arr = list(map(int , hoar_file.readline().split()))
    ok = True
    for j in range(n):
        if hoar_arr[j] != arr[j]:
            print(hoar_arr[j], arr[j])
            ok = False
            break
    if ok:
        print(f"hoar test {i} OK")
    else:
        print(f"hoar test {i} error")
        break
    shell_file = open('shell_test/output' + str(i), 'r')
    shell_arr = list(map(int , shell_file.readline().split()))
    ok = True
    for j in range(n):
        if shell_arr[j] != arr[j]:
            ok = False
            break
    if ok:
        print(f"shell test {i} OK")
    else:
        print(f"shell test {i} error")
        break
    heap_file = open('heap_test/output' + str(i), 'r')
    heap_arr = list(map(int , heap_file.readline().split()))
    ok = True
    for j in range(n):
        if heap_arr[j] != arr[j]:
            ok = False
            break
    if ok:
        print(f"heap test {i} OK")
    else:
        print(f"heap test {i} error")
        break
    intro_file = open('intro_test/output' + str(i), 'r')
    intro_arr = list(map(int , intro_file.readline().split()))
    ok = True
    for j in range(n):
        if intro_arr[j] != arr[j]:
            print(intro_arr[j], arr[j])
            ok = False
            break
    if ok:
        print(f"intro test {i} OK")
    else:
        print(f"intro test {i} error")
        break
    hoar_time = float(hoar_file.readline())
    shell_time = float(shell_file.readline())
    heap_time = float(heap_file.readline())
    intro_time = float(intro_file.readline())
    hoar_sum += hoar_time
    shell_sum += shell_time
    heap_sum += heap_time
    intro_sum += intro_time
    print(f'hoar time: {hoar_time} s\tshell time: {shell_time} s\theap time: {heap_time} s\tintro time: {intro_time} s')
print('\n\n')
print(f'hoar summary time: {hoar_sum} s\nshell summary time: {shell_sum} s\nheap summary time: {heap_sum} s\nintro summary time: {intro_sum} s')