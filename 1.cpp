#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char** argv)
{
    MPI_Init(NULL, NULL);
    int num;

    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    if(world_rank == 0)
        cin >> num;
    else
        MPI_Recv(&num, 1, MPI_INT, world_rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    cout << "El proceso " << world_rank << " recibio " << num << endl;

    if(world_size - 1 > world_rank)
        MPI_Send(&num, 1, MPI_INT, world_rank + 1, 0, MPI_COMM_WORLD);

    MPI_Finalize();
}
