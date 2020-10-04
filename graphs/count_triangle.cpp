#include <iostream>

using namespace std;

long long answer = 0;
int N, M;
bool map[50][50] = {
    0,
};

void dfs(int start, int current, int before, int depth) {
    if (depth == 2) {
        if (current == start) {
            answer++;
        }
        return;
    }

    int iteration_start, iteration_end;
    if (depth != 1) {
        iteration_start = current + 1;
        iteration_end = N;
    } else {
        iteration_start = 0;
        iteration_end = current;
    }

    for (int i = iteration_start; i < iteration_end; i++) {
        if (map[current][i] && i != before) {
            dfs(start, i, current, depth + 1);
        }
    }
}

void solution() {
    answer = 0;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[i][j] = 0;
        }
    }

    int x, y;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        x--;
        y--;
        map[x][y] = 1;
        map[y][x] = 1;
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (map[i][j]) {
                dfs(i, j, i, 0);
            }
        }
    }

    cout << "number of triangle : " << answer;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solution();

    return 0;
}