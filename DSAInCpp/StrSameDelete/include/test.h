#ifndef TEST_H_
#define TEST_H_
#include <iostream>
#include <string>
#include "stringDelete.h"
#include "createdata.h"
#include "fileParse.h"
using std::string;
using std::cout;
using std::endl;

void testStrDelteFunction()
{
    string sourceFilename("./srcdata/data.txt");
    string resultFilename("./srcdata/result.txt");
    cout << "createData" <<endl;
    createData(sourceFilename, 1e3, 30);
    strDelete(sourceFilename, resultFilename);
}

void testFileSparse()
{

    const string filename("./srcdata/sparseTxt.txt");
    const string resFilename("./srcdata/sparseTxt.txt");

    stringSparse spa;
    spa.sparseData(filename);
    cout << spa << endl;
}

#endif