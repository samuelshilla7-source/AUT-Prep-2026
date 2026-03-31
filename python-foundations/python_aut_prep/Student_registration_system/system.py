from Student_registration_system.students import Student
from Student_registration_system.courses import Course

class RegistrationSystem:
    def __init__(self):
        self.students = {}
        self.courses = {}

    def add_student(self, name, student_id):
        if student_id in self.students:
            print("Student already exists")
            return
        self.students[student_id] = Student(name, student_id)

    def add_course(self, course_code, title, max_students):
        if course_code in self.courses:
            print("Course already exists")
            return
        self.courses[course_code] = Course(course_code, title, max_students)

    def register_student_to_course(self, student_id, course_code):
        student = self.students.get(student_id)
        course = self.courses.get(course_code)

        if not student:
            print("Student not found")
            return
        if not course:
            print("Course not found")
            return
        if course in student.courses:
            print("Student already registered in this course")
            return
        if course.is_full():
            print("Course is full")
            return

        student.register_course(course)
        course.add_student(student)
        print(f"{student.name} registered to {course.course_code}")


