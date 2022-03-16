#include <iostream>
#include <fstream>
using namespace std;

void diff(const char* address)
{
    ifstream inFile(address);
    if (!inFile.is_open())
    {
        cout << "Error";
    }
    double sum, multi;
    inFile >> multi >> sum;
    cout << multi - sum;

    inFile.close();
}

int main()
{
    double x, y, z;
    cin >> x >> y >> z;
    ofstream outFile("result.txt");
    if (!outFile.is_open())
    {
        cout << "Error";
    }
    outFile << x * y * z << " " << x + y + z;
    outFile.close();

    diff("result.txt");
    return 0;
}

