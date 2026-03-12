#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define SSD1306_IOC_MAGIC 'k'
#define SSD1306_IOC_CLEAR_SCREEN _IO(SSD1306_IOC_MAGIC, 0)

int main() {
    int fd = open("/dev/ssd1306_oled", O_RDWR);
    if (fd < 0) { perror("open"); return 1; }

    // Send the clear screen command
    ioctl(fd, SSD1306_IOC_CLEAR_SCREEN);

    close(fd);
    return 0;
}
