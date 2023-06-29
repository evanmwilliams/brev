#include "TextBuffer.hpp"
#include "PieceTable.hpp"

int main()
{
  // initialize ncurses screen
  initscr();
  raw();
  noecho();
  scrollok(stdscr, TRUE); // Enable scrolling

  int ch;
  PieceTable pt;
  while ((ch = getch()) != '`' && ch != KEY_F(1))
  {
    if (ch == KEY_BACKSPACE || ch == 127)
    {
      pt.undo();
    }
    else
    {
      pt.insert(std::string(1, ch));
    }

    // clear screen
    erase();

    // write everything in the buffer to screen
    int row = 0;
    int col = 0;
    for (char ch : pt.getText())
    {
      if (ch == '\n')
      {
        // Move to the next line
        row++;
        col = 0;
        move(row, col);
      }
      else
      {
        // Print the character
        mvprintw(row, col, "%c", ch);
        col++;
      }
    }

    refresh();
  }

  std::string buffer_contents = pt.getText();

  endwin();
  std::cout << buffer_contents << std::endl;
  return EXIT_SUCCESS;
}