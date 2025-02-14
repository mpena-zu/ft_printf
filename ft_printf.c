int ft_printf(char const *format, ...)
{
    int i;

    i = 0;
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
        }
        write(1, &format[i], 1);
        i++;
    }
}
int main(void)
{
    ft_printf("hola mundo");
    return (0);
}