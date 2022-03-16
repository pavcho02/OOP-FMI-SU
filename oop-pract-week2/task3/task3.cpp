#include <iostream>
#include <fstream>
using namespace std;

const int capacity = 25;
const int len = 1024;
const char* address = "relation.txt";
const char split = 'x';

struct Pair
{
	int x;
	int y;
};

struct Relation
{
	Pair relations[capacity];
	int size = 0;
};

void initPair(Pair& p, const int a, const int b)
{
	p = { a,b };
}

Pair creatPair()
{
	Pair p;
	int a, b;
	cin >> a >> b;
	initPair(p, a, b);
	return p;
}

Pair readPairFromFile(std::ifstream& inFile)
{
	Pair p;
	int first = 0;
	int second = 0;
	inFile >> first >> second;
	p.x = first;
	p.y = second;
	return p;
}

void writePairToFile(std::ofstream& outFile, const Pair& p)
{
	outFile << p.x << " " << p.y;
}

void addPairToRelation(Relation& r, const Pair& p)
{
	r.relations[r.size].x = p.x;
	r.relations[r.size].y = p.y;
	r.size++;
}

void writeRelationToFile(std::ofstream& outFile, const Relation& r)
{
	outFile << r.size << endl;
	for (int i = 0; i < r.size; i++)
	{
		writePairToFile(outFile, r.relations[i]);
		outFile << endl;
	}
}

Relation readRelationFromFile(std::ifstream& inFile)
{
	Relation r;
	int size = 0;
	inFile >> size;
	for (int i = 0; i < size; i++)
	{
		addPairToRelation(r, readPairFromFile(inFile));
	}
	return r;
}

void printPair(const Pair& p) 
{
	cout << p.x << " " << p.y << endl;
}

void printRelation(const Relation& r) 
{
	for (int i = 0; i < r.size; i++)
	{
		printPair(r.relations[i]);
	}	
}

int main()
{
	Relation example;
	addPairToRelation(example, { 1,2 });
	addPairToRelation(example, { 1,3 });
	addPairToRelation(example, { 1,4 });
	addPairToRelation(example, { 2, 3 });
	addPairToRelation(example, { 2, 4 });
	addPairToRelation(example, { 2, 4 });

	printRelation(example);
	std::cout << std::endl;

	ofstream outFile(address);
	if (!outFile.is_open())
	{
		cout << "error";
	}
	writeRelationToFile(outFile,example);
	ifstream inFile(address);
	if (!inFile.is_open())
	{
		cout << "error";
	}
	Relation r = readRelationFromFile(inFile);
	printRelation(r);
	return 0;
}

