//=========================================================
// Student Grade Manager
// Challenge 3 - CodeLab II Programming Skills Portfolio
//=========================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

//---------------------------------------------------------
// Student Class definition
//---------------------------------------------------------
// PURPOSE:
// The Student class was created to represent a complete
// student record as a single object rather than storing
// student information in multiple separate variables.
//
// WHY OOP WAS USED:
// Object-Oriented Programming improves organisation by
// grouping related data and behaviour together. Each
// Student object contains its own data and methods,
// making the program easier to read, manage and expand.
//
// BENEFITS:
// - Improved code organisation
// - Reduced duplication
// - Easier maintenance
// - Supports multiple student records
// - Makes future expansion simpler
//
// REAL-WORLD LINK:
// Similar approaches are used in databases and student
// management systems where each student is treated as
// an individual record.
//---------------------------------------------------------
class Student
{
private:
// Stores the information associated with each student.
    int studentID;
    string name;
    int yearGroup;
    double coursework;
    double exam;

public:
    // Creates a Student object and assigns values to
    // all attributes when a new record is created.
    //
    // The constructor receives student details and
    // stores them within the object.
    //
    // Ensures every Student object is created with
    // complete and valid information.
    Student(int id, string n, int yg, double cw, double ex)
    {
        studentID = id;
        name = n;
        yearGroup = yg;
        coursework = cw;
        exam = ex;
    }
// Getter methods are used to provide controlled access
// to private student data.
//
// Student information is stored as private data to
// protect the integrity of the object. Getter methods
// allow other parts of the program to retrieve values
// without directly modifying the stored data.
//
// Encapsulation - data and behaviour are grouped
// together while restricting direct access to
// internal attributes. OOP 
//---------------------------------------------------------
    int getID() { return studentID; }
    string getName() { return name; }
    int getYearGroup() { return yearGroup; }
    double getCoursework() { return coursework; } 
    double getExam() { return exam; }
  
    // Calculate the final module mark using the assessment
    // weighting formula.
    //
    // Coursework contributes 40%.
    // Exam contributes 60%.
    //
    // The calculation only needs to be written once and
    // can be reused throughout the program whenever a
    // final mark is required.
    double getFinalMark() { return (coursework * 0.4) + (exam * 0.6); }

    string getClassification()
    {
        double mark = getFinalMark();
        if (mark >= 70) { return "First"; }
        else if (mark >= 60) { return "Upper Second"; }
        else if (mark >= 50) { return "Lower Second"; }
        else if (mark >= 40) { return "Third"; }
        return "Fail"; 
    }
    // Convert a numerical final mark into an academic
    // classification.
    //
    // Selection statements compare the calculated final
    // mark with classification boundaries.
    //
    // Classifications are generated automatically and
    // consistently for every student record.
    //
    // Verify marks correctly map to:
    // First
    // Upper Second
    // Lower Second
    // Third
    // Fail
    void displayStudent()
    {
        cout << "\nID: " << studentID
            << "\nName: " << name
            << "\nYear Group: " << yearGroup
            << "\nCoursework: " << coursework
            << "\nExam: " << exam
            << "\nFinal Mark: " << getFinalMark()
            << "\nClassification: " << getClassification()
            << endl;
    }
};
// Display all student information in a structured
// format including calculated results.
//
// Combines stored data, calculated final marks and
// generated classifications into a single output,
// making student records easier to view and manage.
//
// Display functionality belongs to the Student object,
// keeping related behaviour together with the data it
// operates on.
//---------------------------------------------------------
// End of Student Class definition
//---------------------------------------------------------

//---------------------------------------------------------
// Load Students From File
//---------------------------------------------------------
// PURPOSE:
// Load student records from studentMarks.txt and
// convert them into Student objects that can be used
// throughout the program.
//
// DESIGN DECISION:
// External file storage was chosen so student records
// persist after the program closes rather than being
// recreated every time the application starts.
//
// BENEFIT:
// Supports larger datasets and makes the system more
// realistic compared to storing hard-coded records.

