
int fun(int x)
{
    int y = 0;
    switch(x)
    {
        case 0:
        case 4:
            y += 7;
        case 3:
            y += 100;
            break;
        case 6:
            y += 20;
        case 5: 
            y += 1000;
        default:
            y += 6;
    }
    return y;
}