#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <errno.h>

struct termios orig_termios;

void enableRawMode();

void disableRawMode();

void die(const char *s);