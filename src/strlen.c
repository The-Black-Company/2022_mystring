size_t	strlen (const char	*str)
{
  size_t i = 0;
  for (i = 0; str[i] != 0; i += 1);
  return i;
}
