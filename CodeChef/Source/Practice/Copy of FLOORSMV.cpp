#include "../../Header/MainHeader.h"

#include <cstdio>
#include <limits.h>
#include <queue>

using namespace std;

typedef long long int llint;

struct AdjMatrixCell
{
	llint vertex;
	llint wt;
	AdjMatrixCell *next;
};


llint compute(AdjMatrixCell **adjMatrix,llint numVertices,llint n,llint f,llint m,llint vertex,llint bq)
{
	llint result = 0;
	llint bqRangeMin = (bq-1)*f;
	llint bqRangeMax = (bq*f) - 1;

	bool *visited = new bool[numVertices];
	llint *distance = new llint[numVertices];
	for(llint i=0;i<numVertices;i++)
	{
		visited[i] = false;
		distance[i] = LLONG_MAX;
	}

	queue<int> q;

	q.push(vertex);
	visited[vertex] = true;
	distance[vertex] = 0;

	while(!q.empty())
	{
		llint nodeNum = q.front();
		AdjMatrixCell *v = adjMatrix[nodeNum];
		while(v!=NULL)
		{
			if(visited[v->vertex]==false)
			{
				distance[v->vertex] = distance[nodeNum] + v->wt;
				visited[v->vertex] = true;
				q.push(v->vertex);

				//for calculating result
				if(!((v->vertex)>=bqRangeMin && (v->vertex)<=bqRangeMax))
				{
					result = result + distance[(v->vertex)];
				}
			}
			v = v->next;
		}
		q.pop();
	}

	/*for(llint i=0;i<numVertices;i++)
	{
		printf("%lld\n",distance[i]);
	} */

	delete[] visited;
	delete[] distance;
	return result;
}

void AddTo(AdjMatrixCell **ptr, AdjMatrixCell *cell)
{
	AdjMatrixCell *t = *ptr;
	if(t==NULL)
	{
		//printf("\tptr is null... adding %lld to it",cell->vertex);
		t = cell;
	}
	else
	{
		AdjMatrixCell *temp = t;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = cell;
	}
	*ptr = t;
}

void printAdjMatrix(AdjMatrixCell **adjMatrix,llint numVertices)
{
	for(llint i=0;i<numVertices;i++)
	{
		printf("%lld: ",i);
		AdjMatrixCell *p = adjMatrix[i];
		while(p!=NULL)
		{
			printf("%lld ",p->vertex);
			p = p->next;
		}
		printf("\n");
	}
}

void printEdges(AdjMatrixCell *t)
{
	AdjMatrixCell *temp = t;
	while (temp!=NULL)
	{
		printf("%lld ",temp->vertex);
		temp = temp->next;
	}
	printf("\n");
}

void FLOORSMV()
{
	llint n,f,m;
	llint bi,fi,t,bj,fj;
	//reading values

	scanf("%lld %lld %lld",&n,&f,&m);

	llint numVertices = n*f;
	//llint numEdges = n*(f-1) + (n-1) + m;

	AdjMatrixCell *cell = NULL;

	//Creating adjacency matrix
	AdjMatrixCell **adjMatrix = new AdjMatrixCell*[numVertices];

	for(llint i=0;i<numVertices;i++)
	{
		adjMatrix[i] = NULL;
	}

	for(llint i=0;i<numVertices;i++)
	{
		if((i%f)==0)
		{
			//this is the ground floor
			//adjMatrix[i][i+1].wt = 1;
			//adjMatrix[i][i+f].wt = 1;
			cell = new AdjMatrixCell;
			cell->vertex = i+1;
			cell->wt = 1;
			cell->next = NULL;
			//printf("Adding %lld vertex edge to node %lld\n",i+1,i);
			AddTo(adjMatrix+i,cell);
			//printf("%lld now contains following edges:",i);
			//printEdges(adjMatrix[i]);

			if(i+f<numVertices)
			{
				cell = new AdjMatrixCell;
				cell->vertex = i+f;
				cell->wt = 1;
				cell->next = NULL;
				//printf("Adding %lld vertex edge to node %lld\n",i+f,i);
				AddTo(adjMatrix+i,cell);
				//printf("%lld now contains following edges:",i);
				//printEdges(adjMatrix[i]);
			}

			if((i-f)>=0)
			{
				cell = new AdjMatrixCell;
				cell->vertex = i-f;
				cell->wt = 1;
				cell->next = NULL;
				//printf("Adding %lld vertex edge to node %lld\n",i-f,i);
				AddTo(adjMatrix+i,cell);
				//printf("%lld now contains following edges:",i);
				//printEdges(adjMatrix[i]);
			}
		}
		else
		{
			//these are rest of the floors
			if(((i+1)%f)!=0) // this is for all floors except the top one
			{
				//adjMatrix[i][i-1].wt = 1;
				//adjMatrix[i][i+1].wt = 1;

				cell = new AdjMatrixCell;
				cell->vertex = i-1;
				cell->wt = 1;
				cell->next = NULL;
				//printf("Adding %lld vertex edge to node %lld\n",i-1,i);
				AddTo(adjMatrix+i,cell);
				//printf("%lld now contains following edges:",i);
				//printEdges(adjMatrix[i]);

				cell = new AdjMatrixCell;
				cell->vertex = i+1;
				cell->wt = 1;
				cell->next = NULL;
				//printf("Adding %lld vertex edge to node %lld\n",i+1,i);
				AddTo(adjMatrix+i,cell);
				//printf("%lld now contains following edges:",i);
				//printEdges(adjMatrix[i]);
			}
			else // this is the top floor
			{
				//adjMatrix[i][i-1].wt = 1;
				cell = new AdjMatrixCell;
				cell->vertex = i-1;
				cell->wt = 1;
				cell->next = NULL;
				//printf("Adding %lld vertex edge to node %lld\n",i-1,i);
				AddTo(adjMatrix+i,cell);
				//printf("%lld now contains following edges:",i);
				//printEdges(adjMatrix[i]);
			}
		}
	}

	//printAdjMatrix(adjMatrix,numVertices);

	for(llint i=0;i<m;i++)
	{
		scanf("%lld %lld %lld %lld %lld",&bi,&fi,&t,&bj,&fj);
		llint r = (bi-1)*f + (fi-1);
		llint c = (bj-1)*f + (fj-1);
		//adjMatrix[r][c].wt = t;
		cell = new AdjMatrixCell;
		cell->vertex = c;
		cell->wt = t;
		cell->next = NULL;
		//printf("Adding %lld vertex edge to node %lld\n",c,r);
		AddTo(adjMatrix+r,cell);
		//printf("%lld now contains following edges:",r);
		//printEdges(adjMatrix[r]);
		//adjMatrix[c][r].wt = t; //since the bridges are bidirectional
		cell = new AdjMatrixCell;
		cell->vertex = r;
		cell->wt = t;
		cell->next = NULL;
		//printf("Adding %lld vertex edge to node %lld\n",r,c);
		AddTo(adjMatrix+c,cell);
		//printf("%lld now contains following edges:",c);
		//printEdges(adjMatrix[c]);
	}

	//printAdjMatrix(adjMatrix,numVertices);

	llint q; //queries

	scanf("%lld",&q);
	//printf("\nValue of q=%lld",q);

	while(q>0)
	{
		llint bq,fq;
		scanf("%lld %lld",&bq,&fq);
		llint vertex = (bq-1)*f + (fq-1);
		//printf("\nValue of vertex=%lld",vertex);
		llint ans = compute(adjMatrix,numVertices,n,f,m,vertex,bq);
		printf("%lld\n",ans);
		q--;
	}

}
