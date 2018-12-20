/*
 * TDQC5
 * Bruce Cain
 *
 * 4.1.07
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(void)
{
    /*
     * a. Open existing file
     * e. Close and open file
     */
    FILE *file = fopen("text.txt", "r+");

    if (file == NULL)
    {
        puts("Could'nt open file");
        return -1;
    }

    /*
     * f. Print file info to console
     * http://codewiki.wikidot.com/c:system-calls:stat
     */
    struct stat file_stats;
    if(stat("text.txt", &file_stats) < 0)
    {
        return 1;
    }

    puts("Information for text.txt");
    puts("---------------------------");
    printf("File Size: \t\t%ld bytes\n", file_stats.st_size);
    printf("Number of Links: \t%lu\n", file_stats.st_nlink);
    printf("File inode: \t\t%lu\n", file_stats.st_ino);

    printf("File Permissions: \t");
    printf((S_ISDIR(file_stats.st_mode)) ? "d" : "-");
    printf((file_stats.st_mode & S_IRUSR) ? "r" : "-");
    printf((file_stats.st_mode & S_IWUSR) ? "w" : "-");
    printf((file_stats.st_mode & S_IXUSR) ? "x" : "-");
    printf((file_stats.st_mode & S_IRGRP) ? "r" : "-");
    printf((file_stats.st_mode & S_IWGRP) ? "w" : "-");
    printf((file_stats.st_mode & S_IXGRP) ? "x" : "-");
    printf((file_stats.st_mode & S_IROTH) ? "r" : "-");
    printf((file_stats.st_mode & S_IWOTH) ? "w" : "-");
    printf((file_stats.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n\n");

    char *line = NULL;
    size_t size = 0;

    /*
     * b. Read data from a file
     *
     * Read the file line by line and print out the line.
     */
    puts("Reading from file...");
    while (getline(&line, &size, file) != -1)
    {
        printf("%s", line);
    }
    free(line);

    /*
     * c. Write to a file
     */
    fprintf(file, "\nMy own data\n");

    /*
     * d. Modify data
     * l. insert data
     *
     * Move to the beginning of the file and modify data.
     */
    fseek(file, 0, SEEK_SET);
    fprintf(file, "Modify data");

    /*
     * h. Append data to file
     *
     * Move to the end of the file and write new data.
     */
    fseek(file, 0, SEEK_END);
    fprintf(file, "Append data\n");


    /*
     * j. Determine size of file
     * k. Determine location in a file
     *
     * Move position to the end of the file, using ftell which will tell you
     * how bytes from the begining you are. Since we are at the end we know
     * that the returned offset will be the size of the file.
     * Also the location.
     */
    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    printf("\nFile size: \t%ld bytes\n", file_size);


    /*
     * e. Close and open file.
     */
    fclose(file);
    
    /*
     * i. Delete file
     * https://www.programmingsimplified.com/c-program-delete-file
     */
    if (remove("new_file") != 0)
    {
        fprintf(stderr, "Failed to remove file.\n");
    }
    /*
     * g. Create new file
     *
     * Using modes a or w will create a new file if the file name given cannont
     * be opened.
     */
    file = fopen("new_file", "a+");

    fclose(file);
    return 0;
}

