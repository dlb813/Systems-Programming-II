#include <unistd.h>
#include <iostream>
int	main()
{
    std::cout << "Executing ls command" << std::endl;
    execl("/bin/ls", "/bin/ls", "-r", "-t", "-l", (char *) 0);
    std::cout << "This won't print" << std::endl;
    return 0;
}