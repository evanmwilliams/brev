#include "TextBuffer.hpp"

int main()
{
  initscr();

  int ch;
  TextBuffer tb;
  while ((ch = getch()) != '\n' && ch != KEY_F(1))
  {
    if (ch == KEY_BACKSPACE || ch == 127)
    {
      tb.pop_char();
    }
    else
    {
      tb.append_char(ch);
    }
  }

  std::string buffer_contents = tb.get_contents();
  endwin();
  std::cout << buffer_contents << std::endl;
  return EXIT_SUCCESS;
}