// Reading structured data from a text file and
// converting it into Student objects.
void loadStudents(vector<Student>& students)
{
    ifstream file("studentMarks.txt");
// ifstream is used to read student data from an
// external text file into the program.
    if (!file)
    {
        cout << "Error opening file." << endl;
        return;
    }

    string line;
// Confirms the file opened successfully before any
// processing occurs, preventing file access errors.

    while (getline(file, line))
    {
// Records are processed one line at a time, reducing
// memory usage and simplifying parsing.
        stringstream ss(line);
// stringstream converts the record into a stream,
// making it easier to separate and process individual
// fields from structured file data.
        if (line.empty() || line[0] == '/')
{
    continue;
}
    // Variables used to temporarily store the data
    // extracted from each student record.
        string idStr, name, yearGroupStr,
                courseworkStr, examStr;
    // Extracts each field from the record using
    // commas as delimiters.
        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, yearGroupStr, ',');
        getline(ss, courseworkStr, ',');
        getline(ss, examStr, ',');
// Comma delimiters are used to identify where one
// field ends and the next begins within each record.
        int id = stoi(idStr), yearGroup = stoi(yearGroupStr);
        double coursework = stod(courseworkStr),
                exam = stod(examStr);
// File data is initially read as text and converted
// into numeric data types so calculations can be
// performed correctly.
    students.push_back(Student(id, name, yearGroup, coursework, exam));
    }
// A Student object is created from the parsed data
// and stored in a vector for dynamic record management.
    file.close();
}
//---------------------------------------------------------
// End Load Students From File
//---------------------------------------------------------

//---------------------------------------------------------
// Save Students To File
//---------------------------------------------------------
// PURPOSE:
// Save all current student records to studentMarks.txt
// so additions and modifications remain available after
// the program closes.
//
// DESIGN DECISION:
// File storage was used to provide data persistence.
// Without saving, all student records would be lost when
// the application terminates.
//
// BENEFIT:
// Allows users to add new students, save changes and
// reload updated records during future program sessions.
void saveStudents(vector<Student>& students)
{
    ofstream file("studentMarks.txt");
    // Iterates through each Student object and writes
    // the student's data to the file in comma-separated
    // format so it can be loaded again later.
    // ofstream is used to write student data from memory
    // to an external file.
    for (Student& student : students)
    {
        file << student.getID() << ","
            // Student information is written in CSV-style format 
            //using comma delimiters. This ensures records can
            // be reloaded and parsed correctly by loadStudents().
            << student.getName() << ","
            << student.getYearGroup() << ","
            << student.getCoursework() << ","
            << student.getExam()
            << endl;
    }
    // Processes every Student object stored within the
    // vector to ensure all records are saved.
    file.close();
    // Confirms to the user that the save process
    // completed successfully.
    cout << "Students saved successfully." << endl;
}
//---------------------------------------------------------
// End Save Students To File
//---------------------------------------------------------

//---------------------------------------------------------
// View All Students
//---------------------------------------------------------
// Iterates through the students vector and displays
// the information stored for each Student object.
// The displayStudent() method is called to avoid code
// duplication and ensure student information is
// displayed in a consistent format.
void viewAllStudents(vector<Student>& students)
{
    // Processes every Student object currently stored
    // within the students vector.
    for (Student& student : students)
    {
        // Calls the displayStudent() method to output
        // the student's details, final mark and
        // classification.
        student.displayStudent();
        // Prints a separator to improve readability
        // when multiple student records are displayed.
        cout << "----------------------" << endl;
    }
}
//---------------------------------------------------------
// End View All Students
//---------------------------------------------------------

//---------------------------------------------------------
// View Student By ID
//---------------------------------------------------------
// Allows the user to search for a specific student
// by entering their student ID. The program searches
// the students vector and displays the matching
// student record if it is found.
void viewIndividualStudent(vector<Student>& students)
{
    // Stores the student ID entered by the user.
    int searchID;

    cout << "Enter Student ID Number: ";
    cin >> searchID;
    // Iterates through each Student object in the
    // students vector and compares its ID against
    // the ID entered by the user.
    for (Student& student : students)
    {
        if (student.getID() == searchID)
        {
            // Displays the student's information when
            // a matching ID is found.
            student.displayStudent();
            // Stops searching once the correct student
            // record has been located.
            return;
        }
    }
    // Displays an error message if no matching
    // student ID exists within the vector.
    cout << "Student not found." << endl;
}
//---------------------------------------------------------
// End View Student By ID
//---------------------------------------------------------

