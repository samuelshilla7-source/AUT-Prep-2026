def get_scores():
    scores = []

    while True:
        entry=input("Enter a score (or done): ")

        if entry == "done":
            break

        numbers = int(entry)
        scores.append(numbers)
    return scores

def mathematical_operations(scores):
    total = 0
    for score in scores:
        total += score
    average = total / len(scores) if scores else 0

    return total, average

scores = get_scores()
total, average = mathematical_operations(scores)

print("Total score:", total)
print("Average score:", average)