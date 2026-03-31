def phone_data_usage(days):
    total = 0
    high_days = 0

    for i in range(1, days + 1):
        daily_usage = 2 + (i - 1) * 0.5
        total += daily_usage
        if daily_usage >=4:
         high_days += 1
    return total, high_days
total, high_days = phone_data_usage(10)
print(total)
print(high_days)
    