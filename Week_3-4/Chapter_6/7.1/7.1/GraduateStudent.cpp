#include "GraduateStudent.hpp"

double GraduateStudent::MoneyOwed() const
{
    return GetLibraryFines();
}

//own stuff
GraduateStudent::GraduateStudent() : Student()
{

}

GraduateStudent::GraduateStudent(std::string name, double fines, double fees, bool fullTime)
{
    this -> name = name;
    tuition_fees = fees;
    SetLibraryFines(fines);
    this -> fullTime = fullTime;
}
