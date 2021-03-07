#include <iostream>
#include <vector>
#include "sequenceStack.h"
#include "DLLStack.h"
#include "singleListStack.h"

using namespace std;
int main()
{
    cout << "array stack"<<endl;
    sequenStackTest();
    cout << "\nvec stack"<< endl;
    vecSequenStackTest();
    return 0;
}