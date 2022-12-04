import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py FILENAME FILENAME")
    # TODO: Read database file into a variable
    database = []
    with open(sys.argv[1], "r") as file1:
        reader = csv.reader(file1)
        
        for row in reader:
            database.append(row)

    # TODO: Read DNA sequence file into a variable
    sequence = []
    with open(sys.argv[2], "r") as file2:
        reader = csv.reader(file2)
        for string in reader:
            for character in string[0]:
                sequence.append(character)

    # TODO: Find longest match of each STR in DNA sequence
    match = {}
    STRs=["AGATC", "TTTTTTCT", "AATG", "TCTAG", "GATA", "TATC", "GAAA", "TCTG"]
    for str in STRs:
        match[str] = longest_match(sequence, str)

    # TODO: Check database for matching profiles
    check = 0
    for individual in database:
        for str in STRs:
            if int(individual[str]) != match[str]:
                check = 0
                break
            else:
                check = 1

        if check == 0:
            continue
        else:
             print(individual["name"])
             break

    if check == 0:
        print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
