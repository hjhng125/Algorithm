class Value:
    def __init__(self, n, a, b):
        self.n = n
        self.a = a
        self.b = b

    def solve(self):
        result = int()
        for i in range(self.n):
            result += (self.cal_max_b() * self.cal_min_a())
        return result

    def cal_max_b(self):
        index = self.b.index(max(b))
        return self.b.pop(index)

    def cal_min_a(self):
        index = self.a.index(min(a))
        return self.a.pop(index)


n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

V = Value(n, a, b)
print(V.solve())
