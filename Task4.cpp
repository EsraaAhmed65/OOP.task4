#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;
public:
    static int totalCount;
    Person()
    {
        totalCount++;
    }
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
        totalCount++;
    }
    ~Person()
    {
      totalCount--;
    }
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    int getAge()
    {
        return age;
    }
    virtual void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int Person::totalCount = 0;

class Student : public Person
{
private:
    string studentId;
    char grade;
public:
    Student(){}
    Student(string name, int age, string studentId, char grade) : Person(name, age)
    {
        this->studentId = studentId;
        this->grade = grade;
    }
    ~Student() {}
    void setStudentId(string studentId)
    {
        this->studentId = studentId;
    }
    string getStudentId()
    {
        return studentId;
    }
    void setGrade(char grade)
    {
        this->grade = grade;
    }
    char getGrade()
    {
        return grade;
    }
    void displayInfo()
    {
        Person::displayInfo();
        cout << "Student ID: " << studentId << endl;
        cout << "Grade: " << grade << endl;
    }
};

class Teacher : public Person
{
private:
    string employeeId;
    string subject;
public:
    Teacher(){}
    Teacher(string name, int age, string employeeId, string subject) : Person(name, age)
    {
        this->employeeId = employeeId;
        this->subject = subject;
    }
    ~Teacher() {}
    void setEmployeeId(string employeeId)
    {
        this->employeeId = employeeId;
    }
    string getEmployeeId()
    {
        return employeeId;
    }
    void setSubject(string subject)
    {
        this->subject = subject;
    }
    string getSubject()
    {
        return subject;
    }
    void displayInfo()
    {
        Person::displayInfo();
        cout << "Employee ID: " << employeeId << endl;
        cout << "Subject: " << subject << endl;
    }
};

int main()
{
    Student s("Reem", 20, "123R", 'A');
    Teacher t("Omar", 35, "456O", "probability");
    cout << "Student Information:" << endl;
    s.displayInfo();
    cout << endl <<"---------------------"<<endl;
    cout << "Teacher Information:" << endl;
    t.displayInfo();
    cout << endl<<"---------------------"<<endl;
    cout << "Total number of Person objects created: " << Person::totalCount << endl;
    return 0;
}
