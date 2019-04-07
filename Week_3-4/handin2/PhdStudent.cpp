#include "PhdStudent.hpp"

double PhdStudent::MoneyOwed() const
{
    return 0;
}

PhdStudent::PhdStudent(std::string name1, double fines, double fees, bool fullTime1)
{
    name = name1;
    tuition_fees = fees;
    SetLibraryFines(fines);
    fullTime = fullTime1;
}
