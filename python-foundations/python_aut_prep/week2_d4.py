airtime = {
    "Mon": 3000,
    "Tue": 5000,
    "Wed": 2000,
    "Thu": 7000,
    "Fri": 4500,
    "Sat": 8000,
    "Sun": 2500
}
total_airtime = 0
highest_day = 0
lowest_day = 0
expensive_days = {}

high_amount = ""
low_amount = ""

for day, amount in airtime.items():
    total_airtime += amount
    if amount >= 5000:
        expensive_days[day] = amount
    if highest_day == 0 or amount > highest_day:
        highest_day = amount
        high_amount = day
    if lowest_day == 0 or amount < lowest_day:
        lowest_day = amount
        low_amount = day

average_airtime = total_airtime / len(airtime)

print("Total Airtime:", total_airtime)
print("Average Airtime:", average_airtime)
print("Highest Day:", high_amount, "with", highest_day)
print("Lowest Day:", low_amount, "with", lowest_day)
print("Expensive Days:", expensive_days)