#include <stdio.h>

void backtrack(int* subjects, int target_sum, int* path, int current_sum, int start, int path_size, int n) {
    if (current_sum == target_sum) {
        for (int i = 0; i < path_size; ++i) {
            printf("%d ", path[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i < n; ++i) {
        if (current_sum + subjects[i] <= target_sum) {
            path[path_size] = subjects[i];
            backtrack(subjects, target_sum, path, current_sum + subjects[i], i + 1, path_size + 1, n);
        }
    }
}

void sum_subjects_backtracking(int* subjects, int target_sum, int n) {
    int path[n];  // Temporary array to store the current combination
    backtrack(subjects, target_sum, path, 0, 0, 0, n);
}

int main() {
    int subjects[] = {2, 3, 7, 8, 10};
    int target_sum = 18;
    int n = sizeof(subjects) / sizeof(subjects[0]);
    sum_subjects_backtracking(subjects, target_sum, n);
    return 0;
}