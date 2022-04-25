with open("out.txt", 'r') as f:
    lines = f.readlines()
    total = len(lines)
    elements = list(map(lambda item: list(map(int, item.split())), lines))

    bit_count = lambda item: bin(item).count("1")
    odd_bit = lambda items: sum(map(bit_count, items[:4])) % 2 == items[-1]

    result = list(map(odd_bit, elements))
    print("Correct hash records: " + str(sum(result) / total * 100.) + "%")
    print("Errors: " + str((1. - sum(result) / total) * 100.) + "%")