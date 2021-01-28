#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <string>
#include <list>
using namespace std;

class Book {
  public:
  string title;
  double rank;
  list<string> similarBooks; 

  Book(string title = "", double rank = 1.0) {
    this->title = title;
    this->rank = rank;
  }

  // Necessary for the unordered_set and unordered_map
  bool operator == (const Book &otherBook) const {
    return this->title == otherBook.title;
  }

  // Necessary for the priority_queue
  bool operator < (const Book &otherBook) const {
    // We are inverting the sign to build a min-heap
    return this->rank > otherBook.rank;
  }

  void addSimilarBook(string title) {
    this->similarBooks.push_back(title);
  }
};

// Needed for unordered_set and unordered_map
struct BookHasher {
  hash<string> hasher;
  size_t operator () (const Book &key) const {
    return hasher(key.title);
  }
};

int n, k;
unordered_map<string, Book, BookHasher> inventory;
unordered_set<Book, BookHasher> visitedBooks;
priority_queue<Book> bookSuggestion;

void traverseGraph(Book);

int main() {
  int m;
  string title, simTitle;
  double rank;
  
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> title >> rank;
    Book book = Book(title, rank);

    cin >> m;
    for(int j = 0; j < m; j++) {
      cin >> simTitle;
      book.addSimilarBook(simTitle);
    }
    // Add the book to the inventory with the title as the key
    inventory[title] = book;
  }

  // Read the title of currentBook and traverse the graph
  // searching for the top k ranked similar books.
  cin >> title;
  traverseGraph(inventory[title]);

  while (!bookSuggestion.empty()) {
    Book book = bookSuggestion.top();
    bookSuggestion.pop();
    cout << book.title << " " << book.rank << "\n";
  }

  return 0;
}

void traverseGraph(Book book) {
  // Mark book as visited to avoid loops
  visitedBooks.insert(book);

  // Check if the current book should be added into the top-suggestions
  if (bookSuggestion.size() < k) {
    bookSuggestion.push(book); // add the book
  } else if (book.rank > bookSuggestion.top().rank) {
    bookSuggestion.pop(); // remove the book with less ranking
    bookSuggestion.push(book); // add the current book
  }

  // Move to similar books that has not been visited
  for (auto it = book.similarBooks.begin(); it != book.similarBooks.end(); it++) {
    Book otherBook = inventory[*it];
    if (visitedBooks.find(otherBook) == visitedBooks.end()) {
      traverseGraph(otherBook);
    }
  }
}