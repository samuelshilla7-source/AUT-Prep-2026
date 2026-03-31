total = 0
heavy_days = {}
count = 0

while True:
    entry = input("Enter hours (or done): ")

    if entry == "done":
        break

    number = int(entry)
    total += number
    count += 1
    if number <= 0 or number >= 12:
        print("Invalid input.")

    if number >= 6 and number <= 12:
        day = input("Enter the day of the week: ")
        heavy_days[day] = number

average = total / count if count > 0 else 0

print("Total hours:", total)
print("Average hours:", average)
print("Heavy study days:", heavy_days)

