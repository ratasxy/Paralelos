#include <iostream>
#include <mpi.h>

#define MAX 50

using namespace std;

int countString(string data)
{
   int ans = 0;
   for(int i=0;i<data.size();i++){
     if(data[i] == ' ')
	ans++;
   }

   return ans;
}

int main(int argc, char** argv)
{
    MPI_Init(NULL, NULL);
    string data;
    int tmp;

    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    if(world_rank == 0){
	cin >> data;
        tmp = 0;
        for(int i=0;i<world_size;i++)
        {
	  
        }
    }else{
	MPI_Recv(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	MPI_Recv(&data, num, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
    
    cout << "El proceso " << world_rank << " recibio ";
    for(int i=0;i<num;i++)
	cout << data[i] << " ";
    cout << endl;

    MPI_Finalize();
}
