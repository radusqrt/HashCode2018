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

struct result {
    int vehicule_index;
    std::vector<int> ride_indexes;
};

int R, C, F, N, B, T;
std::vector<ride> rides;
std::vector<result> results;

void getInfo (const char* file_name) {

    int a, b, x, y, s, f;
    FILE * fin;
    fin = fopen (file_name, "r");

    fscanf(fin, "%d %d %d %d %d %d", &R, &C, &F, &N, &B, &T);
    
    for (int i = 0; i < N; ++i) {
        fscanf(fin, "%d %d %d %d %d %d", &a, &b, &x, &y, &s, &f);
        rides.push_back({a, b, x, y, s, f});
    }
        fclose(fin);
}
void writeInfo(const char* file_name) {
    FILE * fout;
    fout = fopen (file_name, "w");

    for (int i = 0; i < F; ++i) {
        fprintf (fout, "%d", results[i].vehicule_index);
        for (unsigned j = 0; j < results[i].ride_indexes.size(); ++j) {
            fprintf (fout, " %d", results[i].ride_indexes[j]);
        }
        fprintf(fout, "\n");
    }
    fclose(fout);
}
int main(int argc, char *argv[]) {

   std::string fisier = argv[1]; 
   getInfo((fisier + ".in").c_str());
   writeInfo((fisier + ".out").c_str());
}