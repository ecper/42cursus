# include <iostream>
# include <fstream>

int main(int argc ,char **argv)
{
    std::string filename;
    std::string s1;
    std::string s2;
    if (argc < 2 || argc > 4)
    {
        std::cerr << "Invalid params." << std::endl;
        return (-1);
    }

    filename = std::string(argv[1]);
    s1 = std::string(argv[2]);
    s2 = std::string(argv[3]);

    std::ifstream ifs;

    ifs.open(filename.c_str(), ifs.in);
    if (ifs.fail())
    {
        std::cerr << "Failed to open file." << std::endl;
        return (-1);
    }

    std::ofstream ofs;
    std::string str;
    std::string replace_str;
    size_t pos;
    ofs.open((filename + ".replace").c_str(), ofs.out);
    if (ofs.fail())
    {
        std::cerr << "Failed to create file." << std::endl;
        return (-1);
    }
    while (getline(ifs, str))
    {
        pos = str.find(s1);
        if (pos != std::string::npos)
        {
            str.erase(pos, pos + s1.size());
            str.insert(pos, s2);
        }
        ofs << str << std::endl;
    }
}
