
https://www.geeksforgeeks.org/find-the-longest-path-in-a-matrix-with-given-constraints/
int solve(vector<vector<int>>& a, int i, int j, int mem[3][3])
{
int m = a.size();
int n = a[0].size();

auto isSafe = [&](int i, int j) {
	if (i < 0 || i >= m) return false;
	if (j < 0 || j >= n) return false;
	return true; 
};

int& res = mem[i][j];
if (res) return res;


int l = 0;
int r = 0;
int t = 0;
int b = 0;
if (isSafe(i, j-1) && a[i][j-1]+1 == a[i][j]) {
	l = solve(a, i, j-1,mem);
}

if (isSafe(i, j+1) && a[i][j+1]+1 == a[i][j]) {
	r = solve(a, i, j+1,mem);
}

if (isSafe(i-1, j) && a[i-1][j]+1 == a[i][j]) {
	t = solve(a, i-1, j,mem);
}
if (isSafe(i+1, j) && a[i+1][j]+1 == a[i][j]) {
	b = solve(a, i+1, j,mem);
}

return (res = 1 + max(max(max(l, r), t), b));
} 

int main()
{
	int res(0);
	vector<vector<int>> a{  {6, 2, 9},
                            {9, 3, 8},
                            {5, 6, 7}};
                            
    int mem[3][3] = {0};
	
	for (int i = 0; i <3; i++)
		for (int j =0; j < 3; j++)
			res = max(res, solve(a,i,j,mem));
	
	cout << res;
}