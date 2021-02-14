#include <iostream>
#include "personal.h"
#include "student.h"
#include "database.h"

using namespace std;
int main() {
  //  Database<Personal> helloDatabase;
   //helloDatabase.run();
    Database<Student>().run();
    return 0;
}