#include<bits/stdc++.h>
#include<semaphore.h>
#include<pthread.h>
#include<string.h> 
#include<stdlib.h> 
// #include<mutex.h>
#include<unistd.h> 
using namespace std;

int northWait = 0; // no one waiting
int southWait = 0; // no one waiting
int northBound = 0; // no one in tunnel
int southBound = 0; // no one in tunnel
// sem_t mutex=1; 
pthread_mutex_t lock;

void *Arrive(void *param){
    // lock.Wait();
    pthread_mutex_lock(&lock);
    // If no one in the tunnel, car goes
    if ((northBound > 0) || (southBound > 0)){
        if (dir == North){
            // if no one is waiting to go south, car goes north
            if ((southWait > 0) || (southBound > 0)) {
                northWait++;
                goNorth.Wait(lock);
                northWait--;
            }
            else {
                // if no one is waiting to go north, car goes south
                if ((northWait > 0) || (northBound > 0)) {
                    southWait++;
                    goSouth.Wait(lock);
                    southWait--;
                }
            }
        }
        if (dir == North) northBound++;
        else southBound++;
        // lock.Signal();
        pthread_mutex_unlock(&lock);
    }
}

void *Depart(void *param){
    // lock.Wait();
    pthread_mutex_lock(&lock);
    if (dir == North) {
        northBound--;
        if (southWait > 0) {
            if (northBound == 0)
                goSouth->Broadcast();
        }
    }
    else {
        southBound--;
        if (northWait > 0) {
            if (southBound == 0)
                goNorth.Broadcast();
        }
    }
    // lock.Signal();
    pthread_mutex_unlock(&lock)
}





int main(){

    if (pthread_mutex_init(&lock, NULL) != 0) 
    { 
        printf("\n mutex init has failed\n"); 
        return 1; 
    }
    // pthread_t tid1,tid2;
    // pthread_create(&tid1,NULL,Arrive,NULL);
    // pthread_create(&tid2,NULL,Depart,NULL);
    // pthread_join(tid1,NULL);
    // pthread_join(tid2,NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}




// enum Direction {North, South};
// class Tunnel {
//     public:
//         Arrive(Direction dir); Depart(Direction dir);
//     private:
//         Lock lock;
//         CVar goNorth, goSouth;
//         int northWait; // waiting to go north
//         int southWait; // waiting to go south
//         int northBound; // going north in Tunnel
//         int southBound; // going south in Tunnel
// }//Tunnel ends
// Tunnel::Tunnel() {
//     lock.value = 1; // lock for shared variables is available
//     northWait = 0; // no one waiting
//     southWait = 0; // no one waiting
//     northBound = 0; // no one in tunnel
//     southBound = 0; // no one in tunnel
// }//constructor ends

// Tunnel::Arrive(Direction dir){
//     lock.Wait();
//     // If no one in the tunnel, car goes
//     if ((northBound > 0) || (southBound > 0)) {
//         if (dir == North) {
//             // if no one is waiting to go south, car goes north
//             if ((southWait > 0) || (southBound > 0)) {
//             // otherwise, we count north waiters, and wait for a signal
//                 northWait++;
//                 goNorth.Wait(lock);
//                 northWait--;
//             }
//             else {
//                 // if no one is waiting to go north, car goes south
//                 if ((northWait > 0) || (northBound > 0)) {
//                     southWait++;
//                     goSouth.Wait(lock);
//                     southWait--;
//                 }
//             }
//         }
//         // count how many cars are in the tunnel
//         if (dir == North) northBound++;
//         else southBound++;
//         lock.Signal();
//     }
// }
// // When a northbound car departs, we signal all southbound cars if any
// // are waiting only if no northbound cars are in the tunnel. Similarly,
// // when a southbound car departs. Note, in the Arrive routine above
// // the car only waits if a car going the other direction is in the
// // tunnel.
// Tunnel::Depart(Direction dir) {
//     lock.Wait();
//     if (dir == North) {
//         northBound--;
//         if (southWait > 0) {
//             if (northBound == 0)
//                 goSouth->Broadcast();
//         }
//     }
//     else {
//         southBound--;
//         if (northWait > 0) {
//             if (southBound == 0)
//                 goNorth.Broadcast();
//         }
//     }
//     lock.Signal();
// }