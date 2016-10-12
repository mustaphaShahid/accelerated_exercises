#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdexcept>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

Grammar read_grammar(std::istream&);
std::vector<std::string> split(const std::string&);
bool space(char);
bool not_space(char);
std::vector<std::string> gen_sentence(const Grammar&);
bool bracketed(const std::string&);
void gen_aux(const Grammar&, const std::string&, std::vector<std::string>&);
int nrand(int);
