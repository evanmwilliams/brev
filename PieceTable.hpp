#include <vector>
#include <string>
#include <stack>

struct Piece
{
  bool isOriginal;
  int start;
  int length;
};

class PieceTable
{
private:
  std::string original;
  std::string add;
  std::vector<Piece> pieces;

  // Stacks to maintain undo and redo history.
  std::stack<std::vector<Piece>> undoStack;
  std::stack<std::vector<Piece>> redoStack;

public:
  PieceTable();
  PieceTable(const std::string &text);

  // TODO: Add a method to insert text at a specific index.
  void insert(const std::string &text);

  std::string getText();

  void undo();

  void redo();
};