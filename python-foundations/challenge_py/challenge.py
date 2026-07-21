def main():
    student = {}

    name = student[name] = input("Enter student's name: ")
    scores = student[name][scores] = int(input("Enter students scores: "))


def get_average(student):

    sum = 0
    for scores in student.values():

        sum += scores
        average = sum/len(scores)

    return average

def get_grade(average):

    if average >= 90:
        print("A")
    elif average >= 80:
        print("B")
    elif average >= 70:
        print("C")
    elif average >= 60:
        print("D")
    else:
        print("F")

def print_all(student):

    for i, j in student.items():
        print("---Grade Report---" )