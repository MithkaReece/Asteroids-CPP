#include "System.hpp"

System::System() : ID(nextID++) {}

int System::nextID = 0;