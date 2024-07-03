# l = []
# print(l)
# l = list("welcome")
# print(l)
# l = [1, 2, 3, 4, 2.4, "hii", (17, 22), ["qwerty", 9, 8, 7]]
# print(l)
# print(l[6])
# print(l[-4])
# print(l[6][0])
# print(l[-2][1])
# print(l[-1][1])
# print(l[-1][-2])
# print(l[-1])

# write a program to enter list from user to print sum of all elements
# l = [11, 22, 33, 44, 55]
# total = 0
# for i in range(len(l)):
#     total += l[i]
# print("SUM = ", total)

# l1 = [1, 2, 3, 4]
# print(id(l1))
# print(id(l1[0]))
# print(l1)
# l1[0] = 8
# print(id(l1))
# print(id(l1[0]))
# print(l1)

# l2 = [5, 6, 7]
# print(l1+l2)
# print(7 in l1)
# print(7 in l2)
# print(7 in (l1+l2))
# print(10 in (l1+l2))
# print(l1[::])
# print(l1[::-1])
# print((l1+l2)[::-1])
# print((l1+l2)[2:6])
# print((l1+l2)[1:6:2])
# print((l1+l2)[6:2:-2])
# print((l1+l2)[-2:-1])
# print((l1+l2)[-1:0:-2])

a = [1, 2, 3, ["A", "B", "C"]]
a.append(4)
a.append("Hello")
a.append([5, 6, 7, "python"])
a.extend([9, 8, 7])
a.extend(["a", "b", "c"])
a.insert(2, 100)
a.insert(-5, 200)
a.insert(30, 24)
a.insert(25, 42)
print(a)
print(a[4].count("A"))
print(a.count("b"))
