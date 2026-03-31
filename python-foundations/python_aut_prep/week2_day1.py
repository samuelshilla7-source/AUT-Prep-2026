marks = [45, 78, 62, 90, 55, 38, 84]
total = 0
passed_students = 0
failed_students = 0

for mark in marks:
    total += mark
    if mark >= 50:
        passed_students += 1
    else:
        failed_students += 1
average = total / len(marks)
print("Total Marks:", total)
print("Average Marks:", average)
print("Passed Students:", passed_students)
print("Failed Students:", failed_students)