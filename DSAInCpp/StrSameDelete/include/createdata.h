#ifndef CREATEDATA_H_
#define CREAATEDATA_H_
#include <iostream>
#include <string>

// 生成limits个字符串保存在filename中，每个数据的范围是0-range
void createData(const std::string& filename, long limits, long range);
#endif