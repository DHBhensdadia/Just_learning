#include<iostream>
#include<string>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string to_string(int n){
    string ans;
    
    if (n == 0){n++;}
    while (n != 0){
        int a = n%10;
        n /= 10;
        ans.push_back('0' + a);
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
    
}

class Person {
  private :
    short int age;
  protected :
    string gender;
    string name;
  public :
    // constructor
    Person(string name, string gender, int age){
        this->name = name;
        if (gender == "male" || gender == "female"){
            this->gender = gender;
        }else {
            this->gender = "other";
        }
        this-> age = age;
    }
    Person(){}
    
    // printer
    void print(){
        cout << name << ' ' << gender << " " << age;
    }
    
    
};

class Manager;

class Employee : protected Person {
  private :
    int yearly_salary;
    static int ecount;
  protected :
    string employee_id;
    string employee_since;
    string designation;
    string department;
  public :
    // constructor
    Employee (string name, string gender, int age, string department, string designation, string employee_since, int yearly_salary) : Person(name, gender, age){
        this->department = department;
        this->designation = designation;
        this->employee_since = employee_since;
        this->yearly_salary = yearly_salary;
        
        employee_id = "E" + to_string(ecount);
        ecount ++;
    }
    Employee (){
        
    }
    
    // printer
    void print(){
        cout << employee_id << ' ';
        Person::print();   
        cout << ' ' << department << ' ' << designation << ' ' << employee_since << ' ' << yearly_salary << endl;
    }

    // increment method
    void increment(float percentage){
        yearly_salary += yearly_salary * percentage;
    }  
    
    //friend class
    friend class Manager;
};
int Employee::ecount = 1;

class Manager : protected Employee {
protected :
    Employee direct_reports[10];
    short int direct_reports_count = 0;
public :
    // constructor
    Manager (const Employee & e) : Employee(e){
    }
    
    // printer
    void print (){
        Employee :: print();  
        Employee *(eparr[direct_reports_count]);
        for (int i = 0; i < direct_reports_count; i++){
            eparr[i] = direct_reports + i;
        }
        for (int i = 0; i < direct_reports_count - 1; i++){
            for (int j = 0; j < direct_reports_count - i - 1; j++){
                if(eparr[j]->yearly_salary <  eparr[j + 1]->yearly_salary){
                    Employee * temp = eparr[j];
                    eparr[j] = eparr[j + 1];
                    eparr[j + 1] = temp;
                }
            }
        }

        for(int i = 0; i < direct_reports_count; i++){
            eparr[i]->print();
        }

    }

    // method to add direct reporter
    void add_direct_report (Employee * to_add){
        direct_reports[direct_reports_count] = *to_add;
        direct_reports_count++;
    }

    // method to change designation
    void change_designation(string existing_one, string new_one){
        for (int i = 0; i < direct_reports_count; i++){
            if (direct_reports[i].designation == existing_one){
                direct_reports[i].designation = new_one;
            }
        }
    }

    //mathod to increase the salary
    void increase_salary(string designation, double percent){
        for (int i = 0; i < direct_reports_count; i++){
            if (direct_reports[i].designation == designation){
                int& ref_d = direct_reports[i].yearly_salary;
                ref_d += ref_d * percent/100.0;
            }
        }
    }
};

int main() {
    string name, gender, department, designation, employee_since;
    short age;
    int yearly_salary;
    cin >> name >> gender >> age >> department >> designation;
    cin >> employee_since >> yearly_salary;
    Employee employee(name, gender, age, department, designation,
                      employee_since, yearly_salary);
    Manager manager(employee);
    
    int direct_reports_count = 0;
    cin >> direct_reports_count;
    
    Employee *employee_ptr;
    for(int i = 0; i < direct_reports_count; i++) {
        getchar(); // removing newline from input buffer
        cin >> name >> gender >> age >> department >> designation;
        cin >> employee_since >> yearly_salary;
        employee_ptr = new Employee(name, gender, age, department,
                                    designation, employee_since,
                                    yearly_salary);
        manager.add_direct_report(employee_ptr);
    }
    
    getchar(); // Removing newline from input buffer
    string existing_designation, new_designation;
    cin >> existing_designation >> new_designation;
    manager.change_designation(existing_designation, new_designation);

    float increment_percentage;
    cin >> designation >> increment_percentage;
    manager.increase_salary(designation, increment_percentage);

    manager.print();
    
    return 0;
}