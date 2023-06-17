#include "brev.hpp"

void TextBuffer::append_char(char c)
{
  buffer.push_back(c);
}

bool TextBuffer::pop_char()
{
  if (buffer.size() > 0) {
    buffer.pop_back();
    return true;
  }
  return false;
}

std::string TextBuffer::get_contents()
{
  return std::string(buffer.begin(), buffer.end());
}

int main()
{
  initscr();

  int ch;
  TextBuffer tb;
  while ((ch = getch()) != '\n' && ch != KEY_F(1)) {
    if (ch == KEY_BACKSPACE || ch == 127) {
      tb.pop_char();
    } else {
      tb.append_char(ch);
    }
  }

  std::string buffer_contents = tb.get_contents();
  endwin();
  std::cout << buffer_contents << std::endl;
  return EXIT_SUCCESS;
}