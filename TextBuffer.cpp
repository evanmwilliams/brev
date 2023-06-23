#include "TextBuffer.hpp"

void TextBuffer::append_char(char c)
{
  buffer.push_back(c);
}

bool TextBuffer::pop_char()
{
  if (buffer.size() > 0)
  {
    buffer.pop_back();
    return true;
  }
  return false;
}

std::string TextBuffer::get_contents()
{
  return std::string(buffer.begin(), buffer.end());
}