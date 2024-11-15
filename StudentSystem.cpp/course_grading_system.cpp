#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Course {
public:
    string courseName;
    unordered_map<string, int> grades; // exam type, its score

    Course() {}
    Course(string name) : courseName(name) {}
};

class Student {
public:
    string name;
    vector<Course> courses;  // Use vector for flexibility

    Student(string studentName) : name(studentName) {
        courses.push_back(Course("Math"));
        courses.push_back(Course("Science"));
        courses.push_back(Course("Arts"));
    }
};

void printGradesForStudent(const Student& student) {
    cout << "Grades for " << student.name << ":\n";
    for (const auto& course : student.courses) {
        cout << "Course: " << course.courseName << "\n";
        for (const auto& grade : course.grades) {
            cout << "  " << grade.first << ": " << grade.second << "\n";
        }
    }
}

void printGradesForCourse(const vector<Student>& students, const string& courseName) {
    cout << "Grades for " << courseName << ":\n";
    for (const auto& student : students) {
        for (const auto& course : student.courses) {
            if (course.courseName == courseName) {
                for (const auto& grade : course.grades) {
                    cout << "  " << grade.first << ": " << grade.second << "\n";
                }
            }
        }
    }
}

void printGradesByExamType(const vector<Student>& students, const string& examType) {
    cout << "Grades for " << examType << ":\n";
    for (const auto& student : students) {
        for (const auto& course : student.courses) {
            if (course.grades.find(examType) != course.grades.end()) {
                cout << student.name << " - " << course.courseName << ": " 
                     << course.grades.at(examType) << "\n";
            }
        }
    }
}

void printPassingGrades(const vector<Student>& students, int passingScore) {
    cout << "Passed (Grade >= " << passingScore << "):\n";
    for (const auto& student : students) {
        for (const auto& course : student.courses) {
            for (const auto& grade : course.grades) {
                if (grade.second >= passingScore) {
                    cout << student.name << " - " << course.courseName << " - " 
                         << grade.first << ": " << grade.second << "\n";
                }
            }
        }
    }
}

int main() {
    // Create sample Students
    Student Ahmet("Ahmet");
    Ahmet.courses[0].grades["Midterm"] = 85; // Math
    Ahmet.courses[1].grades["Final"] = 90;  // Science
    Ahmet.courses[2].grades["Project"] = 5; // Arts
    Ahmet.courses[0].grades["Final"] = 85;  // Math Final

    Student Ayse("Ayse");
    Ayse.courses[0].grades["Midterm"] = 85; // Math
    Ayse.courses[2].grades["Final"] = 90;   // Arts

    // Array of all students
    vector<Student> students = {Ahmet, Ayse};

    // Example queries
    printGradesForStudent(Ahmet);
    printGradesForCourse(students, "Math");
    printGradesByExamType(students, "Final");
    printPassingGrades(students, 90);

    return 0;
}