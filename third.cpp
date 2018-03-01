#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

struct ride {
     int SR;
     int SC;
     int FR;
     int FC;
     int ES;
     int LF;
     int idx;
};

struct car {
    int t;
    int posR, posC;
};

int R, C, F, N, B, T;
std::vector<ride> rides;

void getInfo(const char* file_name)
{
    int a, b, x, y, s, f;
    FILE * fin;
    fin = fopen (file_name, "r");

    fscanf(fin, "%d %d %d %d %d %d", &R, &C, &F, &N, &B, &T);

    for (int i = 0; i < N; i++) {
        fscanf(fin, "%d %d %d %d %d %d", &a, &b, &x, &y, &s, &f);
        rides.push_back({a, b, x, y, s, f, i});
    }

    fclose(fin);
}

int main(int argc, char *argv[]) {
    int cost, tmp_cost, i, j, dist_cursa, dist_pos_start, timp_es, check_time;
    int cursa, masina, dist_cursa_ales, dist_pos_start_ales, timp_es_ales;
    getInfo(argv[1]);

    std::vector<car> cars(F);
    std::vector<int> result[F];

    for (i = 0; i < F; ++i) {
        cars[i].posC = 0;
        cars[i].posR = 0;
        cars[i].t = 0;
    }

    while (N --) {
        cost = -INF;
        cursa = -1;
        masina = -1;
        for (i = 0; i < F; ++i) {
            for (j = 0; j <= N; ++j) {
                dist_cursa = abs(rides[j].SR - rides[j].FR) + abs(rides[j].SC - rides[j].FC);
                dist_pos_start = abs(rides[j].SR - cars[i].posR) + abs(rides[j].SC - cars[i].posC);
                timp_es = rides[j].ES - cars[i].t;
                check_time = dist_pos_start + dist_cursa + cars[i].t;

                tmp_cost = (check_time <= rides[j].LF) ? (dist_cursa - (dist_pos_start + timp_es)) : -INF;

                if (tmp_cost > cost) {
                    cost = tmp_cost;
                    cursa = j;
                    masina = i;
                    dist_cursa_ales = dist_cursa;
                    dist_pos_start_ales = dist_pos_start;
                    timp_es_ales = timp_es;
                }
            }
        }

        if (cursa == -1) {
            cursa = 0;
            masina = 0;
        }
        // printf("%d %d %d\n", cursa, rides[cursa].idx, masina);

        result[masina].push_back(rides[cursa].idx);
        std::swap(rides[N], rides[cursa]);
        cars[masina].posR = rides[cursa].FR;
        cars[masina].posC = rides[cursa].FC;
        if (timp_es_ales < 0) {
            timp_es_ales = 0;
        }

        cars[masina].t += (dist_pos_start_ales + dist_cursa_ales + timp_es_ales);
    }

    for (i = 0; i < F; ++i) {
        printf("%d ", result[i].size());
        for (j = 0; j < result[i].size(); ++j) {
            printf("%d ", result[i][j]);
        }

        printf("\n");
    }

    return 0;
}