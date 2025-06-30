#include <functional>
#include <iostream>
#include <vector>

template <typename T> 
struct TreeNode {
  T data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int value = 0) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T> 
struct Sorted {
private:
  TreeNode<T> *root;
  std::vector<T> array_elements;
  std::vector<T> sort_array_elements;
  void insertRec(TreeNode<T> *&node, T data);
  void traverseInOrder(TreeNode<T> *node);
  void destroyTree(TreeNode<T> *node);
  std::function<int(T &, T &)> comparison;

public:
  Sorted(std::vector<T> &values, std::function<int(T &, T &)> compare = std::less<T>());
  int size();
  T min();
  T max();
  void push(T data);
  std::vector<T> vect();
  ~Sorted();
  friend std::ostream &operator<<(std::ostream &os, const Sorted<T> &tree);
};

template <typename T>
Sorted<T>::Sorted(std::vector<T> &values, std::function<int(T &, T &)> compare)
    : root(nullptr), comparison(compare) {
  for (T &value : values) {
    insertRec(root, value);
  }
}

template <typename T>
void Sorted<T>::push(T data) {
  insertRec(root, data);
}

int compareIntegers(int &a, int &b) {
  if (a < b) return -1;
  if (a > b) return 1;
  return 0;
}

template <typename T> 
void Sorted<T>::insertRec(TreeNode<T> *&node, T data) {
  if (node == nullptr) {
    node = new TreeNode<T>(data);
    array_elements.push_back(data);
  } else if (comparison(data, node->data) < 0) {
    std::cout << "Inserting " << data << " to the left of " << node->data << std::endl;
    insertRec(node->left, data);
  } else {
    std::cout << "Inserting " << data << " to the right of " << node->data << std::endl;
    insertRec(node->right, data);
  }
}

template <typename T> 
int Sorted<T>::size() {
  return array_elements.size();
}

template <typename T> 
T Sorted<T>::min() {
  return sort_array_elements.front();
}

template <typename T> 
T Sorted<T>::max() {
  return sort_array_elements.back();
}

template <typename T>
std::vector<T> Sorted<T>::vect() {
  std::cout << "Starting the sort " << std::endl;
  traverseInOrder(root);
  return sort_array_elements;
}

template <typename T> 
void Sorted<T>::traverseInOrder(TreeNode<T> *node) {
  if (!node) return;
  traverseInOrder(node->left);
  sort_array_elements.push_back(node->data);
  traverseInOrder(node->right);
}

template <typename T> 
Sorted<T>::~Sorted() {
  destroyTree(root);
}

template <typename T> 
void Sorted<T>::destroyTree(TreeNode<T> *node) {
  if (node) {
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
  }
}

template <typename T>
std::ostream &operator<<(std::ostream &os, Sorted<T> &tree) {
  std::vector<T> elements = tree.vect();
  for (size_t i = 0; i < elements.size(); ++i) {
    os << "value: " << elements[i] << std::endl;
  }
  return os;
}

int main() {
  int a = 42, b = 30, c = 55, d = 33, e = 5008, f = 41;
  std::vector<int> coeffs = {a, e, c, d, f};
  Sorted<int> test(coeffs, compareIntegers);
  test.push(b);
  test.push(10);
  test.push(100);
  test.push(1000);
  test.push(10000);
  std::cout << test << std::endl;

  int min = test.min();
  int max = test.max();
  std::cout << "Min element : " << min << std::endl;
  std::cout << "Max element : " << max << std::endl;
  std::cout << "Tree size : " << test.size() << std::endl;

  return 0;
}
