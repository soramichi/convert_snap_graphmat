# README
- Convert SNAP graph (e.g. ego-Twitter) file into the txt format comaptible with GraphMat.
- The output can then be converted to the binary format of GraphMat using the graph_converter included in GraphMat.
- The sample input is provided as `sample.graph'. The node IDs do not need to be contiguous (they are not contiguous in the SNAP dataset).

# How to use
`./convert_snap_graphmat.cpp sample.graph > sample.out`