password = "aut2026"

count = 0
while True:
    user_input = input("Enter the password: ")
    if user_input == password:
        print("Access granted.")
        break
    else:
        print("Wrong password. Attempts left:", 3 - (count + 1))
    count += 1
    if count == 3:
        print("Account Locked.")
        break
    
