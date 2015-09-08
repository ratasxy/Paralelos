#include <iostream>
#include <mpi.h>

#define MAX 50

using namespace std;

int main(int argc, char** argv)
{
    MPI_Init(NULL, NULL);
    int size, num;
    int data[MAX];

    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    if(world_rank == 0){
        cin >> num;
        for(int i=0;i<num;i++)
                cin >> data[i];
        for(int i=1;i<world_size;i++){
                MPI_Send(&num, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
                MPI_Send(&data, num, MPI_INT, i, 0, MPI_COMM_WORLD);
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
