# README
- Convert SNAP graph (e.g. ego-Twitter) file into the txt format comaptible with GraphMat.
- The output can then be converted to the binary format of GraphMat using the graph_converter included in GraphMat.
- The sample input is provided as `sample.graph' (each line describes source and destination node IDs of an edge). The node IDs do not need to be contiguous (they are not contiguous in the SNAP dataset).
- GraphMat may not compile as is (it didn't on Debian buster + gcc 8.3.0). Try [this patch](https://github.com/soramichi/GraphMat/commit/3306b33b5c58c535149689d38202ecfd7a523cc6) in that case.

# How to use
```
# Download a graph data from the SNAP dataset and unzip it
$ wget http://snap.stanford.edu/data/twitter_combined.txt.gz
$ gzip -d twitter_combined.txt.gz

# Make this program and convert the downloaded txt into a GraphMat-compatible format
$ make
$ ./convert_snap_graphmat twitter_combined.txt > twitter_combined_graphmat.txt

# Use the converter included in GraphMat to convert it into a binary format (for efficiency)
$ /path/to/GraphMat/bin/graph_converter --selfloops 1 --duplicatededges 1 --inputformat 1 --outputformat 0 --inputheader 0 --outputheader 1 --nvertices 81306 data/twitter_combined_graphmat.txt twitter_combined.bin.mtx
```

For graphs that have very large node IDs such as ego-Gplus, define `itype` as `double` and it should work (I don't know why `uint64_t` instead of `double` does not work).
