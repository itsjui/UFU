int main()
{
    int h1, h2, m1, m2, h, m;
    h1 = h2 = m1 = m2 = h = m = 0;

    scanf("%d %d %d %d", &h1, &m1, &h2, &m2);

    h = h2 - h1;
    m = m2 - m1;

    if (h == 0 && m == 0)
    {
        h = 24;
    }
    else
    {
        if (m < 0)
        {
            m += 60;
            h--;
        }
        if (h < 0)
        {
            h += 24;
        }
    }
    printf("O JOGO DUROU %i HORA(S) E %i MINUTO(S)\n", h, m);
    return 0;
}