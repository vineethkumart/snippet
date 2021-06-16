/* 
Two water Jug problem
You are given a m litre jug and a n litre jug where 0 < m < n. Both the jugs are initially empty. The jugs don’t have markings to allow measuring smaller quantities. You have to use the jugs to measure d litres of water where d < n. Determine the minimum no of operations to be performed to obtain d litres of water in one of jug.
The operations you can perform are:

Empty a Jug
Fill a Jug
Pour water from one jug to the other until one of the jugs is either empty or full.
*/

/*
    This again is a state transition problem where you want to minimize the states to the destination

    initial state being (0,0) and you want to reach (0,d) or (d,0)

    Allowed transitions are:
    (i,j) -> 
        (0,j)       // empty jug 1
        (i,0)       // empty jug 2
        (m,j)       // fill  jug 1
        (i,n)       // fill  jug 2
        (i + min(m-i, j), j - min(m-i, j))  // fill jug 1 from jug 2
        (i - min(n-j), i), j + min(n-j, i)  // fill jug 2 from jug1

*/

// Recrusion using DFS
int paths(int i, int j, const int m, const int n, const int d, int mem[101][101])
{
    if (i == d || j == d) {
        return 0;
    }

    if (mem[i][j]) return mem[i][j];
    mem[i][j] = INT_MAX; // visited but don't have an answer
    int result(INT_MAX);

    result = min(result, paths(0, j, m, n, d, mem));
    result = min(result, paths(i, 0, m, n, d, mem));
    result = min(result, paths(m, j, m, n, d, mem));
    result = min(result, paths(i, n, m, n, d, mem));
    result = min(result, paths(i + min(m-i, j), j - min(m-i, j), m, n, d, mem));
    result = min(result, paths(i - min(n-j, i), j + min(n-j, i), m, n, d, mem));

    if (result == INT_MAX) return result;

    mem[i][j] = result + 1;
    return mem[i][j];
}


// BFS SOlution
void printPath(map<pair<int, int>, pair<int, int>>& path, pair<int, int>& el)
{
    if (el.first == 0 && el.second == 0) {
        cout << "(0, 0)";
        return;
    }

    printPath(path, path[el]);
    cout << "->(" << el.first <<", " << el.second << ")";
}

int main()
{
    const int m = 81, n = 100, d = 88;

    map<pair<int, int>, bool> visited;
    queue<pair<int,int>> q;

    pair<int, int> marker = make_pair(INT_MAX, INT_MAX);

    map<pair<int, int>, pair<int, int>> path;

    q.push(make_pair(0,0));
    q.push(marker);

    int states(0);

    while (!q.empty()) {
        auto el = q.front(); q.pop();

        if (el == marker) { // change of level/depth
            states++;
            q.push(marker);
            continue;
        }
        const int i = el.first;
        const int j = el.second;

        if (i == d || j == d) {
            // print path
            printPath(path, el);
            break;
        }

        // visit
        visited[el] = true;

        // push next set of states
        int ni, nj;

        // fill jug 1
        ni = m, nj = j;
        if (!visited[{ni, nj}]) {
            path[{ni,nj}] = el;
            q.push({ni,nj});
        }

        // fill jug 2
        ni = i; nj = n;
        if (!visited[{ni, nj}]) {
            path[{ni,nj}] = el;
            q.push({ni,nj});
        }


        // empty jug 1
        ni = 0; nj = j;
        if (!visited[{ni, nj}]) {
            path[{ni,nj}] = el;
            q.push({ni,nj});
        }


        // empty jug 2
        ni = i; nj = 0;
        if (!visited[{ni, nj}]) {
            path[{ni,nj}] = el;
            q.push({ni,nj});
        }

        // jug2 -> jug 1
        ni = i + min(j, m-i);
        nj = j - min(j, m-i);
        if (!visited[{ni, nj}]) {
            path[{ni,nj}] = el;
            q.push({ni,nj});
        }

        // jug 1 -> jug2
        ni = i - min(i, n-j);
        nj = j + min(i, n-j);
        if (!visited[{ni, nj}]) {
            path[{ni,nj}] = el;
            q.push({ni,nj});
        }
    }

    cout << "\nnumber of states " << states;
}
