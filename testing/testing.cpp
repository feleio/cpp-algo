#include <iostream>
#include <string>

using namespace std;

int main()
{
    const string s("sdf");
     string* ps = &s;
    //ps->push_back('a');
    cout << s;
    return 0;
}