#include <string>
#include <iterator>
#include "graph.h"

void menu();

template<class T, class E>
void AddCity(GraphLnk<T, E>& G);

template<class T, class E>
void AddPath(GraphLnk<T, E>& G);


template<class T, class E>
bool MakeMST(GraphLnk<T, E>& graph, vector<EdgeNode<T, E> >& V);

int main(){
	GraphLnk<string, int> cities;
	vector<EdgeNode<string, int> > mst;
	char cmd = '\0';
	bool isQuit = false;
	menu();
	while(!isQuit){
		cout << "Enter your operation [A, B, C, D, E]\n>";
		cin >> cmd;
		switch(cmd){
			case 'A':
				AddCity(cities);//add city
				break;
			case 'B':
				AddPath(cities);//add path between cities
				break;
			case 'C':
				MakeMST(cities, mst);//make minimum spanning tree
				break;
			case 'D'://print mstree
				for(vector<EdgeNode<string, int> >::iterator iter = mst.begin(); iter != mst.end(); ++iter)
					cout << *iter << endl;
				break;
			case 'E'://quit
				isQuit = true;
				break;
			default:
				cout << "Wrong order, Enter again\n";
		}
	}
	cout << "Thanks for using\n";
	cin.get();
	cin.get();
	return 0;
}


void menu(){
	cout << "-----Electricity Net Cost Stimulator-----\n"
		<< "-----------------------------------------\n"
		<< "-----  A --- Add City -------------------\n"
		<< "-----  B --- Add Path Between Cities ----\n"
		<< "-----  C --- Make Minimum Spanning Tree--\n"
		<< "-----  D --- Show Minimum Spanning Tree--\n"
		<< "-----  E --- Quit -----------------------\n"
		<< "-----------------------------------------\n";
}

template<class T, class E>
void AddCity(GraphLnk<T, E>& G){
	int citiesAmount = 0;
	cout << "Enter cities amount: ";
	cin >> citiesAmount;
	if(citiesAmount <= 0){
		cout << "Wrong amount\n";
		return;
	}
	cout << "Enter City names\n";
	string cityTmp;
	for(int i = 0;i < citiesAmount;++i){
		cout << "City" << i + 1 << ": ";
		cin >> cityTmp;
		G.insertVertex(cityTmp);
	}
}


template<class T, class E>
void AddPath(GraphLnk<T, E>& G){
	string city1, city2;
	int weight;
	bool isEnd = false;
	cout << "Enter like this: name1 name2 weight[enter \"0 0 0\" to end]\n";
	while(!isEnd){
		cout << "Enter two city and the distance between them: ";
		cin >> city1 >> city2 >> weight;
		if(city1 == "0" && city2 == "0" && weight == 0){
			isEnd = true;
		}else{
			G.insertEdge(city1, city2, weight);
		}
	}
}

template<class T, class E>
bool MakeMST(GraphLnk<T, E>& G, vector<EdgeNode<T, E> >& V){
	if(G.isEmpty())return false;
	Kruskal(G, V);
	cout << "Kruskal minimum spanning tree made!\n";
	return true;
}


