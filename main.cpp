#include "TextBuffer.hpp"
#include "PieceTable.hpp"

int main(int argc, char *argv[])
{
  initscr();
  raw();
  noecho();

  int ch;
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