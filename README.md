
# Path Finder - utility that finds closest paths for a given node

## How to build ?

```bash
cmake -B build/ .
cmake --build ./build
```

## Run tests ?

```bash
mkdir build && cd build

cmake .. && cmake --build .

ctest
```

## What's inside?

BFS algorithm, since it would be the most efficient solution
given the graph is not oriented and not weighted. Time Complexity is O(V + E).
