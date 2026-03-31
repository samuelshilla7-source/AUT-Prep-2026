def average_score(a, b, c):
    return (a + b + c) / 3
def recommend_plan(a,b,c):
    avg = average_score(a,b,c)
    if avg >= 10:
        return "Heavy User"
    elif avg >= 5:
        return "Moderate User"
    else:
        return "Light User"
print(recommend_plan(12,10,9))
print(recommend_plan(4,5,3))
print(recommend_plan(10,5,7))



