def get_numbers():
    numbers = []
    

    while True:
        entry = input("Enter a number (or done): ")
        
        if entry == "done":
            break

        try:
            numbers.append(int(entry))
        except ValueError:
            print("Invalid input. Please enter a number (or done) ")
        
         
    return numbers

def mathematical_operations(numbers):
    total = sum(numbers)
    average = total / len(numbers) if numbers else 0
    highest_number = max(numbers) if numbers else None
    lowest_number = min(numbers) if numbers else None

    return total, average, highest_number, lowest_number

numbers = get_numbers()

if not numbers:
    print("No numbers were entered.")
else:
    total, average, highest_number, lowest_number = mathematical_operations(numbers)
    print("Total:", total)
    print("Average:", average)
    print("Maximum:", highest_number)
    print("Minimum:", lowest_number)