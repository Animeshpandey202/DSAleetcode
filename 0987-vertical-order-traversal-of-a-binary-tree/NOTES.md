vector < vector < int >> findVertical(node * root) {
map < int, map < int, multiset < int >>> nodes;
queue < pair < node * , pair < int, int >>> todo;
todo.push({
root,
{
0,
0
}
}); //initial vertical and level
while (!todo.empty()) {
auto p = todo.front();
todo.pop();
node * temp = p.first;
​
//x -> vertical , y->level
int x = p.second.first, y = p.second.second;
nodes[x][y].insert(temp -> data); //inserting to multiset
​
if (temp -> left) {
todo.push({
temp -> left,
{
x - 1,
y + 1
}
});
}
if (temp -> right) {
todo.push({
temp -> right,
{
x + 1,
y + 1
}