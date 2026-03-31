class Course:
    def __init__(self, course_code, title, max_students):
        self.course_code = course_code
        self.title = title
        self.max_students = max_students
        self.students = []

    def is_full(self):
        return len(self.students) >= self.max_students

    def add_student(self, student):
        if student in self.students:
            return False
        if self.is_full():
            return False
        self.students.append(student)
        return True

    def remove_student(self, student):
        if student not in self.students:
            return False
        self.students.remove(student)
        return True