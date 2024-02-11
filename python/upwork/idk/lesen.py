import re

def extract_values_from_line(line):
    # Use regular expressions to extract the values of X, Y, and Z
    # pattern = r"KN\s+NAME='.+?'\s+X=(-?\d+\.\d+|\d+)\s+Y=(-?\d+\.\d+|\d+)\s+Z=(-?\d+\.\d+|\d+)\s+REF='.+?'"
    pattern = r"KN\s+NAME='.+?'\s+X=(-?\d+\.\d+|\d+)\s+Y=(-?\d+\.\d+|\d+)\s+Z=(-?\d+\.\d+|\d+)\s+REF='.+?'\s*"
    matches = re.findall(pattern, line)
    
    for match in matches:
        x, y, z = match
        return x, y, z

    # if match:
    #     x_value, y_value, z_value = map(float, match.groups())
    #     return x_value, y_value, z_value

    return None

def save_values_to_file(x, y, z, output_filename):
    with open(output_filename, 'a') as output_file:
        output_file.write(f"X: {x}\nY: {y}\nZ: {z}\n")

# File names
input_filename = "input.txt"
output_filename = "output.txt"
i = 1
try:
    # Open the input file and read the line
    with open(input_filename, 'r') as input_file:
        for input_line in input_file:
            input_line = input_file.readline().strip()

            # Extract the values of X, Y, and Z
            values = extract_values_from_line(input_line)
            
            print(i, " ", values)
            i += 1

            if values is not None:
                x, y, z = values

                # Save the values to the output file
                save_values_to_file(x, y, z, output_filename)
                print(f"The values have been successfully saved to '{output_filename}'.")
            else:
                print("The values of X, Y, and Z could not be extracted.")
except FileNotFoundError:
    print(f"The input file '{input_filename}' was not found.")
except Exception as ex:
    print(f"An error occurred: {ex}")