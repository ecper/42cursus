# include "Harl.hpp"

int main(int argc, char **argv)
{

    if (argc < 2 || argc > 3)
    {
        std::cout << "Invalid params." << std::endl;
        return (-1);
    }

    Harl harl;
    std::string params;

    params = argv[1];

    harl.filterComplain(params);

    return (0);
}