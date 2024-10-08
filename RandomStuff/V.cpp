#include <iostream>
#include <vector>
#include <map>
#include <string>

// Sınav türleri
enum class ExamType { MIDTERM, FINAL, MAKEUP, HOMEWORK, PROJECT, TERM_PROJECT };

// Sınav/Ödev bilgilerini saklamak için struct
struct Grade {
    ExamType examType;
    double score;
    std::string date;
};

// Bir öğrencinin aldığı ders bilgilerini saklamak için struct
struct Course {
    std::string courseName;
    std::vector<Grade> grades;
};

// Öğrenciyi temsil eden struct
struct Student {
    int studentID;
    std::string name;
    std::map<std::string, Course> courses; // Ders adıyla eşleşen Course yapıları
};

// Öğrencileri saklamak için bir sınıf
class GradeAnalysis {
private:
    std::map<int, Student> students; // Öğrenci ID ile eşleşen öğrenciler
    
public:
    // Öğrenci ekleme
    void addStudent(int id, const std::string& name) {
        students[id] = {id, name, {}};
    }

    // Ders ekleme
    void addCourse(int studentID, const std::string& courseName) {
        students[studentID].courses[courseName] = {courseName, {}};
    }

    // Sınav notu ekleme
    void addGrade(int studentID, const std::string& courseName, ExamType examType, double score, const std::string& date) {
        Grade grade = {examType, score, date};
        students[studentID].courses[courseName].grades.push_back(grade);
    }

    // Öğrencinin ders bazlı notlarını listeleme
    void listGradesByCourse(int studentID, const std::string& courseName) {
        if (students.find(studentID) != students.end()) {
            Course& course = students[studentID].courses[courseName];
            std::cout << "Grades for " << courseName << ":\n";
            for (const Grade& grade : course.grades) {
                std::cout << "Type: " << static_cast<int>(grade.examType) << ", Score: " << grade.score << ", Date: " << grade.date << "\n";
            }
        }
    }

    // Ders bazlı sınav türü ile filtreleme
    void filterByExamType(const std::string& courseName, ExamType examType) {
        std::cout << "Filtering by exam type for course: " << courseName << "\n";
        for (const auto& studentPair : students) {
            const Student& student = studentPair.second;
            if (student.courses.find(courseName) != student.courses.end()) {
                const Course& course = student.courses.at(courseName);
                for (const Grade& grade : course.grades) {
                    if (grade.examType == examType) {
                        std::cout << "Student: " << student.name << ", Score: " << grade.score << ", Date: " << grade.date << "\n";
                    }
                }
            }
        }
    }
};

int main() {
    GradeAnalysis gradeAnalysis;

    // Öğrenci ekle
    gradeAnalysis.addStudent(1, "Alice");
    gradeAnalysis.addStudent(2, "Bob");

    // Ders ekle
    gradeAnalysis.addCourse(1, "Math");
    gradeAnalysis.addCourse(1, "Physics");
    gradeAnalysis.addCourse(2, "Math");

    // Not ekle
    gradeAnalysis.addGrade(1, "Math", ExamType::MIDTERM, 85.5, "2024-10-01");
    gradeAnalysis.addGrade(1, "Math", ExamType::FINAL, 90.0, "2024-12-15");
    gradeAnalysis.addGrade(2, "Math", ExamType::MIDTERM, 78.0, "2024-10-01");

    // Öğrencinin ders bazlı notlarını listele
    gradeAnalysis.listGradesByCourse(1, "Math");

    // Ders bazlı sınav türü ile filtrele
    gradeAnalysis.filterByExamType("Math", ExamType::MIDTERM);

    return 0;
}