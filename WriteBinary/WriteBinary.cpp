#include <iostream>
#include <fstream>


int main()
{
    std::ofstream f("file.bin", std::ios::binary);

    if (!f.is_open())
    {
        return -1;
    }

    int a = 16;

    f.write((const char*)&a, sizeof(int)); // the file will show 10 00 00 00

    f.close();
    return 0;
}
