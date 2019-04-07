#include <iostream>
#include "Student.hpp"
#include "GraduateStudent.hpp"
#include "PhdStudent.hpp"

int main(int argc, const char * argv[]) {
    
    Student student1("Alice", 5, 100);

    std::cout << "Name: " << student1.name << "\n"
              << "Fines: " << student1.GetLibraryFines() << "\n"
              << "Tuition fees: " << student1.tuition_fees << "\n"
              << "Money Owed: " << student1.MoneyOwed() << "\n";
    
    std::cout << "----------------------\n";
    
    GraduateStudent student2("Bob", 60, 150, 1);
    
    std::cout << "Name: " << student2.name << "\n"
              << "Fines: " << student2.GetLibraryFines() << "\n"
              << "Tuition fees: " << student2.tuition_fees << "\n"
              << "Money Owed: " << student2.MoneyOwed() << "\n";
    
    std::cout << "----------------------\n";
    
    PhdStudent student3("Ole", 80, 500, 1);
    
    std::cout << "Name: " << student3.name << "\n"
              << "Fines: " << student3.GetLibraryFines() << "\n"
              << "Tuition fees: " << student3.tuition_fees << "\n"
              << "Money Owed: " << student3.MoneyOwed() << "\n";
    
    return 0;
}
