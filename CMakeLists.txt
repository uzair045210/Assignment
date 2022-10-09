cmake_minimum_required(VERSION 3.20)
project(Assignment)

set(CMAKE_CXX_STANDARD 23)

add_executable(Assignment main.cpp linear/linkedList/List.h linear/linkedList/List.cpp linear/linkedList/Node.h linear/stack/StackList.cpp linear/stack/StackList.h linear/queue/QueueList.cpp linear/queue/QueueList.h binary/tree/BNode.h binary/tree/BST.cpp binary/tree/BST.h binary/tree/AVL.cpp binary/tree/AVL.h binary/tree/AVLNode.h binary/heap/Heap.cpp binary/heap/Heap.h   binary/graph/directed/Graph.cpp binary/graph/directed/Graph.h algorithms/search/Search.cpp algorithms/search/Search.h)
