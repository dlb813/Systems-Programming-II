#include <iostream>
#include <string>

// Required by fork routine
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>   // Declaration for exit()

using namespace std;

int main()
{
    pid_t pID = fork();
    if (pID == 0)                // child
    {
        cout << "Child Process: My Process ID is " << getpid() << endl;
    }
    else if (pID < 0)            // failed to fork
    {
        cerr << "Failed to fork" << endl;
        exit(1);
        // Throw exception
    }
    else                         // parent
    {
        cout << "Parent Process: My Process ID is " << getpid() << endl;
    }
}
