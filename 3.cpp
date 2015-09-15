#include <iostream>
#include <mpi.h>
#include <string>

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
    int tmp, tmp2;
    int size;
    int sum = 0;

    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    if(world_rank == 0){
	getline(cin,data);
        tmp = 0;
	size = data.size();
        for(int i=1;i<world_size-1;i++)
        {
		MPI_Send(&size, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
		MPI_Send(&data[tmp], size/(world_size-1), MPI_INT, i, 0, MPI_COMM_WORLD);

		tmp += size/(world_size-1);

		MPI_Recv(&tmp2, 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		sum += tmp2;			  
        }
	
	cout << "Palabras: " << sum << endl;
    }else{
	MPI_Recv(&size, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	MPI_Recv(&data, size/(world_size-1), MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

	tmp2 = countString(data); 
	MPI_Send(&tmp, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
}