//---------------------------------------------------------
// Calculate Final Mark And Classification
//---------------------------------------------------------
// PURPOSE:
// Allows the user to locate a specific student record
// and view the student's calculated final mark and
// academic classification.
//
// DESIGN DECISION:
// Student records are searched using Student ID because
// IDs are unique and provide a reliable way to identify
// a specific student.
//
// OOP BENEFIT:
// The program uses methods belonging to the Student
// class instead of performing calculations directly
// in this function.
void calculateStudentMark(vector<Student>& students)
{
    // User enters the Student ID that will be used
    // to locate a specific student record.
    int searchID;

    cout << "Enter Student ID Number: ";
    cin >> searchID;
    // Iterates through each Student object stored in
    // the vector until a matching Student ID is found.
    for (Student& student : students)
    {
        if (student.getID() == searchID)
        {
            // Calls the Student class method which
            // calculates the weighted final mark using
            // the assessment formula.
            cout << "\nFinal Mark: " << student.getFinalMark() << endl;
            // Uses the Student class method to convert
            // the calculated mark into the appropriate
            // academic classification.
            cout << "Classification: " << student.getClassification() << endl;
            // Ends the function once a matching
            // student record has been found.
            return;
        }
    }
    // Displays a message if the Student ID
    // cannot be found.
    cout << "Student not found." << endl;
}
//---------------------------------------------------------
// End Calculate Final Mark And Classification
//---------------------------------------------------------

//---------------------------------------------------------
// Add A New Student
//---------------------------------------------------------
// PURPOSE:
// Allows users to create new student records during
// program execution and store them within the system.
//
// DESIGN DECISION:
// New records are stored as Student objects and added
// to the students vector. This allows the collection
// to grow dynamically without requiring a fixed number
// of student records.
//
// BENEFIT:
// Users can expand the dataset without modifying the
// source code or manually editing the data file.
void addStudent(vector<Student>& students)
{
    // Variables used to temporarily store the new
    // student's information before creating a
    // Student object.
    int id, yearGroup;
    string name;
    double coursework, exam;

    cout << "Enter Student ID Number: ";
    cin >> id;
    // Clears any remaining input before reading
    // the student's name using getline().
    cin.ignore(1000, '\n');
    // Clears any remaining characters from the input buffer
    // before getline() reads the student's full name.

    cout << "Enter Student Name: ";
    getline(cin, name);
    // Validation loop to ensure the year group
    // entered is between 1 and 4.
    do
    {
        cout << "Enter Year Group (1-4): "; cin >> yearGroup;
    } while (yearGroup < 1 || yearGroup > 4);
    // Validation loop to ensure the coursework
    // mark remains between 0 and 100.
    do
    {
        cout << "Enter Coursework Mark (0-100): "; cin >> coursework;
    } while (coursework < 0 || coursework > 100);
    // Validation loop to ensure the exam mark
    // remains between 0 and 100.
    do
    {
        cout << "Enter Exam Mark (0-100): "; cin >> exam;
    } while (exam < 0 || exam > 100);
    // Checks whether the entered student ID
    // already exists to prevent duplicate records.
    for (Student& student : students)
        if (student.getID() == id)
        {
            cout << "Student ID already exists." << endl;
            return;
        }
    // Creates a new Student object and stores it
    // within the students vector.
    students.push_back(
        Student(id, name, yearGroup, coursework, exam)
    );
    // Confirms that the student record was
    // successfully added.
    cout << "Student added successfully." << endl;
}
//---------------------------------------------------------
// End Add A New Student
//---------------------------------------------------------

//---------------------------------------------------------
// Search Student By Name
//---------------------------------------------------------
// PURPOSE:
// Allows users to locate a student record using the
// student's name rather than their Student ID.
//
// ADDITIONAL FEATURE:
// This functionality was added beyond the core
// assessment requirements to improve usability and
// provide an alternative search method.
//
// DESIGN DECISION:
// Student records are searched by comparing the
// entered name against the names stored within each
// Student object.
//
// BENEFIT:
// Makes the system easier to use when a Student ID
// is unknown but the student's name is available.

// Providing an alternative search method when a
// Student ID is unknown.
void searchByName(vector<Student>& students)
{
    // Stores the name entered by the user.
    string searchName;

    cin.ignore(1000, '\n');
    // Clears any leftover characters from the input 
    // buffer before reading a full name with getline().
    cout << "Enter Student Name: ";
    getline(cin, searchName);
    // Searches through each Student object stored
    // in the students vector.
    for (Student& student : students)
        if (student.getName() == searchName){ student.displayStudent(); return; }
    // Displays a message if no matching
    // student record exists.
    cout << "Student not found." << endl;
}
//---------------------------------------------------------
// End Search Student By Name
//---------------------------------------------------------

