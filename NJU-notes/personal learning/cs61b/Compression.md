# Prefix-Free Codes
A prefix-free code is one in which no codeword is a prefix of any other.
# Huffman Coding
Calculate relative frequencies.
- Assign each symbol to a node with weight = relative frequency.
- Take the two smallest nodes and merge them into a super node with weight equal to sum of weight.
- Repeat until everything is part of a tree.
代价是仅能表示a subset of all possible characters. It's just tradeoff
压缩时可以使用map，decoding使用trie会是更好的选择。