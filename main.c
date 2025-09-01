#include "func.h"

int main (int argc, char *argv[])
{
    int max_size, ret_val;
    char choice;

    if (argc < 2)
    {
        printf ("Usage: %s <maxsize>\n", argv[0]);
        exit (0);
    }

    max_size = atoi (argv[1]);
    int *int_queue;
    if ((int_queue = (int *) malloc (max_size * sizeof (int))) == NULL)
    {
        printf ("unable to allocate memory for the array\n");
        exit (0);
    }

    int front = 0, rear = 0, data;

    do
    {
        printf ("Key in your option: N - Enqueue D - Deque P - peek F - Full ? E - Empty Q - Quit:");
        scanf (" %c", &choice);
        choice = toupper (choice);
        if (choice == 'Q')
            break;
        switch (choice)
        {
            case 'N':	// Enqueue op
                printf ("Key in the data to be added:");
                scanf ("%d", &data);
                Enqueue (int_queue, &rear, max_size, data);
                break;

            case 'D':	// Deque op
                ret_val = Dequeue (int_queue, &front, &rear, max_size, &data);
                if (ret_val != -1)
                    printf ("Data removed is %d\n", data);
                break;

            case 'P':	// Peek op
                ret_val = Peek (int_queue, front, rear, &data);
                if (ret_val != -1)
                    printf ("Data at the top is %d\n", data);
                break;

            case 'F':	// Is the queue full?
                ret_val = isFull (rear, max_size);
                if (ret_val)
                    printf ("Queue is full\n");
                else
                    printf ("Queue is not full\n");
                break;

            case 'E':	// Is the queue empty
                ret_val = isEmpty (front, rear, max_size);
                if (ret_val)
                    printf ("Queue is empty\n");
                else
                    printf ("Queue is not empty\n");
                break;

            default:
                printf ("Invalid choice\n");
        }
    } while (1);
    free (int_queue);
    return 0;
}