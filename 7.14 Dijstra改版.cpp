#include<iostream>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;
#pragma warning (disable:4996)
#define ERROR 0
#define OK 1
#define OVERFLOW 3

#define MAXNAME 20
#define INFINITY 1
#define MAX_V 101 //最大顶点数目

typedef char ElemType;
typedef struct
{
	int code;
	//ElemType* info;
}VertexType;
typedef struct
{
	double arcs[MAX_V+1][MAX_V+1];
	int vexnum, arcnum;
	VertexType vex[MAX_V+1];
	int GraphKind; //0 1 2 3 分别表示无向图 有向图 无向网 有向网
}MGraph;

void CreateMGraph(MGraph& G)
{

	int i, j, k;


	//邻接矩阵初始化(全为无穷大)
	for (i = 0; i <= G.vexnum; i++)
		for (j = 0; j <= G.vexnum; j++)
		{
				 G.arcs[i][j] =G.arcs[j][i] = INFINITY;
		}
	for (k = 1; k <= G.arcnum; k++)
	{
		cin >> i >> j;        //按起点编号 终点编号输入边
		G.vex[i].code = i;
		G.vex[j].code = j;
		cin >> G.arcs[i][j];
		//G.arcs[j][i] = G.arcs[i][j];
	}
	//double a=G.arcs[1][1];
}

int Max(double* dist, int n, vector<int> flag)
{
	int u = -1;
	double max = -1;
	for (int j = 1; j <= n; ++j)
	{
		if (!flag[j] && dist[j] > max&& dist[j]<1)
		{
			u = j;
			max = dist[j];
		}
	}
	return u;
}

//有向网或者无向网
double* Dijkstra(MGraph G, int s)//s为起始点编号
{
	/*几个数组的意义
		dist[i]:s->i的最短距离
		path[i]:经过path[i]到达i
		flag[i]:已被入选与否*/
	double dist[MAX_V+1];
	//int path[MAX_V + 1]
	vector<int>flag(MAX_V + 1);
	int i, j, MaxDist = 1, k = 1, t;
	for (i = 1; i <= G.vexnum; i++)
	{
		flag[i] = 0;
		dist[i] = G.arcs[s][i];
		//if (dist[i] < INFINITY)path[i] = s;
		//else path[i] = -1;
	}

	flag[s] = true;
	//for (i = 1; i <= G.vexnum - 1; i++)
	while(true)
	{
		//if (find(flag.begin(), flag.end(), 0) == flag.end())break;

		k = Max(dist, G.vexnum, flag);//返回dist[]中flag为0元素中最小者的编号
		if (k == -1)break;//所有可连通的点都已经到达过

		flag[k] = true;
		MaxDist = dist[k];
		for (j = 1; j <= G.vexnum; j++)
		{
			if (flag[j] == false &&(MaxDist * G.arcs[k][j] > dist[j] || dist[j] >= 1))
			{
				dist[j] = MaxDist * G.arcs[k][j];
				//path[j] = k;
			}
		}
	}
	return dist;

}


void PrintMGraph(MGraph G)
{
	int i, j;
	for (i = 1; i <= G.vexnum; i++)
	{
		for (j = 1; j <= G.vexnum; j++)
		{
			if (G.arcs[i][j] < INFINITY)  //输出INFINITY时用符号"∞"代替
				cout << setw(3) << G.arcs[i][j];
			else cout << setw(3) << "∞";
		}
		cout << "\n";
	}
}

int main()
{
	MGraph Graph;
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	Graph.vexnum = n;
	Graph.arcnum = m;


	CreateMGraph(Graph); //0 1 2 3 分别表示无向图 有向图 无向网 有向网

	
	double* dist=Dijkstra(Graph, s);//输入数字为起点编号
	cout <<fixed<<setprecision(3) <<dist[t];
}


/*
7 11 1 7
1 3 0.8
1 2 0.9
1 5 0.5
3 5 0.2
3 4 0.3
4 5 0.95
2 5 0.7
2 6 0.3
4 7 0.75
5 7 0.3
6 7 0.85
*/

/*测试数据
书本P117
3 5 8
v0 v1 v2 v3 v4
0 1 2  0 2 6  0 3 9
1 2 3  1 4 7
2 3 1  2 4 2
3 4 2


离散数学书P167 （1）
2 8 12
v1 v2 v3 v4 v5 v6 v7 v8
0 1 6  0 2 3
1 3 2  1 5 6
2 3 2  2 4 5  2 6 8
3 4 1  3 7 6
4 6 1
5 7 3
6 7 3

离散数学书P167 （2）
2 6 10
v1 v2 v3 v4 v5 v6
0 1 4  0 2 8
1 2 2  1 3 3  1 4 6
2 3 2  2 5 8
3 4 3  3 5 1
4 5 6
*/
