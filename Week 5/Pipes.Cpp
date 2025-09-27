#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

int main() {
    while (true) {
        cout << "\n==== Mini Shell Menu ====\n";
        cout << "Commands:\n"
             << "  child <name>\n"
             << "  ls\n"
             << "  mkdir <dirname>\n"
             << "  exit\n> ";
        cout.flush();

        string line;
        if (!getline(cin, line)) break;   // EOF (Ctrl+D)
        if (line.empty()) continue;

        // Extract first word (command)
        size_t spacePos = line.find(' ');
        string cmd = (spacePos == string::npos) ? line : line.substr(0, spacePos);
        string arg = (spacePos == string::npos) ? ""   : line.substr(spacePos + 1);

        if (cmd == "child") {
            // Demonstrate parent->child pipe
            int fd[2];
            if (pipe(fd) == -1) {
                perror("pipe");
                continue;
            }

            pid_t pid = fork();
            if (pid < 0) {
                perror("fork");
                continue;
            }
            if (pid == 0) { // child
                close(fd[1]); // close write end
                char buffer[128];
                ssize_t n = read(fd[0], buffer, sizeof(buffer) - 1);
                if (n > 0) {
                    buffer[n] = '\0';
                    cout << "New child with name: " << buffer << endl;
                }
                close(fd[0]);
                _exit(0);
            } else { // parent
                close(fd[0]); // close read end
                write(fd[1], arg.c_str(), arg.size());
                close(fd[1]);
                waitpid(pid, nullptr, 0);
            }
            continue;
        }

        if (cmd == "exit") {
            cout << "Exiting shell.\n";
            break;
        }

        if (cmd == "ls" || cmd == "mkdir") {
            pid_t pid = fork();
            if (pid < 0) {
                perror("fork");
                continue;
            }
            if (pid == 0) {
                // Build argv for execvp
                if (cmd == "ls") {
                    char *argv[] = { const_cast<char*>("ls"), nullptr };
                    execvp("ls", argv);
                } else if (cmd == "mkdir") {
                    if (arg.empty()) {
                        cerr << "Usage: mkdir <dirname>\n";
                        _exit(1);
                    }
                    char *argv[] = { const_cast<char*>("mkdir"),
                                     const_cast<char*>(arg.c_str()), nullptr };
                    execvp("mkdir", argv);
                }
                perror("execvp");
                _exit(1);
            } else {
                waitpid(pid, nullptr, 0);
            }
            continue;
        }

        cout << "Unknown command: " << cmd << endl;
    }
    return 0;
}
