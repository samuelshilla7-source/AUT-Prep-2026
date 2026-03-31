sales = {
    "Mon": 20000,
    "Tue": 35000,
    "Wed": 15000,
    "Thu": 40000,
    "Fri": 30000
}

def weekly_sales_report(sales):
    total = 0
    highest_amount = 0
    lowest_amount = 0
    big_days = {}
    highest_day = ""
    lowest_day = ""

    for day, amount in sales.items():
        total += amount
        if amount > highest_amount:
            highest_amount = amount
            highest_day = day
        if lowest_amount == 0 or amount < lowest_amount:
            lowest_amount = amount
            lowest_day = day
        if amount >= 30000:
            big_days[day] = amount

    average_sales = total / len(sales)
    return total, average_sales, highest_day, highest_amount, lowest_day, lowest_amount, big_days

total, average, high_day, high_amount, low_day, low_amount, big_days = weekly_sales_report(sales)
print(f"Total Sales: {total}")
print(f"Average Daily Sales: {average}")
print(f"Highest Sales: {high_day} with {high_amount}")
print(f"Lowest Sales: {low_day} with {low_amount}")
print("Big Sales Days (>= 30000):", big_days)