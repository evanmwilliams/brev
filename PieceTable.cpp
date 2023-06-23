#include "PieceTable.hpp"

PieceTable::PieceTable()
{
  original = "";
  pieces.push_back({true, 0, 0});
}

PieceTable::PieceTable(const std::string &text)
{
  original = text;
  pieces.push_back({true, 0, static_cast<int>(text.size())});
}

void PieceTable::insert(const std::string &text)
{
  // Save the current state for undo operation.
  undoStack.push(pieces);
  // Clear the redo stack as a new operation is being performed.
  while (!redoStack.empty())
    redoStack.pop();

  // Simple insert at end of the string, without handling more complex cases
  add += text;
  pieces.push_back({false, static_cast<int>(add.size()) - static_cast<int>(text.size()), static_cast<int>(text.size())});
}

std::string PieceTable::getText()
{
  std::string result;
  for (auto &piece : pieces)
  {
    if (piece.isOriginal)
      result += original.substr(piece.start, piece.length);
    else
      result += add.substr(piece.start, piece.length);
  }
  return result;
}

void PieceTable::undo()
{
  if (!undoStack.empty())
  {
    // Save the current state for redo operation.
    redoStack.push(pieces);
    // Revert to the previous state.
    pieces = undoStack.top();
    undoStack.pop();
  }
}

void PieceTable::redo()
{
  if (!redoStack.empty())
  {
    // Save the current state for undo operation.
    undoStack.push(pieces);
    // Revert to the next state.
    pieces = redoStack.top();
    redoStack.pop();
  }
}
