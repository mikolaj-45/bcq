
int main(int argc, char **argv)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (i != 1)
            write(1, "\n", 1);
        
        //copy board
        
        find_main();
        i++;
    }
}