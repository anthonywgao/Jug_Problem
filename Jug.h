#ifndef __JUG_H__
#define __JUG_H__

#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

struct Vertex {
	Vertex(){
		dist = numeric_limits<int>::max();
		prev = 0;
		act = "";
	}
	int dist;
	Vertex* prev;
	string act;
};
class Jug {
public:
	Jug(int, int, int, int, int, int, int, int, int);
	~Jug();

	//solve is used to check input and find the solution if one exists
	//returns -1 if invalid inputs. solution set to empty string.
	//returns 0 if inputs are valid but a solution does not exist. solution set to empty string.
	//returns 1 if solution is found and stores solution steps in solution string.
	int solve(string& solution);
private:
	//anything else you need
	//returns true if a is min
	int min(int a, int b) {
		if (a > b) {
			return b;
		}
		return a;
	}
	int Ca;
	int Cb;
	int N;
	int cfA;
	int cfB;
	int ceA;
	int ceB;
	int cpAB;
	int cpBA;
	bool invalid;
	vector<vector<Vertex*> >graph;
	void buildGraph(int, int, int, Vertex*, string);
	void print(string&, Vertex*);
};

#endif