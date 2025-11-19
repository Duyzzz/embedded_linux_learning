#include <iostream>
#include <memory>
#include <sys/timerfd.h>
#include <unistd.h>      // for read(), close()
#include <cstring>       // for memset, strerror (optional)
#include <stdint.h>      // for uint64_t
#include <sys/types.h>
#include <sys/time.h>    // sometimes needed depending on usage
#include <errno.h>
#include <functional>

using namespace std;

class LinuxTimer {
    public:
    LinuxTimer(){
        fd = timerfd_create(CLOCK_MONOTONIC, 0);
        if(fd == -1){
            perror("Fail to create timer");
        }
    }
    ~LinuxTimer(){
        int res = close(fd);
        if(res == -1){
            perror("Fail to delete fd");
        }
    }
    void setTime(int period, int interval){ // simple for testing.
        spec.it_value.tv_sec = period;
        spec.it_interval.tv_sec = interval;
        if (timerfd_settime(fd, 0, &spec, nullptr) == -1) {
            perror("timerfd_settime");
        }
    }
    void consume(const function<void()>& cb){
        uint64_t exp;
        read(fd, &exp, sizeof(exp));
        cb();
    }
    LinuxTimer(const LinuxTimer&) = delete;
    LinuxTimer& operator=(const LinuxTimer&) = delete;
    private:
        int fd;
        itimerspec spec;
};
void sayHi(){
    cout << "Hello" << endl;
}
int main(){
    auto timer = make_unique<LinuxTimer>();
    timer->setTime(1, 0);
    timer->consume(sayHi);
    return 0;
}