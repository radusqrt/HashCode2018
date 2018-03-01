#include <bits/stdc++.h>

struct ride {
     int SR;
     int SC;
     int FR;
     int FC;
     int ES;
     int LF;
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
        rides.push_back({a, b, x, y, s, f});
    }

    fclose(fin);
}

int main(int argc, char *argv[]) {

    getInfo(argv[1]);
    
    while (N --) {
        
    }

    return 0;
}