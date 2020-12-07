import os
for i in range(1, 101):
    # print(i)
    os.popen(f'echo {i} | .\\a.exe')