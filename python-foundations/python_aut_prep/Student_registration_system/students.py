class Student:
    def __init__(self, name, student_id):
        self.name = name
        self.student_id = student_id
        self.courses = []

    def register_course(self, course):
        if course in self.courses:
            return False
        self.courses.append(course)
        return True

    def drop_course(self, course):
        if course not in self.courses:
            return False
        self.courses.remove(course)
        return True