def convert_and_check():
    for X in range(2, 17):  # Minuend base
        for Y in range(2, 17):  # Subtrahend base
            for Z in range(2, 17):  # Difference base
                try:
                    minuend = int('4442', X)
                    subtrahend = int('1122210', Y)
                    difference = int('6331', Z)
                    if minuend - subtrahend == difference:
                        return X, Y, Z
                except ValueError:
                    # This will handle cases where conversion is not possible due to invalid digits for the base
                    continue

print(convert_and_check())