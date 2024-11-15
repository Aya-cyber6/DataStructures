      //Find grade by student name
    cout << "Grades for " << "Ahmet" << ":\n";
    for (const Course& course : Ahmet.courses) {
        cout << "Course: " << course.courseName << "\n";
        for (const auto& grade : course.grades) {
            cout << "  " << grade.first << ": " << grade.second << "\n";
        }
    }

    //List grades by course name
          cout << "Grades for Math" << ":\n";
          for(const auto& student : students ){
            for (const auto& grade : student.courses[0].grades) {
                     cout << "  " << grade.first << ": " << grade.second << "\n";
        }
   }