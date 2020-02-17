#include<bits/stdc++.h>
using namespace std;

int nvertices;
int *a;
int *ssize;
priority_queue< pair<int,pair<int,int> >, vector< pair<int,pair<int,int> > >,greater< pair<int,pair<int,int> > > > pq;

void init()
{
    for(int i=0;i<nvertices;i++)
    {
        a[i] = i;
        ssize[i] =1;
    }
}

int findroot(int x)
{
    while( a[x] != x)
    {
        x = a[a[x]];
    }
    return x;
}

int connect(int x,int y)
{
    int rootx = findroot(x);
    int rooty = findroot(y);

    if( rootx == rooty ) //formation of cycle here
    {
        return 0;
    }

    else if( ssize[rootx] > ssize[rooty] )
    {
        a[rooty] = a[rootx];
        ssize[rootx] += ssize[rooty];
        return 1;
    }

    else
    {
        a[rootx] = a[rooty];
        ssize[rooty] += ssize[rootx];
        return 1;
    }
    return 1;
}

int main()
{
    cout<<"\nplease enter the number of vertices :\n";
    cin>>nvertices;

    a=(int*) malloc(nvertices * sizeof(int));

    int nconnections;

    ssize = (int*)malloc(nvertices * sizeof(int));
    cout<<"\nplease enter no of connections :\n";
    cin>>nconnections;

    for(int i=0;i<nconnections;i++)
    {
        int a,b,cost;
        cin>>a>>b>>cost;
        pair<int,int> p = make_pair(a,b);
        pair<int, pair<int,int> > q= make_pair(cost,p);
        pq.push(q);
    }

    int totalcost = 0;
    init();
    //print();
    //exit(0);
    while(!pq.empty())
    {
        int cost = pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second;

        int ans = connect(a,b);

        if( ans == 1 ) //connection was made;
        {
            totalcost += cost;
        }

        pq.pop();
    }

    printf("\n the minimum cost of the spanning tree is : %d ",totalcost);
    return 0;
}
