#include <iostream>
#include <memory>
#include <string>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

class FileHandle{
    private:
        int fd;
    public:
        FileHandle(const string path){
            this->fd = open(path.c_str(), O_RDWR);
            if(this->fd < 0){
                perror("Open");
                throw runtime_error("Failed to open file");
            }
        }
        
        ~FileHandle(){
            close(fd);
        }
    FileHandle(const FileHandle&) = delete;
    FileHandle& operator = (const FileHandle&) = delete;
};

int main(){
    auto eg = make_unique<FileHandle>("/dev/ttyUSB0");
    return 0;
}