#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class employee {
protected:
    string first_name;
    string last_name;
    string phone_number;
    string email;
    string emp_register_num;

public:
    void set_first_name(string first) {
        first_name = first;
    }
    void set_last_name(string last) {
        last_name = last;
    }
    void set_phone_number(string phone) {
        phone_number = phone;
    }
    void set_email(string mail) {
        email = mail;
    }
    void set_emp_register_num(string emp_num) {
        emp_register_num = emp_num;
    }

    string get_first_name() {
        return first_name;
    }
    string get_last_name() {
        return last_name;
    }
    string get_phone_number() {
        return phone_number;
    }
    string get_email() {
        return email;
    }
    string get_emp_register_num() {
        return emp_register_num;
    }

    virtual void display_info() {
        cout << "First Name: " << first_name << endl;
        cout << "Last Name: " << last_name << endl;
        cout << "Phone Number: " << phone_number << endl;
        cout << "Email: " << email << endl;
        cout << "Employee Register Number: " << emp_register_num << endl;
    }
};

class administrator : public employee {
private:
    string education_level;
    string field_of_study;
    double monthly_salary;

public:
    administrator(string first, string last, string phone, string mail, string emp_num, string edu_lvl, string field, double msalary) {
        set_first_name(first);
        set_last_name(last);
        set_phone_number(phone);
        set_email(mail);
        set_emp_register_num(emp_num);
        education_level = edu_lvl;
        field_of_study = field;
        monthly_salary = msalary;
    }

    void display_info() override {
        employee::display_info();
        cout << "Education Level: " << education_level << endl;
        cout << "Field of Study: " << field_of_study << endl;
        cout << "Monthly Salary: " << monthly_salary << endl;
    }
};

class teacher : public employee {
private:
    string subjects_taught;
    int student_assessment;
    float hourly_salary;

public:
    teacher(string first, string last, string phone, string mail, string emp_num, string subj, int assess, float hsalary) {
        set_first_name(first);
        set_last_name(last);
        set_phone_number(phone);
        set_email(mail);
        set_emp_register_num(emp_num);
        subjects_taught = subj;
        student_assessment = assess;
        hourly_salary = hsalary;
    }

    void display_info() override {
        employee::display_info();
        cout << "Subjects Taught: " << subjects_taught << endl;
        cout << "Student Assessment: " << student_assessment << endl;
        cout << "Hourly Salary: " << hourly_salary << endl;
    }
};

void add(vector<employee>& emps) {
    string first_name;
    string last_name;
    string phone_number;
    string email;
    string emp_register_num;
    string education_level;
    string field_of_study;
    string subjects_taught;
    int student_assessment;
    double monthly_salary;
    float hourly_salary;
    int choice;

    cout << "\t\t\t\t___________________________________________\n";
    cout << "\t\t\t\t                                           \n";
    cout << "\t\t\t\t            Add New Staff Member           \n";
    cout << "\t\t\t\t___________________________________________\n";
    cout << "\t\t\t\t            Select Employee Type:          \n";
    cout << "\t\t\t\t                                           \n";
    cout << "\t\t\t\t            1) Administrator               \n";
    cout << "\t\t\t\t                                           \n";
    cout << "\t\t\t\t            2) Teacher                     \n";
    cout << "\t\t\t\t                                           \n";
    cout << "\t\t\t\t            3) Exit                        \n";
    cout << "\t\t\t\t                                           \n";
    cout << "\t\t\t\t            Choice:  ";
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << "\t\t\t\t___________________________________________\n";
            cout << "\t\t\t\t                                           \n";
            cout << "\t\t\t\t            Add New Administrator          \n";
            cout << "\t\t\t\t___________________________________________\n";
            cout << "\t\t\t\t            Enter First Name: ";
            cin >> first_name;
            cout << "\t\t\t\t            Enter Last Name: ";
            cin >> last_name;
            cout << "\t\t\t\t            Enter Phone Number: ";
            cin >> phone_number;
            cout << "\t\t\t\t            Enter Email Address: ";
            cin >> email;
            cout << "\t\t\t\t            Enter Employee Register Number: ";
            cin >> emp_register_num;
            cout << "\t\t\t\t            Enter Education Level: ";
            cin >> education_level;
            cout << "\t\t\t\t            Enter Field of Study: ";
            cin >> field_of_study;
            cout << "\t\t\t\t            Enter Monthly Salary: ";
            cin >> monthly_salary;

            emps.push_back(administrator(first_name, last_name, phone_number, email, emp_register_num, education_level, field_of_study, monthly_salary));

            cout << "New Administrator Added Successfully.";
            break;
        }
        case 2: {
            cout << "\t\t\t\t___________________________________________\n";
            cout << "\t\t\t\t                                           \n";
            cout << "\t\t\t\t             Add New Teacher               \n";
            cout << "\t\t\t\t___________________________________________\n";
            cout << "\t\t\t\t            Enter First Name: ";
            cin >> first_name;
            cout << "\t\t\t\t            Enter Last Name: ";
            cin >> last_name;
            cout << "\t\t\t\t            Enter Phone Number: ";
            cin >> phone_number;
            cout << "\t\t\t\t            Enter Email Address: ";
            cin >> email;
            cout << "\t\t\t\t            Enter Employee Register Number: ";
            cin >> emp_register_num;
            cout << "\t\t\t\t            Enter Subjects Taught: ";
            cin >> subjects_taught;
            cout << "\t\t\t\t            Enter Student assessment: ";
            cin >> student_assessment;
            cout << "\t\t\t\t            Enter Hourly Salary: ";
            cin >> hourly_salary;

            emps.push_back(teacher(first_name, last_name, phone_number, email, emp_register_num, subjects_taught, student_assessment, hourly_salary));

            cout << "New Teacher Added Successfully.";
            break;
        }
        case 3: {
            exit(0);
        }
        default: {
            cout << "\t\t\t\t Please enter a valid choice:";
            break;
        }
    }
}

