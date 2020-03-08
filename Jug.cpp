#include "Jug.h"

Jug::Jug(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
	Ca = a;
	Cb = b;
	N = c;
	cfA = d;
	cfB = e;
	ceA = f;
	ceB = g;
	cpAB = h;
	cpBA = i;
	
	//check invalid inputs
	if (Ca > Cb || Cb > 1000 || N > Cb || N < 0 || Ca < 0 || Cb < 0 || cfA < 0 || cfB < 0 || ceA < 0 || ceB < 0 || cpAB < 0 || cpBA < 0) {
		invalid = true;
	}
	else {
		invalid = false;
		// creating empty adjacency table
		vector<vector<Vertex*> > table(Ca + 1);
		for (unsigned i = 0; i < table.size(); ++i) {
			for (int j = 0; j <= Cb; ++j) {
				Vertex* temp = new Vertex();
				table.at(i).push_back(temp);
			}
		}
		graph = table;
		buildGraph(0, 0, 0, nullptr, "");
		/*for (int i = 0; i < graph.size(); ++i) {
			for (int j = 0; j < graph.at(i).size(); ++j) {
				cout << graph.at(i).at(j)->dist << " ";
			}
			cout << endl;
		}*/
	}
}
Jug::~Jug() {}
void Jug::buildGraph(int a, int b, int d, Vertex* p, string str) {
	Vertex* v = graph.at(a).at(b);
	if (d < v->dist) {
		//cout << d << endl;
		v->dist = d;
		v->prev = p;
		v->act = str;
		//fillA
		buildGraph(Ca, b, d + cfA, v, "fill A");
		//fillB
		buildGraph(a, Cb, d + cfB, v, "fill B");
		//emptyA
		buildGraph(0, b, d + ceA, v, "empty A");
		//emptyB
		buildGraph(a, 0, d + ceB, v, "empty B");
		//pourAB
		int tempA = min(a, Cb - b);
		buildGraph(a - tempA, b + tempA, d + cpAB, v, "pour A B");
		//pourBA
		int tempB = min(b, Ca - a);
		buildGraph(a + tempB, b - tempB, d + cpBA, v, "pour B A");
	}
}
int Jug::solve(string& str) {
	//check for valid values
	str = "";
	if (invalid) {
		return -1;
	}
	//checks if solveable and searches for shortest path
	bool solveable = false;
	int min = graph.at(0).at(N)->dist;
	//indices
	int minA = 0;
	int minB = N;
	for (int i = 0; i < Ca; ++i) {
		if (graph.at(i).at(N)->prev != nullptr) {
			solveable = true;
		}
		if (graph.at(i).at(N)->dist < min) {
			min = graph.at(i).at(N)->dist;
			minA = i;
			minB = N;
		}
	}
	if (N <= Ca) {
		for (int i = 0; i < Cb; ++i) {
			if (graph.at(N).at(i)->prev != nullptr) {
				solveable = true;
			}
			if (graph.at(N).at(i)->dist < min) {
				min = graph.at(N).at(i)->dist;
				minA = N;
				minB = i;
			}
		}
	}
	if (!solveable) {
		return 0;
	}
	print(str, graph.at(minA).at(minB));
	str += "success " + to_string(min);
	return 1;
}
void Jug::print(string& str, Vertex* v) {
	if (v->act == "") {
		return;
	}
	print(str, v->prev);
	str += v->act + '\n';
}