def get_data():
    student = {}

    while True:
        choice = input("1.Add student" "\n"
        "2.Update student" "\n"
        "3.View student" "\n"
        "4.Delete student" "\n"
        "5.View all students" "\n"
        "6.Exit"  )

        

        try:
            choice = int(choice)
            if choice == 1:
                name = input("Enter student name: ")
                if name in student:
                    print(f"{name} already exists. Please choose a different name or 2 to update the student.")
                    continue
                else:
                 
                 score = int(input(f"Enter {name}'s score: "))
                 age = int(input(f"Enter {name}'s age: "))
                 student[name] = {"score": score, "age": age}
                 print(f"Added {name} with score {score} and age {age}.")

            elif choice == 2:
                name = input("Enter student name to update: ")

                if name in student:
                    field = input("What field do you want to update? (score/age/both): ")

                    if field == "both":
                        new_score = int(input(f"Enter new score for {name}: "))
                        new_age = int(input(f"Enter new age for {name}: "))
                        student[name] = {"score": new_score, "age": new_age}
                        print(f"Updated {name}'s score to {new_score} and age to {new_age}.")

                    elif field == "score":
                        new_score = int(input(f"Enter new score for {name}: "))
                        student[name]["score"] = new_score
                        print(f"Updated {name}'s score to {new_score}.")

                    elif field == "age":
                        new_age = int(input(f"Enter new age for {name}: "))
                        student[name]["age"] = new_age
                        print(f"Updated {name}'s age to {new_age}.")

                    else:
                        print("Invalid field. Please enter 'score' or 'age' or 'both'.")

                else:
                    print(f"{name} not found.")

            elif choice == 3:
                name = input("Enter student name to view: ")
                if name in student:
                    print(f"{name}: Score - {student[name]['score']}, Age - {student[name]['age']}")
                else:
                    print(f"{name} not found.")

            elif choice == 4:
                name = input("Enter student name to delete: ")
                if name in student:
                    print(f"Are you sure you want to delete {name}? (y/n): ")
                    if input() == "y":
                        del student[name]
                        print(f"{name} has been deleted.")
                    else:
                        print(f"Deletion of {name} cancelled.")
                else:
                    print(f"{name} not found.")

            elif choice == 5:
                if not student:
                    print("No students found.")
                else:
                 for name, info in student.items():
                    print(f"{name}: Score - {info['score']}, Age - {info['age']}")

            elif choice == 6:
                break

            else:
                print("Invalid choice. Please enter a number between 1 and 6.")
        except ValueError:
            print("Invalid input. Please enter a number.")
            continue

    return student

def main():
    students = get_data()
    print("Final student data:")
    for name, info in students.items():
        print(f"{name}: Score - {info['score']}, Age - {info['age']}")

    return students

students = main()