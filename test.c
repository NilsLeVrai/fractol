double atod(const char *str) {
    double result = 0.0;
    double fraction = 0.0;
    double divisor = 1.0;
    int sign = 1;
    int fraction_flag = 0;

    // Skip leading whitespaces
    while (isspace(*str)) {
        str++;
    }

    // Check for sign
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    // Process the integer and fractional parts
    while (*str) {
        if (isdigit(*str)) {
            if (fraction_flag) {
                // Processing fractional part
                fraction = fraction * 10 + (*str - '0');
                divisor *= 10;
            } else {
                // Processing integer part
                result = result * 10 + (*str - '0');
            }
        } else if (*str == '.') {
            // Start processing fractional part
            if (fraction_flag) {
                // More than one decimal point found
                break;
            }
            fraction_flag = 1;
        } else {
            // Invalid character found
            break;
        }
        str++;
    }

    result += fraction / divisor;
    return sign * result;
}

int main() {
    const char *str1 = "123.456";
    const char *str2 = "-789.012";
    const char *str3 = "   +34.56";
    const char *str4 = "56.78xyz";

    printf("String: '%s', Double: %f\n", str1, atod(str1));
    printf("String: '%s', Double: %f\n", str2, atod(str2));
    printf("String: '%s', Double: %f\n", str3, atod(str3));
    printf("String: '%s', Double: %f\n", str4, atod(str4));

    return 0;
}