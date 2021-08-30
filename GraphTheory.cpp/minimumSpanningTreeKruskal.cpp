/*
    Sort all the edges according to weight
    Take first one and check if they both belong to same component
    and if they do not than connect them else leave them

    at the end we will have a minimum spanning tree

    Time Complexity : O(M logM) + O(M X 4a)
                          ^           ^
                        Sorting     For iteration
          Finally   : O(M logM) 
    Space Complexity : O(N)
*/

#include <bits/stdc++.h>
using namespace std;
struct node
{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b)
{
    return a.wt < b.wt;
}

int findPar(int u, vector<int> &parentArr)
{
    if (u == parentArr[u])
    {
        return u;
    }
    return parentArr[u] = findPar(parentArr[u], parentArr);
}

void unionn(int u, int v, vector<int> &parentArr, vector<int> &rankArr)
{
    u = findPar(u, parentArr);
    v = findPar(v, parentArr);
    if (rankArr[u] < rankArr[v])
    {
        parentArr[u] = v;
    }
    else if (rankArr[v] < rankArr[u])
    {
        parentArr[v] = u;
    }
    else
    {
        parentArr[v] = u;
        rankArr[u]++;
    }
}
int main()
{
    int N, m;
    cin >> N >> m;
    vector<node> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }
    sort(edges.begin(), edges.end(), comp);

    vector<int> parentArr(N);
    for (int i = 0; i < N; i++)
    {
        parentArr[i] = i;
    }
    vector<int> rankArr(N, 0);

    int cost = 0;
    vector<pair<int, int>> mst;
    for (auto it : edges)
    {
        if (findPar(it.v, parentArr) != findPar(it.u, parentArr))
        {
            cost += it.wt;
            mst.push_back({it.u, it.v});
            unionn(it.u, it.v, parentArr, rankArr);
        }
    }
    cout << cost << endl;
    for (auto it : mst)
    {
        cout << it.first << " - " << it.second << endl;
    }
    return 0;
}