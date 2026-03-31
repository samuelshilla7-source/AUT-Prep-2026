def get_student_data():
    students = {}
    
    while True:
        entry = input("Enter student name (or done): ")

        if entry == "done":
            break

        name_entry = entry
        
        
        
        try:
            if name_entry not in students:
                students[name_entry] = { "score": 0, "age": 0 }
                score_entry = input(f"Enter score for {name_entry}: ")
                age_entry = input(f"Enter age for {name_entry}: ")
                new_score = int(score_entry)
                new_age = int(age_entry)
                print(f"Adding new student {name_entry} with score {new_score} and age {new_age}.")
                students[name_entry] = {"score": new_score, "age": new_age}

            else:
                choice = input(f"Student exists. Update data? (y/n): ")

                if choice == "y":
                    field = input(f"What field do you want to update? (score/age/both): ")
                    if field == "both":
                        score_entry = input(f"Enter new score for {name_entry}: ")
                        age_entry = input(f"Enter new age for {name_entry}: ")
                        new_score = int(score_entry)
                        new_age = int(age_entry)
                        students[name_entry] = {"score": new_score, "age": new_age}
                        print(f"Updated {name_entry}'s score to {new_score} and age to {new_age}.")

                    elif field == "score":
                        score_entry = input(f"Enter new score for {name_entry}: ")
                        new_score = int(score_entry)
                        students[name_entry]["score"] = new_score
                        print(f"Updated {name_entry}'s score to {new_score}.")

                    elif field == "age":
                        age_entry = input(f"Enter new age for {name_entry}: ")
                        new_age = int(age_entry)
                        students[name_entry]["age"] = new_age
                        print(f"Updated {name_entry}'s age to {new_age}.")
                    else:
                        print("Invalid field. Please enter 'score' or 'age' or 'both'.")
                else:
                    continue
                   
            

        except ValueError:
            print(f"Invalid input. Please enter numbers for score and age for the following student {name_entry}.")

    return students


def analyze_student_data(students):
    scores = [data["score"] for data in students.values()]
    ages = [data["age"] for data in students.values()]

    for student_name, data in students.items():
        print(f"Student: {student_name}, Score: {data['score']}, Age: {data['age']}")
        
    total_score = sum(scores)
    average_score = total_score / len(scores) if scores else 0
    olddest_age_name = max(students, key=lambda name: students[name]["age"]) if students else None
    olddest_age = students[olddest_age_name]["age"] if olddest_age_name else None
    print(f"Oldest student: {olddest_age_name} with age {olddest_age}.")
    lowest_age_name = min(students, key=lambda name: students[name]["age"]) if students else None
    lowest_age = students[lowest_age_name]["age"] if lowest_age_name else None
    print(f"Youngest student: {lowest_age_name} with age {lowest_age}.")

    
    return total_score, average_score, olddest_age, olddest_age_name, lowest_age, lowest_age_name
   

students = get_student_data()

if not students:
    print("No student data was entered.")

else:
    total, average, oldest, oldest_name, youngest, youngest_name = analyze_student_data(students)
    print(f"Total Score: {total}")    
    print(f"Average Score: {average}")
    print(f"Oldest Person: {oldest_name} with age {oldest}")
    print(f"Youngest Person: {youngest_name} with age {youngest}")