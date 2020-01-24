class Value:
    def __init__(self, n, str_list):
        self.n = n
        self.str_list = str_list

    def solve(self):
        temp = list(self.str_list[0])
        for item in self.str_list:
            for i in range(len(item)):
                if temp[i] != item[i]:
                    temp[i] = '?'
        return ''.join(temp)


n = int(input())
str_list = []
for _ in range(n):
    str_list.append(input())
v = Value(n, str_list)
print(v.solve())
