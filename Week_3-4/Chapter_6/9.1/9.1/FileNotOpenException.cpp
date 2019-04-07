#include "FileNotOpenException.hpp"

FileNotOpenException::FileNotOpenException(std::string prob) : Exception("File", prob)
{
    
}
