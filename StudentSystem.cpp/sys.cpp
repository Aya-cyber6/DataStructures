#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

// Class to represent a Grade for a specific exam type
class Grade {
public:
    std::string examType;
    int score;

    Grade(const std::string &examType, int score) : examType(examType), score(score) {}

    bool isPassed(int passingScore) const {
        return score >= passingScore;
    }
};

// Class to represent a Course, containing multiple grades
class Course {
public:
    std::string courseName;
    std::vector<Grade> grades;

    Course(const std::string &courseName) : courseName(courseName) {}

    void addGrade(const Grade &grade) {
        grades.push_back(grade);
    }
};

// Class to represent a Student, containing multiple courses
class Student {
public:
    int studentId;
    std::string name;
    std::vector<Course> courses;

    Student(int studentId, const std::string &name) : studentId(studentId), name(name) {}

    void addCourse(const Course &course) {
        courses.push_back(course);
    }
};

// Class to manage and operate on all students
class SchoolData {
private:
    std::vector<Student> students;

public:
    void addStudent(const Student &student) {
        students.push_back(student);
    }

    // Retrieve a student by ID
    Student* getStudentById(int Id) {
        for (auto &student : students) {
            if (student.studentId == Id) {
                return &student;
            }
        }
        return nullptr;
    }

    // Get grades for a specific student
    std::vector<Grade> getGradesByStudent(int studentId) {
        std::vector<Grade> grades;
        Student* student = getStudentById(studentId);
        if (student) {
            for (const auto &course : student->courses) {
                grades.insert(grades.end(), course.grades.begin(), course.grades.end());
            }
        }
        return grades;
    }

    // Get all grades for a specific course
    std::vector<Grade> getGradesByCourse(const std::string &courseName) {
        std::vector<Grade> grades;
        for (const auto &student : students) {
            for (const auto &course : student.courses) {
                if (course.courseName == courseName) {
                    grades.insert(grades.end(), course.grades.begin(), course.grades.end());
                }
            }
        }
        return grades;
    }

    // Get grades by exam type across all students
        std::vector<Grade> getGradesByExamType(const std::string &examType) {
        std::vector<Grade> grades;
           for (const auto &student : students){
            for (const auto &course : student.courses){
              for (const auto &grade : course.grades){
                if (grade.examType == examType){
                     grades.push_back(grade);
                }        
            }
            }
           }
         return grades;
    }

    // Get passed grades across all students for a given passing score
    std::vector<Grade> getPassedGrades(int passingScore) {
        std::vector<Grade> passedGrades;
        for (const auto &student : students) {
            for (const auto &course : student.courses) {
                for (const auto &grade : course.grades) {
                    if (grade.isPassed(passingScore)) {
                        passedGrades.push_back(grade);
                    }
                }
            }
        }
        return passedGrades;
    }
};

// Helper function to display grades
void displayGrades(const std::vector<Grade> &grades) {
    for (const auto &grade : grades) {
        std::cout << "Exam Type: " << grade.examType << ", Score: " << grade.score << '\n';
    }
}

// Example usage
int main() {
    SchoolData schoolData;

    // Adding a student and their courses and grades
    Student student1(1, "Alice");
    Course course1("Mathematics");
    course1.addGrade(Grade("Midterm", 85));
    course1.addGrade(Grade("Final", 90));
    student1.addCourse(course1);

    Course course2("Science");
    course2.addGrade(Grade("Midterm", 78));
    course2.addGrade(Grade("Final", 88));
    student1.addCourse(course2);

    schoolData.addStudent(student1);

    // Fetch and display grades by criteria
    std::cout << "Grades by Student (ID 1):\n";
    displayGrades(schoolData.getGradesByStudent(1));

    std::cout << "\nGrades by Course (Mathematics):\n";
    displayGrades(schoolData.getGradesByCourse("Mathematics"));

    std::cout << "\nGrades by Exam Type (Midterm):\n";
    displayGrades(schoolData.getGradesByExamType("Midterm"));

    std::cout << "\nPassed Grades (Passing Score 80):\n";
    displayGrades(schoolData.getPassedGrades(80));

    return 0;
}