void show(vector<employee>& emps) {
    if (emps.empty()) {
        cout << "\t\t\t\t No Employees Were Found.";
        return;
    }

    for (int i = 0; i < emps.size(); i++) {
        emps[i].display_info();
        cout << endl;
    }
}

void inspect(vector<employee>& emps) {
    string emp_register_num;
    cout << "\t\t\t\t Enter Employee Register Number: ";
    cin >> emp_register_num;

    for (int i = 0; i < emps.size(); i++) {
        if (emps[i].get_emp_register_num() == emp_register_num) {
            emps[i].display_info();
            return;
        }
    }

    cout << "\t\t\t\t Employee Not Found.";
}

void del(vector<employee>& emps) {
    string emp_register_num;
    cout << "\t\t\t\t Enter Employee Register Number: ";
    cin >> emp_register_num;

    for (int i = 0; i < emps.size(); i++) {
        if (emps[i].get_emp_register_num() == emp_register_num) {
            emps.erase(emps.begin() + i);
            cout << "\t\t\t\t Employee Removed.";
            return;
        }
    }

    cout << "\t\t\t\t Employee Not Found.";
}

int main() 
{
    vector<employee> emps;

    int choice;
    int option = 0;

    while (option != 4)
    {
    
    cout << "\t\t\t\t___________________________________________\n";
    cout << "\t\t\t\t                                           \n";
    cout << "\t\t\t\t             Staff Management              \n";
    cout << "\t\t\t\t___________________________________________\n";
    cout << "\t\t\t\t                                           \n";
    cout << "\t\t\t\t            1) Add Staff Member            \n";
    cout << "\t\t\t\t                                           \n";
    cout << "\t\t\t\t            2) Inspect Staff Member        \n";
    cout << "\t\t\t\t                                           \n";
    cout << "\t\t\t\t            3) Show All Staff              \n";
    cout << "\t\t\t\t                                           \n";
    cout << "\t\t\t\t            4) Delete Staff Member         \n";
    cout << "\t\t\t\t                                           \n";
    cout << "\t\t\t\t            5) Exit                        \n";
    cout << "\t\t\t\t                                           \n";
    cout << "\n\t\t\t            Please Select: ";

    cin >> choice;

    if (cin.fail()) {
            cout << "\t\t\t\t Invalid choice. Please try again: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
    }
    switch (choice) 
    {
        case 1: {
            add(emps);
            break;
        }
        case 2: {
            inspect(emps);
            break;
        }
        case 3: {
            show(emps);
            break;
        }
        case 4: {
            del(emps);
            break;
        }
        case 5: {
            exit(1);
        }
        default: {
            cout << "\t\t\t\t Please enter a valid choice: ";
            break;
        }
    }
    }
    return 0;
}
