#include <iostream>
using namespace std;

class Exam {
    string* student_name;
    string* exam_date;
    int* score;

public:
    Exam(const string& student_name) {
        this->student_name = new string(student_name); // Why error when *this->student_name = student_name;
        this->exam_date = new string("");
        this->score = new int(0);
    }

    //  Omitting the implementation of the Copy Constructor and Copy Assignment Operator
  /*Exam(const Exam& exam) {
        student_name = new string(*exam.student_name);
        exam_date = new string(*exam.exam_date);
        score = new int(*exam.score);
    }

    Exam& operator=(const Exam& otherExam) {
        if(this == &otherExam) return *this;

        delete student_name;
        delete exam_date;
        delete score;

        student_name = new string(*otherExam.student_name);
        exam_date = new string(*otherExam.exam_date);
        score = new int(*otherExam.score);

        return *this;
    }*/

    ~Exam() {
        delete student_name;
        student_name = nullptr;

        delete exam_date;
        exam_date = nullptr;

        delete score;
        score = nullptr;
    }

    void displayExamDetails() {
        cout << "\nStudent Name: " << *student_name << endl;
        cout << "Exam Date: " << *exam_date << endl;
        cout << "Score: " << *score << endl;
    }

    void setExamDate(const string& date) {
        *this->exam_date = date;
    }

    void setExamScore(const int& score) {
        *this->score = score;
    }
};

int main() {
    
    /*
    // Create an original Exam object
    Exam exam1("Osman");
    exam1.setExamDate("15-09-2025");
    exam1.setExamScore(85);
    cout << "Original Exam:" << endl;
    exam1.displayExamDetails();

    // Create a deep copy using the copy constructor
    Exam exam2(exam1);
    cout << "\nDeep Copy:" << endl;
    exam2.displayExamDetails();

    // Modify the original to demonstrate independence
    exam1.setExamDate("20-09-2025");
    exam1.setExamScore(90);

    cout << "\nAfter modification:" << endl;
    cout << "Original:" << endl;
    exam1.displayExamDetails();
    cout << "Copy (unchanged):" << endl;
    exam2.displayExamDetails();
    */
    
    return 0;
}
