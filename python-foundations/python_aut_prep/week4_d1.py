def get_data():
    data = {}

    while True:
        entry = input("Enter student name (or done): ")

        if entry == "done":
            break

        name = entry
        
        
        try:
            old_score = data.get(name) if name in data else None

            if name not in data:
                score_entry = input(f"Enter score for {name}: ")
                new_score = int(score_entry)
                print(f"Adding new student {name} with score {new_score}.")
                data[name] = new_score

            else:
                choice = input(f"Student exists. Update score? (y/n): ")

                if choice == "y":
                    score_entry = input(f"Enter score for {name}: ")
                    new_score = int(score_entry)
                    data[name] = new_score
                    print(f"Updated {name}'s score to {new_score}.")
                    
                else:
                    print(f"Keeping existing score for {name}: {old_score}.")
                    continue

        
           

        except ValueError:
            print("Invalid score. Please enter a number.")

    return data

def analyze_data(data):
    score = list(data.values())

    for name, scores in data.items():
        print(f"Student: {name}, Score: {scores}")
        
    total_score = sum(score)
    average_score = total_score / len(score) if score else 0
    highest_name = max(data, key=data.get) if data else None
    highest_score = data[highest_name] if highest_name else None
    lowest_name = min(data, key=data.get) if data else None
    lowest_score = data[lowest_name] if lowest_name else None
    
    return total_score, average_score, highest_score, lowest_score


data = get_data()

if not data:
    print("No data was entered.")
else:
    total, average, highest, lowest = analyze_data(data)
    print("Total Score:", total)
    print("Average Score:", average)
    print("Highest Score:", highest)
    print("Lowest Score:", lowest)