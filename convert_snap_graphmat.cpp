#include <iostream>
#include <sstream>
#include <cstdio>
#include <set>
#include <map>

// For an input that has very large node IDs, use double instead of unsigned long.
// (No idea why uint64_t doesn't work. Maybe it's not compatible with sstream::operator>>().)
typedef unsigned long itype;

int main(int argc, char* argv[]) {
  char buff[1024];
  itype s, d;
  std::set<itype> nodes = std::set<itype>();
  std::map<itype, unsigned long> new_ids = std::map<itype, unsigned long>();
  FILE* f;

  f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("");
  }

  // 1st phase: insert node IDs to a set (ordered, de-duplicated)
  while(fgets(buff, sizeof(buff), f)) {
    std::stringstream ss(buff);
    ss >> s >> d;
    nodes.insert(s);
    nodes.insert(d);
  }

  // assign new ids to the nodes
  unsigned long new_id = 1; // should be from 1 due to GraphMat specification
  for(auto it = nodes.begin(); it != nodes.end(); it++) {
    new_ids[*it] = new_id;
    new_id++;
  }
  
  // 2nd phase: convert original node IDs to the new IDs
  rewind(f);
  while(fgets(buff, sizeof(buff), f)) {
    std::stringstream ss(buff);
    ss >> s >> d;    
    printf("%ld %ld 1\n", new_ids[s], new_ids[d]);
  }

  return 0;
}
