#include "test_util.h"
#include "util.h"

int main(int argc, char** argv)
{
    CHECK(argc == 3, "USAGE: %s OUT_PATH TEST_CASE", argv[0]);
    test_helper_functions();

    // Confirm input file exists.
    const char *input_filename = argv[2];
    FILE *input_file;
    CHECK(input_file = fopen(input_filename, "r"), "%s test file does not exist!\n", input_filename);

    // Read in input file line by line.
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, input_file)) != -1)
    {
        // Parse the input line.
        int size;
        int *num = get_nums(line, &size);
        CHECK(size, "Input line is empty.");

        // Delete old solution file.
        remove("solution.txt");

        // Run the solution.
        factor(num[0]);

        // Open the solution output file.
        FILE *file;
        CHECK(file = fopen("solution.txt", "r"), "file does not exist!");

        // Parse the file.
        char * sol_line = NULL;
        size_t sol_len = 0;
        CHECK(getline(&sol_line, &sol_len, file) != -1, "Error reading file!");

        // Check results.
        int sol_size;
        int *sol = get_nums(sol_line, &sol_size);
        CHECK(size - 1 == sol_size, "Incorrect number of factorials for %d.", num[0]);
        printf("%-10d   ->   [", num[0]);
        for(int i=0; i < sol_size; i++)
        {
            if (i != (sol_size-1))
            {
                printf("%d, ", sol[i]);
            }
            else
            {
                printf("%d]\n", sol[0]);
            }
            CHECK(num[i+1] == sol[i], "Incorrect factorial for %d.", num[0]);
        }

        // Clean up.
        free(num);
        free(sol_line);
        free(sol);
        fclose(file);
    }

    // Clean up.
    fclose(input_file);
    free(line);

    return 0;
}
