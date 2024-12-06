#include <stdio.h>


#define CONCAT_AUX(x,y) x##y
#define CONCAT(x,y) CONCAT_AUX(x,y)
#define QUOTE(str) #str
#define EXPAND_AND_QUOTE(str) QUOTE(str)

#define LED_PIN             20
#define LED_DIR             "out"

#define PIN_HIGH            "1"
#define PIN_LOW             "0"

#define PATH_EXPORT        "/sys/class/gpio/export"
#define PATH_DIRECTION     EXPAND_AND_QUOTE(CONCAT(/sys/class/gpio/gpio,LED_PIN/direction))
#define PATH_VALUE         EXPAND_AND_QUOTE(CONCAT(/sys/class/gpio/gpio,LED_PIN/value))


void direction_init()
{
    int fd = open(PATH_DIRECTION, O_WRONLY);
    if(fd<0)
    {
        fprintf(stderr, "failed to open direction file\n");
        return;
    }

    write(fd, LED_DIR, strlen(LED_DIR));
    
    close(fd);
}

void export_init()
{
    int fd = open(PATH_EXPORT, O_WRONLY);
    if(fd<0)
    {
        fprintf(stderr, "failed to open export file\n");
        return;
    }
    write(fd, LED_PIN, strlen(LED_PIN));
    close(fd);
}

int main(void)
{
    export_init();
    sleep(1);
    direction_init();

    int fd = open(PATH_VALUE, O_WRONLY);
    if(fd<0)
    {
        fprintf(stderr, "failed to open export file\n");
        exit(1);
    }

    for(int i = 0; i < 5; i++)
    {
        write(fd, PIN_HIGH, strlen(PIN_HIGH));
        sleep(2);
        write(fd, PIN_HIGH, strlen(PIN_LOW));
        sleep(2);
    }

    close(fd);
}