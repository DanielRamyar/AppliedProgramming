#include "Student.hpp"

double Student::MoneyOwed() const
{
    return tuition_fees + GetLibraryFines();
}

void Student::SetLibraryFines(double amount)
{
    if (amount >= 0)
    {
        library_fines = amount;
    }
}

//own stuff
Student::Student()
{
    name = "Unspecified";
    tuition_fees = 0;
    library_fines = 0;

}

Student::Student(std::string name, double fines, double fees)
{
    this -> name = name;
    tuition_fees = fees;
    SetLibraryFines(fines);
    
}
