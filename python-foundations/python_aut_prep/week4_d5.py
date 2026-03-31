import json

from datetime import datetime

def load_data(people_data, logs_data):

    try:
        with open(people_data,  "r") as file:
            people = json.load(file)
    except FileNotFoundError:
        people = {}

    try:
        with open(logs_data, "r") as file:
            logs = json.load(file)
    except FileNotFoundError:
        logs = []

    return people, logs

def save_data(people_data, people, logs_data, logs):

    with open(people_data, "w") as file:
        json.dump(people, file, indent=4)

    with open(logs_data, "w") as file:
        json.dump(logs, file, indent=4)

def add_log(logs, action, name):
    time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    logs.append({"time": time, "action": action, "name": name})
    return logs

def register_person(people,logs, filename, logs_data,):

    name = input("Enter person name: ")
    if name in people:
        print(f"{name} already exists. Please choose a different name or check-in the person.")
        return people
    
    else:
        role = input(f"Enter {name}'s role: ")
        people[name] = {"role": role, "visits": 0}
        logs = add_log(logs, "Registered", name)
        save_data(filename, people, logs_data, logs)
        print(f"Registered {name} with role {role} and 0 visits.")

    return people

def check_in_person(people, logs, filename, logs_data):

    name = input("Enter person name to check-in: ")
    if name in people:
        people[name]["visits"] += 1
        logs = add_log(logs, "Checked In", name)
        save_data(filename, people, logs_data, logs)
        print(f"Checked in {name}. Total visits: {people[name]['visits']}.")
    else:
        print(f"{name} not found. Please register the person first.")

    return people

def view_person(people):

    name = input("Enter person name to view: ")
    if name in people:
        print(f"{name}: Role - {people[name]['role']}, Visits - {people[name]['visits']}")
    else:
        print(f"{name} not found.")

def delete_person(people, logs, filename, logs_data):

    name = input("Enter person name to delete: ")
    if name in people:
        confirm = input(f"Are you sure you want to delete {name}? (y/n): ")
        if confirm == "y":
            del people[name]
            logs = add_log(logs, "Deleted", name)
            save_data(filename, people, logs_data, logs)
            print(f"Deleted {name}.")
        else:
            print("Deletion cancelled.")
    else:
        print(f"{name} not found.")

    return people

def view_all_people(people):
    
    if people:
        print("All registered people:")
        sorted_people = dict(sorted(people.items(), key=lambda item: item[1]['visits'], reverse=True))
        for name, info in sorted_people.items():
            print(f"{name}: Role - {info['role']}, Visits - {info['visits']}")
    else:
        print("No people registered.")
        


def get_data(people_data, logs_data):

    people, logs = load_data(people_data, logs_data)
    
    
    while True:

        choice = input("1.Register Person (name + role)" "\n"
                       "2.Check-In Person" "\n"
                       "3.View Person" "\n"
                       "4.Delete Person" "\n"
                       "5.View All People" "\n"
                       "6.View Activity History" "\n"
                       "7.Exit"  )
        
        try:
            choice = int(choice)

            if choice == 1:

                people = register_person(people,logs, people_data, logs_data)

            elif choice == 2:

                people = check_in_person(people, logs, people_data, logs_data)
                
            elif choice == 3:

                view_person(people)

            elif choice == 4:
                
                people = delete_person(people, logs, people_data, logs_data)

            elif choice == 5:
                
                view_all_people(people)

            elif choice == 6:

                print("Activity History:")
                sorted_logs = sorted(logs, key=lambda x: x['time'], reverse=True)
                for log in sorted_logs:

                    print(f"{log['time']} - {log['action']} - {log['name']}")

            elif choice == 7:

                print("Exiting the program.")

                

                break

            else:
                print("Invalid choice. Please enter a number between 1 and 6.")

        except ValueError:
            print("Invalid input. Please enter a number for choice and visits.")
    return people

def main(filename, logs_filename):
    people = get_data(filename, logs_filename)
    print("Final registered people:")
    for name, info in people.items():
        print(f"{name}: Role - {info['role']}, Visits - {info['visits']}")

    return people, logs_filename
people = main("people_data.json", "logs_data.json")