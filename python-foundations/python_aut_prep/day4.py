sum_hours = 0
heavy_study = 0

for day in range(1,15):
    hours = day * 1
    print(f"Day {day}: Studied for {hours} hours")
    sum_hours += hours
    if hours >= 10:
        heavy_study += 1
average_hours = sum_hours / 14
print(f"Heavy study days: {heavy_study}")
print(f"Average study hours per day: {average_hours}")