#include <iostream>
#include <ncurses.h>
#include <vector>
#include <string>

class TextBuffer
{
private:
  std::vector<char> buffer;
  int cursor;

public:
  std::string get_contents();
  void append_char(char c);
  bool pop_char();
  bool undo_last_action();
};