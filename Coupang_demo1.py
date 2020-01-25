
v = [[1, 4], [3, 4], [3, 10]]
# v = [[1, 1], [2, 2], [1, 2]]


def solution(v):
    answer = []
    x_list = []
    y_list = []
    for x, y in v:
        if x in x_list:
            x_list.remove(x)
        else:
            x_list.append(x)
        if y in y_list:
            y_list.remove(y)
        else:
            y_list.append(y)
    answer = [x_list[0], y_list[0]]
    return answer

print(solution(v))
