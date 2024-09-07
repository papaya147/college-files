# logical var
logical_var = TRUE
cat(logical_var)
cat(class(logical_var))

# numeric var
numeric_var = 5245
cat(numeric_var)
cat(class(numeric_var))

# integer var (the L denotes the integer type from the generic numeric)
int_var = 412L
cat(int_var)
cat(class(int_var))

# complex var
complex_var = 3 + 2i
cat(complex_var)
cat(class(complex_var))

# character var
char_var = "papaya"
cat(char_var)
cat(class(char_var))

# raw bytes type
raw_var = charToRaw("papaya")
cat(raw_var)
cat(class(raw_var))