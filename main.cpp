#include "TextBuffer.hpp"
#include "PieceTable.hpp"

int main()
{
  initscr();
  raw();
  noecho();

  int ch;
  // TextBuffer tb;
  // while ((ch = getch()) != '\n' && ch != KEY_F(1))
  // {
  //   if (ch == KEY_BACKSPACE || ch == 127)
  //   {
  //     tb.pop_char();
  //   }
  //   else
  //   {
  //     tb.append_char(ch);
  //   }
  // }

  // std::string buffer_contents = tb.get_contents();

  PieceTable pt;
  while ((ch = getch()) != '\n' && ch != KEY_F(1))
  {
    if (ch == KEY_BACKSPACE || ch == 127)
    {
      pt.undo();
    }
    else
    {
      pt.insert(std::string(1, ch));
    }
  }

  std::string buffer_contents = pt.getText();

  endwin();
  std::cout << buffer_contents << std::endl;
  return EXIT_SUCCESS;
}