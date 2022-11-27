#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int S, int Target) {
    vector<vector<pair<double, int>>> graph(n+1);
    for (int i = 0; i < edges.size(); i++) {
        vector<int> e = edges[i];
        graph[e[0]].emplace_back(succProb[i], e[1]);
    }

    priority_queue<pair<double, int>> que;
    vector<double> Proba(n+1, 0);

    que.emplace(1, S);
    Proba[S] = 1;
    while (!que.empty()) {
        double pr = que.top().first;
        int node = que.top().second;
        que.pop();
        if (pr < Proba[node]) {
            continue;
        }
        for(int i=0;i< graph[node].size(); i++)
        {
            double prNext = graph[node][i].first;
            int nodeNext = graph[node][i].second;
            if (Proba[nodeNext] < Proba[node] * prNext) {
                Proba[nodeNext] = Proba[node] * prNext;
                que.emplace(Proba[nodeNext], nodeNext);
            }
        }
    }
    return Proba[Target];
}

int main()
{
    int n, m,S,Target,i;
    cin >> n >> m >> S >> Target;
    vector<vector<int>> edges;
    vector<double> succProb;
    for (i = 0; i < m; i++)
    {
        vector<int>tem(2);
        double Proba;
        cin>>tem[0] >> tem[1];
        cin >> Proba;
        succProb.push_back(Proba);
        edges.push_back(tem);
    }
    cout << fixed<<setprecision(3) << maxProbability(n, edges, succProb, S, Target);
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