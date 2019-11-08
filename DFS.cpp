///Made by Subhadeep Saha
#include<iostream>
using namespace std;

#define totalV 8//define it according to total no. of vertices

int time =0;
struct vertex
{
    int name;//for the name of the vertex
    int d_time, f_time;//for discovery time and finishing time
    char color;//for identification of colored or not colored
    int par;
}* Ver[totalV];//global declaration of the array which will hold all the matrix

void create_vertex(int Adjlt[][totalV])//this function will allocate all the vertex
{//passing the graph as argument
    for(int i=0; i<totalV; i++)
    {
        Ver[i]=(struct vertex*)malloc(sizeof(struct vertex));
        Ver[i]->name=i+1;//starting the name increasing 1 as array starts with 0
        Ver[i]->d_time=-1;//the discovery time
        Ver[i]->f_time=-1;//the finishing time
        Ver[i]->color='w';//defining the color
        Ver[i]->par=-1;//keeping track of parent
    }
}
void DFS_visit(struct vertex* u, int Adjlt[][totalV])//function to visit depth wise
{
    time++;//time stamp for d time and f time
    u->d_time=time;//the discovery time for the vertex
    u->color='g';//the grey coloring after the vertex visit
    for(int i=0;i<totalV;i++)
    {
        if(Adjlt[u->name-1][i]==1)//to traverse all those vertices connected to it
        {
            if(Ver[i]->color=='w')//if not visited it is white
            {
                Ver[i]->par=u->name;//making the current vertex as the parent of that newly discovered
                DFS_visit(Ver[i],Adjlt);//now exploring that vertex visited recently
            }
        }
    }
    u->color='b';//coloring black as visited and explored all neighbours
    time++;//incrementing time stamp
    u->f_time=time;//assigning the finishing time
}
void DFS(int Adjlt[][totalV])//function to visit all vertices
{
    for(int i = 0; i < totalV; i++)
    {
        if(Ver[i]->color=='w')//if not visited it is white
        {
            DFS_visit(Ver[i],Adjlt);//passing to visit all its neighbours depth wise
        }
    }
}

int main()
{
    int graph[][totalV]={{0,1,1,1,0,0,0,0},
                         {1,0,1,0,1,1,0,0},
                         {1,1,1,0,0,1,0,0},
                         {1,0,0,0,0,0,1,1},
                         {0,1,0,0,0,1,0,0},
                         {0,1,1,0,1,0,0,0},
                         {0,0,0,1,0,0,0,1},
                         {0,0,0,1,0,0,1,0},
                        };//the matrix as per the given graph
    create_vertex(graph);//creating the vertex of the graph
    DFS(graph);//dfs

    for(int i = 0 ; i<totalV; i++)
    {
        cout<<"Vertex no.-  "<<Ver[i]->name<<"\n";
        cout<<"Discovery time\t"<<Ver[i]->d_time<<endl<<"Finish time\t"<<Ver[i]->f_time<<endl<<endl;
    }
    return 0;
}

