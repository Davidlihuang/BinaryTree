#ifndef  STRCMP_H_
#define STRCMP_H_
#include <iostream>
#include <vector>
using namespace std;;
/*ASCII码：
* 0-9: 48 - 57 
*a-z:   97- 112   
*A-Z:   65 - 90    // 差值32
*/
int strLen(const char *cstr);
int s_int(const char *cstr, int first, int second);
vector<int> checkNumber(const char *cstr);
bool strcmpWithDigital(const char *c1st, const char *c2nd);

#endif
