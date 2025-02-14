#include <iostream>
#include <algorithm>

int main (int argc, char const *argv[])
{
    std:: string s = "";
    for(int i = 1; i < argc; i++)
    {
        std:: string tmp = argv[i];

        std::transform(
          tmp.begin(), 
          tmp.end(), 
          tmp.begin(),
          ::toupper
        );
        s += tmp;
    }

    if (argc == 1)
        s  = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << s << std::endl;
    return (0);
}
