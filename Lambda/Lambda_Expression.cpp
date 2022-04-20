#include <functional>
#include <iostream>
using namespace std;

bool CallDidProviderHandler(
    const std::string& str, const std::function<void(const std::string&)>& handler)
{
    handler(str);
    return true;
}

bool Lambda_func(const std::string& str, std::string& value)
{
    cout << "Str = " << str << endl;
    value = str;
    return true;
}

void MyFunc(const std::string& str, std::string& value)
{
    CallDidProviderHandler(str, [&value](const auto& str1) {
        Lambda_func(str1, value);
    });
}

int main()
{
    std::string str("Rajesh");
    std::string value;
    MyFunc(str, value);
    cout << "Value = " << value << endl;
    return 0;
}
