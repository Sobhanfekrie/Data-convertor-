#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// تابع نمونه برای معکوس کردن هر خط از فایل
void process_file(const char *input_file, const char *output_file) {
    FILE *in = fopen(input_file, "r");
    if (!in) {
        perror("Cannot open input file");
        return;
    }

    FILE *out = fopen(output_file, "w");
    if (!out) {
        perror("Cannot open output file");
        fclose(in);
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), in)) {
        int len = strlen(line);
        for (int i = len - 1; i >= 0; i--) {
            fputc(line[i], out);
        }
    }

    fclose(in);
    fclose(out);
}

// برای فراخوانی از Python (با subprocess یا ctypes)
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }
    process_file(argv[1], argv[2]);
    return 0;
}
