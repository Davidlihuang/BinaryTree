#ifndef TEST_H_
#define TEST_H_
#include <iostream>
#include <string>
#include "stringDelete.h"
#include "createdata.h"
#include "fileParse.h"
#include "strCmp.h"
using std::string;
using std::cout;
using std::endl;

void testStrDelteFunction()
{
    string sourceFilename("./srcdata/data.txt");
    string resultFilename("./srcdata/result.txt");
    cout << "createData" <<endl;
    createData(sourceFilename, 1e4, 30);
    strDelete(sourceFilename, resultFilename);
}

void testFileSparse()
{

    const string filename("/home/huangli/MyLearning/DataStructure/DSAInCpp/StrSameDelete/srcdata/sparseTxt.txt");
    const string resFilename("/home/huangli/MyLearning/DataStructure/DSAInCpp/StrSameDelete/srcdata/sparseTxt.txt");

    stringSparse spa;
    spa.sparseData(filename);
    cout << spa << endl;
}
void  testStrcmp()
{
    cout << "b90c < c21a: \t" <<strcmpWithDigital("b90c", "c21a") << endl;
    cout << "a99 < a120 :\t" << strcmpWithDigital("a99", "a120") << endl;
    cout << "99a < 100c: \t" << strcmpWithDigital("99a", "100c") << endl;
    cout << "abc23eg < abc129b:\t" << strcmpWithDigital("abc23eg", "abc129b") << endl;
    cout << "abd23< abc123:\t" << strcmpWithDigital("abd23", "abc123") << endl;
}
#endif
