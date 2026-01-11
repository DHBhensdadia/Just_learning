#include <iostream>

int main()
{
    std::cout<<"Hello World" << std :: endl;
    
    int a{40};
    short b{40};
    
    
    int i{2147483647};
    char c1{62};
    char c2{'A'}; 
    char c3{'\n'};
    
    float f{32.423f}; 
    double d{43243.432};
    
    bool b{true};  

    const char* name{"Devansh"};
    
// enum data type 
    enum Weekdays{Sunday, Monday, Tuesdsay, Wednesday, Thusday, Friday, Saterday};
    Weekdays today{Monday};
    std :: cout << today;


// std i/o

    //output
    std :: cout << 42;
    
    std :: cout << "Age is " << 42;
    
    std :: cout << "Age is " << a;
    
    // new l
    std :: cout << "Hello!" << std :: endl;
    std :: cout << "in entier new line";
    
    // input
    int age;
    std :: cout << "Enter age : ";
    std :: cin >> age;
    std :: cout << "you have entered " << age << std :: endl;
    
    int level{}, score{};
    std :: cout << "Enter level and score : ";
    std :: cin >> level >> score;
    
    
//type conversion

    int int_var{45};
    double double_var{45.67};
    double sum = int_var + double_var;
    std :: cout << "Sum is : " << sum << std :: endl;

    double pi{3.14};
    int int_pi = (int) pi; // C-style


//The auto type specifier

    auto ao{10};
    std :: cout << ao << std::endl;
    // auto ap{10}, do{10.2}   error

    decltype(10 + 15.34) variable;     // specifing type of a variable using onother exparetion or variable
    decltype(ao) variable2;

    decltype(3 + 4.5) var;
    std::cout << typeid(var).name();

//arathmatic unari

    int vall{-4};
    std::cout << +vall << std::endl;
    std::cout << -vall << std::endl;


// fallthrough

    int var{1};

    switch (var) 
    {
        case 1:
        std:: cout << "Case 1\n";
        [[fallthrough]];
        case 2:
        std:: cout << "Case 2\n"; 
    }
    
    return 0;
}