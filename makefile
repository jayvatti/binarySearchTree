
valgrind:
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./Tree

main.o: main.cpp TreeNode.h
	g++ -c main.cpp

TreeNode.o: TreeNode.h TreeNode.cpp
	g++ -c TreeNode.cpp

Tree: TreeNode.o main.o
	g++ TreeNode.o main.o -o Tree

clean:
	rm -f *.o
	rm Tree
run: Tree
	./Tree
