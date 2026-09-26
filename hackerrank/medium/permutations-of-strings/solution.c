
int main()
{
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);

    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);

    // Allocate memory for number of books on each shelf
    total_number_of_books = malloc(
        total_number_of_shelves * sizeof(int)
    );

    // Allocate memory for pages on each shelf
    total_number_of_pages = malloc(
        total_number_of_shelves * sizeof(int*)
    );

    // Initialize all shelves
    for (int i = 0; i < total_number_of_shelves; i++)
    {
        total_number_of_books[i] = 0;
        total_number_of_pages[i] = NULL;
    }

    while (total_number_of_queries--)
    {
        int type_of_query;
        scanf("%d", &type_of_query);

        if (type_of_query == 1)
        {
            int x, y;
            scanf("%d %d", &x, &y);

            // Current number of books on shelf x
            int current_books = total_number_of_books[x];

            // Increase book count
            total_number_of_books[x]++;

            // Increase memory for one more book
            total_number_of_pages[x] = realloc(
                total_number_of_pages[x],
                total_number_of_books[x] * sizeof(int)
            );

            // Store pages of the new book
            total_number_of_pages[x][current_books] = y;
