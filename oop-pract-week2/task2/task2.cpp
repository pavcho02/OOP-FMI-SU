#include <iostream>
#include <fstream>
using namespace std;



int lengthOfFile(const char* address)
{
    ifstream inFile(address);
    if (!inFile.is_open())
    {
        cout << "Error";
    }
    int counter = -1;
    while (!inFile.eof())
    {
        char ch = inFile.get();
        counter++;
    }
    inFile.close();

    return counter;
}

int main()
{
    cout << lengthOfFile("task2.txt");
	return 0;
}

