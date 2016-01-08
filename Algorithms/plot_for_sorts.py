import matplotlib.pyplot as plt
import math

x = []
y_1 = []
y_2 = []
y_3 = []
f = open('result.txt')
for line in f:
    x1, y1, y2 = line.split()
    x.append([int(x1)])
    y_1.append([int(y1)])
    y_2.append([int(y2)])
    y_3.append((int(x1)*math.log(int(x1), 2)))
plt.plot(x, y_2)
plt.plot(x, y_3)
plt.show()