//---------------------------------------------------------
// Display Highest Performing Student
//---------------------------------------------------------
// Searches through all students and identifies the
// student with the highest final mark. This is achieved
// by comparing each student's calculated final mark
// against the current highest performing student.

// Identifying the highest-performing student from
// a dynamic collection of records.
void highestStudent(vector<Student>& students)
{
    // Checks whether any student records exist before
    // attempting to perform the search.
    if (students.empty())
    {
        cout << "No students found." << endl;
        return;
    }
    // Assumes the first student is initially the
    // highest performing student.
    Student topStudent = students[0];
    // Iterates through all Student objects and compares
    // their final marks to identify the highest result.
    for (Student& student : students)
    {
        if (student.getFinalMark() > topStudent.getFinalMark())
        {
            // Updates the highest performing student
            // whenever a larger final mark is found.
            topStudent = student;
        }
    }
    // Displays the details of the highest performing
    // student after all comparisons have been completed.
    cout << "\nHighest Performing Student" << endl;
    cout << "--------------------------" << endl;

    topStudent.displayStudent();
}
//---------------------------------------------------------
// End Display Highest Performing Student
//---------------------------------------------------------

//---------------------------------------------------------
// Main Program
//---------------------------------------------------------
// Controls the overall execution of the Student Grade
// Manager. The main function loads student records,
// displays the menu system and processes user requests.
int main()
{
    //-----------------------------------------------------
    // Variable Declaration Section
    //-----------------------------------------------------
    // Stores all Student objects loaded from the file
    // and the user's selected menu option.
    vector<Student> students;
    //-----------------------------------------------------
    // Variable Declaration Section End
    //-----------------------------------------------------

    //-----------------------------------------------------
    // Student Loading Section
    //-----------------------------------------------------
    // Loads student records from the text file into
    // the students vector and displays the number
    // of records successfully loaded.
    loadStudents(students);
    
    cout << students.size()
        << " students loaded successfully."
        << endl;
    //-----------------------------------------------------
    // Student Loading Section End
    //-----------------------------------------------------
    int choice;
    //-----------------------------------------------------
    // Menu System Section
    //-----------------------------------------------------
    // Displays the main menu and allows the user to
    // access different features of the program. A
    // do-while loop is used so the menu continues
    // running until the user selects Exit.
    do
    {
        cout << "\n===== Student Grade Manager =====" << endl;
        cout << "1. View All Students" << endl;
        cout << "2. View Individual Student" << endl;
        cout << "3. Calculate Student Mark" << endl;
        cout << "4. Add Student" << endl;
        cout << "5. Search By Name" << endl;
        cout << "6. Highest Performing Student" << endl;
        cout << "7. Save Students To File" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter Menu Option (1-8): ";

        cin >> choice;
        //-------------------------------------------------
        // Menu Processing Section
        //-------------------------------------------------
        // PURPOSE:
        // Provide users with access to all system features
        // through a single menu-driven interface.
        //
        // DESIGN DECISION:
        // A switch statement was chosen because it provides
        // a clear and organised method of processing multiple
        // user commands.
        //
        // BENEFITS:
        // - Easy navigation
        // - Improved usability
        // - Centralised program control
        // - Simple feature expansion
        switch (choice)
        {
        case 1: // View all student records.
            viewAllStudents(students);
            break;

        case 2: // View an individual student record.
            viewIndividualStudent(students);
            break;

        case 3: // Calculate and display final mark and classification.
            calculateStudentMark(students);
            break;

        case 4: // Create and add a new student record.
            addStudent(students);
            break;

        case 5: // Search for a student using their name.
            searchByName(students);
            break;

        case 6: // Display the highest-performing student.
            highestStudent(students);
            break;

        case 7: // Save all current student records to file.
            saveStudents(students);
            break;

        case 8:
            // Save records before program termination to ensure
            // data persistence and prevent information loss.
            saveStudents(students);
            cout << "Exiting Program..." << endl;
            break;
        // Displays an error message if an invalid
        // menu option is entered.
        default:
            cout << "Invalid choice." << endl;
        }
        // Handles invalid menu selections and provides
        // user feedback if an unsupported option is entered.
        //-------------------------------------------------
        // Menu Processing Section End
        //-------------------------------------------------
    } while (choice != 8);
    //-----------------------------------------------------
    // Menu System Section End
    //-----------------------------------------------------
    return 0;
}
//---------------------------------------------------------
// End Main Program
//---------------------------------------------------------


//program exacutiable line of codes == 246 no spaces or comments
//with spaces and comments word count == 674 
