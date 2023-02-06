#include <Tree.h>

using namespace NodeTask;

int main() {
	Tree tree;

	int array[] = { 50, 25, 75, 12, 37, 43, 30 };

	for (size_t i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
		tree.add_node(array[i]);
		print_tree(tree.root);
		std::cout << std::endl;
	}
	std::cout << std::endl << tree.get_size() << std::endl;

	return 0;
}